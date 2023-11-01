#include "../includes/philo.h"

void	create_threads(t_data *d)
{
	size_t	i;
	void	*func_ptr;

//	__DEBUG__(d);

	if (errno || d->errstat)
	{
		__DEBUG__(d);
		return ;
	}

	i = 0;
	while (i <= d->i.n_philo)
	{
//		__DEBUG__(d);

		d->p_arr[i].d = d;
		d->p_arr[i].philo_i = i;

		if (i == 0)
		{
			d->p_arr[i].threadrole = A_MONITOR;
			func_ptr = &monitor_routine;
		}
		else
		{
			d->p_arr[i].threadrole = ONE_OF_PHILOS;
			func_ptr = &philo_routine;
		}

		if (pthread_create(&d->thread_arr[i], NULL, func_ptr, &d->p_arr[i]))
		{
			d->errstat = THREAD_CREATE_ERROR;
//			__DEBUG_WITH_OWN_P__(d, &d->p_arr[i]);
			return ;
		}

//		__DEBUG_WITH_INPUT__(d);

		i++;
	}

	__DEBUG__(d);

	return ;
}
