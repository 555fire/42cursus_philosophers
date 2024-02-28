/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:55:08 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/22 21:20:29 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_funcstat			set_data(t_data *const d, const size_t argc,
						char **const argv);
//
static t_funcstat	allocate_attributes(t_data *const d);
static void			set_attributes(t_data *d);
static t_funcstat	init_mutexes(t_data *d);
static t_funcstat	set_start_time(time_t *start_time);

t_funcstat	set_data(t_data *const d, const size_t argc, char **const argv)
{
	set_input(&d->i, argc, argv);
	if (allocate_attributes(d))
	{
		putstr_stderr_atomic(&d->printstat, ANSI_BOLD_RED ERRMSG_MALLOC ANSI_RESET);
		free_heaps(d->p_arr, d->thread_arr, d->mutexfork_arr, d);
		return (FAIL);
	}
	set_attributes(d);
	if (init_mutexes(d))
	{
		putstr_stderr_atomic(&d->printstat, ANSI_BOLD_RED ERRMSG_MUTEX_INIT ANSI_RESET);
		return (FAIL);
	}
	if (set_start_time(&d->start_time))
	{
		putstr_stderr_atomic(&d->printstat, ANSI_BOLD_RED ERRMSG_GETTIMEOFDAY ANSI_RESET);
		return (FAIL);
	}
	return (SUCCESS);
}

//

static t_funcstat	allocate_attributes(t_data *const d)
{
	d->p_arr = ft_calloc(d->i.n_philo + NUM_OF_MONITORS, sizeof(t_personal));
	d->thread_arr = ft_calloc(d->i.n_philo + NUM_OF_MONITORS,
			sizeof(pthread_t));
	d->mutexfork_arr = ft_calloc(d->i.n_philo, sizeof(pthread_mutex_t));
	if (!d->p_arr || !d->thread_arr || !d->mutexfork_arr)
		return (FAIL);
	return (SUCCESS);
}

static void	set_attributes(t_data *d)
{
	size_t	i;

	i = 0;
	while (i < d->i.n_philo + NUM_OF_MONITORS)
	{
		d->p_arr[i].p_arr_i = i;
		if (i < d->i.n_philo)
			d->p_arr[i].philo_i = i + 1;
		i++;
	}
	i = 0;
	while (i < d->i.n_philo + NUM_OF_MONITORS)
	{
		d->p_arr[i].rhf_i = i;
		if (i < d->i.n_philo - 1)
			d->p_arr[i].lhf_i = i + 1;
		else
			d->p_arr[i].lhf_i = 0;
		i++;
	}
}

static t_funcstat	init_mutexes(t_data *d)
{
	size_t	i;

	i = 0;
	while (i < d->i.n_philo)
	{
		if (pthread_mutex_init(&d->mutexfork_arr[i], NULL))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static t_funcstat	set_start_time(time_t *start_time)
{
	time_t	cur_time;

	if (get_usec_time(&cur_time))
		return (FAIL);
	*start_time = cur_time + LAG_TIME_TILL_START_TIME;
	return (SUCCESS);
}

/*
	line 85-95
	Set indexes of right and left fork of each philosopher.
*/

/*
	Relations of philo ids and fork ids.
	Case of n_philo is 5.
(philo_i - 1):  0 1 2 3 4
      i      :  0 1 2 3 4
   philo_i   :  1 2 3 4 5
   (fork_i)  : 0 1 2 3 4
    rhf_i    :  0 1 2 3 4
    lhf_i    :  1 2 3 4 0
*/
