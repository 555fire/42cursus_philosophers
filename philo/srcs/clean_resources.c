#include "../includes/philo.h"

void	clean_resources(t_data *d)
{
	size_t	i;
	size_t	loop_count;

	__DEBUG__(d);

	loop_count = 0;
//	while (1)
//	while (loop_count <= 10)
//	while (loop_count <= 10000000)
	while (loop_count <= 100000000)
	{
//		__DEBUG__(d);
		if (errno || d->errstat || d->simustat)
		{
			__DEBUG__(d);
			break ;
		}
		loop_count++;
		if (loop_count % 1000000 == 0)
		{
//			__DEBUG__(d);
			__DEBUG_PRINT_LOOP_COUNT__(loop_count);
		}
	}

	__DEBUG__(d);

	i = 0;
	while (!errno && d->errstat > THREAD_CREATE_ERROR && i < d->i.n_philo)
	{
		__DEBUG__(d);
		if (pthread_join(d->thread_arr[i], NULL))
		{
			__DEBUG__(d);
			d->errstat = THREAD_JOIN_ERROR;
			break ;
		}
		i++;
	}

	__DEBUG__(d);

	i = 0;
//	while (!errno && i <= d->i.n_philo)
	while (!errno && i < d->i.n_philo)
	{
		__DEBUG__(d);
		if (pthread_mutex_destroy(&d->mutexfork_arr[i]))
		{
			__DEBUG__(d);
			d->errstat = MUTEX_DESTROY_ERROR;
			break ;
		}
		i++;
	}

	__DEBUG__(d);

	if (errno || d->errstat)
		print_errstat(d, d->errstat);

	__DEBUG__(d);

	if (errno != EINVAL && !d->errstat)
	{
		__DEBUG__(d);
		free_safely(d->p_arr);
		free_safely(d->thread_arr);
		free_safely(d->mutexfork_arr);
		free_safely(d);
		__DEBUG__(d);
	}

	__DEBUG__(d);

	return ;
}
