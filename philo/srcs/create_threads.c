#include "../includes/philo.h"

void	create_threads(t_data *d)
{
	size_t	i;
//	void	*f;

	__DEBUG__(d);

	if (errno || d->errstat)
		return ;

	i = 0;
	while (i <= d->i.n_philo)
	{
		__DEBUG__(d);
		d->p_arr[i].d = d;
		d->p_arr[i].philo_i = i;
		__DEBUG_WITH_INPUT__(d);
		if (i == 0)
		{
			d->p_arr[i].threadrole = A_MONITOR;
			__DEBUG_WITH_OWN_P__(d, &d->p_arr[i]);
			if (pthread_create(&d->thread_arr[i], NULL, monitor_routine, &d->p_arr[i]))
			{
				d->errstat = THREAD_CREATE_ERROR;
				return ;
			}
			i++;
			continue ;
		}
		d->p_arr[i].threadrole = ONE_OF_PHILOS;
		__DEBUG_WITH_OWN_P__(d, &d->p_arr[i]);
		if (pthread_create(&d->thread_arr[i], NULL, philo_routine, &d->p_arr[i]))
		{
			d->errstat = THREAD_CREATE_ERROR;
			return ;
		}
		i++;
	}

	__DEBUG__(d);

	return ;
}

//	i = 0;
//	while (i <= d->i.n_philo)
//	{
//		__DEBUG__(d);
//		d->p_arr[i].d = d;
//		d->p_arr[i].philo_i = i;
//		__DEBUG_WITH_INPUT__(d);
//		if (i == 0)
//		{
//			d->p_arr[i].threadrole = A_MONITOR;
//			__DEBUG_WITH_OWN_P__(d, &d->p_arr[i]);
//			if (pthread_create(&d->thread_arr[i], NULL, philo_routine, &d->p_arr[i]))
//			{
//				d->errstat = THREAD_CREATE_ERROR;
//				return ;
//			}
//			i++;
//		}
//		d->p_arr[i].threadrole = ONE_OF_PHILOS;
//		__DEBUG_WITH_OWN_P__(d, &d->p_arr[i]);
//		if (pthread_create(&d->thread_arr[i], NULL, philo_routine, &d->p_arr[i]))
//		{
//			d->errstat = THREAD_CREATE_ERROR;
//			return ;
//		}
//		i++;
//	}

//	i = 0;
//	while (i < d->i.n_philo)
//	{
//		__DEBUG__(d);
//		d->p_arr[i].d = d;
//		d->p_arr[i].philo_i = i + 1;
//		if (pthread_create(&d->thread_arr[i], NULL, philo_routine, &d->p_arr[i]))
//		{
//			d->errstat = THREAD_CREATE_ERROR;
//			return ;
//		}
//		i++;
//	}
//
//	d->p_arr[i].d = d;
//	d->p_arr[i].threadrole = A_MONITOR;
//	if (pthread_create(&d->thread_arr[i], NULL, monitor_routine, &d->p_arr[i]))
//		d->errstat = THREAD_CREATE_ERROR;
