/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:54:40 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/01/15 17:25:26 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	create_threads(t_data *d);

void	create_threads(t_data *d)
{
	size_t	i;
	void	*func_ptr;

	if (errno || d->errstat)
		return ;
	i = 0;
	while (i <= d->i.n_philo)
	{
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
			set_errstat_and_print_stderr_with_debug_info(d, THREAD_CREATE_ERROR, ERRMSG_THREAD_CREATE, __func__);
			return ;
		}
		i++;
	}
}
