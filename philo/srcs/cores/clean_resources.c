/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:54:37 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/22 21:09:50 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void				clean_resources(t_data *const d);
void				free_heaps(t_personal *p_arr, pthread_t *thread_arr,
						pthread_mutex_t *mutexfork_arr, t_data *d);
//
static t_funcstat	join_threads(t_data *d);
static t_funcstat	destroy_mutexes(t_data *d);

void	clean_resources(t_data *const d)
{
	// if (errstat <= INPUT_VALUE_ERROR)
	// 	return ;
	// if (errstat <= MALLOC_ERROR)
	// {
	// 	free_heaps(d->p_arr, d->thread_arr, d->mutexfork_arr, d);
	// 	return ;
	// }
	// if (errstat < MUTEX_INIT_ERROR)
	// 	return ;
	if (join_threads(d))
	{
		putstr_stderr_atomic(&d->printstat, ANSI_BOLD_RED ERRMSG_THREAD_JOIN ANSI_RESET);
		return ;
	}
	if (destroy_mutexes(d))
	{
		putstr_stderr_atomic(&d->printstat, ANSI_BOLD_RED ERRMSG_MUTEX_DESTROY ANSI_RESET);
		return ;
	}
	free_heaps(d->p_arr, d->thread_arr, d->mutexfork_arr, d);
}

//

void	free_heaps(t_personal *p_arr, pthread_t *thread_arr,
	pthread_mutex_t *mutexfork_arr, t_data *d)
{
	free_safely(p_arr);
	free_safely(thread_arr);
	free_safely(mutexfork_arr);
	free_safely(d);
}

//

static t_funcstat	join_threads(t_data *d)
{
	size_t	i;

	i = 0;
	while (d->errstat > THREAD_CREATE_ERROR && i < d->i.n_philo)
	{
		if (pthread_join(d->thread_arr[i], NULL))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static t_funcstat	destroy_mutexes(t_data *d)
{
	size_t	i;

	i = 0;
	while (i < d->i.n_philo)
	{
		if (pthread_mutex_destroy(&d->mutexfork_arr[i]))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}
