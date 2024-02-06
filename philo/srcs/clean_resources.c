/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:54:37 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/01/31 14:50:27 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void				clean_resources(t_data *d);
static void			wait_till_simu_ends(t_data *d);
static t_funcstat	join_threads(t_data *d);
static t_funcstat	destroy_mutexes(t_data *d);

static void			wait_till_simu_ends(t_data *d)
{
	__DEBUG__(d);
	while (1)
	{
		if (errno || d->simustat != SIMU_LASTS)
			break ;
	}
	__DEBUG__(d);
}

static t_funcstat	join_threads(t_data *d)
{
	size_t	i;

	i = 0;
	while (!errno && d->errstat > THREAD_CREATE_ERROR && i < d->i.n_philo)
	{
		if (pthread_join(d->thread_arr[i], NULL))
		{
			set_errstat_simustat_and_print_errmsg(d, THREAD_JOIN_ERROR, ERRMSG_THREAD_JOIN);
			return (FAILED);
		}
		i++;
	}
	return (SUCCEEDED);
}

static t_funcstat	destroy_mutexes(t_data *d)
{
	size_t	i;

	i = 0;
	while (!errno && i < d->i.n_philo)
	{
		if (pthread_mutex_destroy(&d->mutexfork_arr[i]))
		{
			set_errstat_simustat_and_print_errmsg(d, MUTEX_DESTROY_ERROR, ERRMSG_MUTEX_DESTROY);
			return (FAILED);
		}
		i++;
	}
	return (SUCCEEDED);
}

void	clean_resources(t_data *d)
{
	__DEBUG__(d);
	wait_till_simu_ends(d);
	__DEBUG__(d);
	if (join_threads(d))
		return ;
	if (destroy_mutexes(d))
		return ;
	if (d)
		free_safely(d->p_arr, d->thread_arr, d->mutexfork_arr, d);
	__DEBUG__(d);
}
