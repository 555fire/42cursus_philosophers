/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:54:40 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/22 21:26:09 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_funcstat	create_threads(t_data *d, const size_t n_philo,
				t_personal **const p_arr, pthread_t **const thread_arr);

t_funcstat	create_threads(t_data *d, const size_t n_philo,
	t_personal **const p_arr, pthread_t **const thread_arr)
{
	size_t	i;
	void	*thread_routine;

	i = 0;
	while (i <= n_philo)
	{
		(*p_arr)[i].d = d;
		(*p_arr)[i].philo_i = i;
		if (i == 0)
			thread_routine = &monitor_routine;
		else
			thread_routine = &philo_routine;
		if (pthread_create(&(*thread_arr)[i], NULL, thread_routine, &(*p_arr)[i]))
		{
			putstr_stderr_atomic(&d->printstat, ANSI_BOLD_RED ERRMSG_THREAD_CREATE ANSI_RESET);
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}
