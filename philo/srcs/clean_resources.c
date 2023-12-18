/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:54:37 by mamiyaza          #+#    #+#             */
/*   Updated: 2023/12/18 22:21:25 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clean_resources(t_data *d)
{
	size_t	i;

	while (1)
	{
		if (errno != 0 || d->errstat != 0 || d->simustat != SIMU_LASTS)
			break ;
	}
	i = 0;
	while (!errno && d->errstat > THREAD_CREATE_ERROR && i < d->i.n_philo)
	{
		if (pthread_join(d->thread_arr[i], NULL))
		{
			handle_errors(d, THREAD_JOIN_ERROR, __func__, __LINE__);
//			d->errstat = THREAD_JOIN_ERROR;
//			perror_atomically(d, ERRMSG_THREAD_JOIN, __func__, __LINE__);
			break ;
		}
		i++;
	}
	i = 0;
	while (!errno && i < d->i.n_philo)
	{
		if (pthread_mutex_destroy(&d->mutexfork_arr[i]))
		{
			handle_errors(d, MUTEX_DESTROY_ERROR, __func__, __LINE__);
//			d->errstat = MUTEX_DESTROY_ERROR;
//			perror_atomically(d, ERRMSG_MUTEX_DESTROY, __func__, __LINE__);
			break ;
		}
		i++;
	}
	__DEBUG__(d);
	if (errno != EINVAL && !d->errstat)
		free_safely(d->p_arr, d->thread_arr, d->mutexfork_arr, d);
	__DEBUG__(d);
}
