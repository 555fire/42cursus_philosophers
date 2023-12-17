/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:54:37 by mamiyaza          #+#    #+#             */
/*   Updated: 2023/12/18 00:21:20 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clean_resources(t_data *d)
{
	size_t	i;
	// size_t	loop_count;

	// loop_count = 0;
	// while (loop_count <= 100000000)
	// {
	// 	if (errno || d->errstat || d->simustat)
	// 		break ;
	// 	loop_count++;
	// 	if (loop_count % 1000000 == 0)
	// 		__DEBUG_PRINT_LOOP_COUNT__(loop_count);
	// }

	i = 0;
	while (!errno && d->errstat > THREAD_CREATE_ERROR && i < d->i.n_philo)
	{
		if (pthread_join(d->thread_arr[i], NULL))
		{
			d->errstat = THREAD_JOIN_ERROR;
			break ;
		}
		i++;
	}

	i = 0;
	while (!errno && i < d->i.n_philo)
	{
		if (pthread_mutex_destroy(&d->mutexfork_arr[i]))
		{
			perror(ERRMSG_MUTEX_DESTROY);
			d->errstat = MUTEX_DESTROY_ERROR;
			break ;
		}
		i++;
	}

	// if (errno || d->errstat)
	// 	print_errstat(d, d->errstat);

	__DEBUG__(d);
	if (errno != EINVAL && !d->errstat)
	{
		free_safely(d->p_arr);
		free_safely(d->thread_arr);
		free_safely(d->mutexfork_arr);
		free_safely(d);
	}
	__DEBUG__(d);
}
