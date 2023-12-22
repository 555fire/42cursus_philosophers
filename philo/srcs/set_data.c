/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:55:08 by mamiyaza          #+#    #+#             */
/*   Updated: 2023/12/23 01:07:13 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_funcstat	valid_argc_and_argv(t_data *d, size_t argc, char **argv)
{
	size_t	i;
	size_t	arg;

	if (argc != 5 && argc != 6)
	{
		handle_errors(d, ARGC_ERROR, __func__, __LINE__);
		return (1);
	}
	i = 1;
	while (i <= argc - 1)
	{
		arg = ph_atoi(argv[i], d);
		if (d->errstat || (i == 1 && (arg < 1 || arg > 200))
			|| ((i >= 2 && i <= 4) && (arg < 60 || arg > INT_MAX))
			|| (i == 5 && (arg < 0 || arg > INT_MAX)))
		{
			handle_errors(d, ARGV_ERROR, __func__, __LINE__);
			return (1);
		}
		i++;
	}
	return (0);
}

static t_funcstat	set_args(t_data *d, size_t argc, char **argv)
{
	if (valid_argc_and_argv(d, argc, argv))
		return (1);
	d->i.n_philo = ph_atoi(argv[1], d);
	d->i.time_to_die = ph_atoi(argv[2], d);
	d->i.time_to_eat = ph_atoi(argv[3], d);
	d->i.time_to_sleep = ph_atoi(argv[4], d);
	if (argc == 6)
		d->i.n_times_must_eat = ph_atoi(argv[5], d);
	else
		d->i.n_times_must_eat = INT_MAX;
	return (0);
}

static t_funcstat	alloc_attrs(t_data *d)
{
	d->p_arr = NULL;
	d->p_arr = ph_calloc(d->i.n_philo + NUM_OF_MONITORS, sizeof(t_personal), d);
	if (d->errstat)
		return (1);
	d->thread_arr = NULL;
	d->thread_arr = ph_calloc(d->i.n_philo + NUM_OF_MONITORS,
			sizeof(pthread_t), d);
	if (d->errstat)
		return (1);
	d->mutexfork_arr = NULL;
	d->mutexfork_arr = ph_calloc(d->i.n_philo, sizeof(pthread_mutex_t), d);
	if (d->errstat)
		return (1);
	return (0);
}

static t_funcstat	set_attrs(t_data *d)
{
	size_t	i;

	if (alloc_attrs(d))
		return (1);
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
	return (0);
}

t_data	*set_data(t_data *d, size_t argc, char **argv)
{
	size_t	i;

	d = ph_calloc_without_d(sizeof(t_data), 1);
	if (errno)
		return (d);
	if (set_args(d, argc, argv) || set_attrs(d))
		return (d);
	i = 0;
	while (i < d->i.n_philo)
	{
		if (pthread_mutex_init(&d->mutexfork_arr[i], NULL))
		{
			handle_errors(d, MUTEX_INIT_ERROR, __func__, __LINE__);
			break ;
		}
		i++;
	}
	d->start_time = get_usec_time(d) + 50000;
	return (d);
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