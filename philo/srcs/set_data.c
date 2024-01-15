/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:55:08 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/01/15 19:39:48 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_funcstat	validate_argc(size_t argc);
static t_funcstat	validate_num_philo(size_t i, size_t arg);
static t_funcstat	validate_time_to_die_time_to_eat\
_time_to_sleep(size_t i, size_t arg);
static t_funcstat	validate_num_eat(size_t i, size_t arg);
static t_funcstat	validate_argv(t_data *d, size_t argc, char **argv);
static void			set_args(t_data *d, size_t argc, char **argv);
static t_funcstat	validate_and_set_args(t_data *d, size_t argc, char **argv);
static t_funcstat	allocate_attributes(t_data *d);
static t_funcstat	set_attributes(t_data *d);
t_data				*set_data(size_t argc, char **argv);

static t_funcstat	validate_argc(size_t argc)
{
	return (argc < MIN_ARGC || argc > MAX_ARGC);
}

static t_funcstat	validate_num_philo(size_t i, size_t arg)
{
	return (i == ARGC_NUM_PHILO && (arg < MIN_NUM_PHILO || arg > MAX_NUM_PHILO));
}

static t_funcstat	validate_time_to_die_time_to_eat\
_time_to_sleep(size_t i, size_t arg)
{
	return ((i >= MIN_ARGC_TIME_TO_DIE_TIME_TO_EAT_TIME_TO_SLEEP
		&& i <= MAX_ARGC_TIME_TO_DIE_TIME_TO_EAT_TIME_TO_SLEEP)
		&& (arg < MIN_TIME_TO_DIE_TIME_TO_EAT_TIME_TO_SLEEP
		|| arg > MAX_TIME_TO_DIE_TIME_TO_EAT_TIME_TO_SLEEP));
}

static t_funcstat	validate_num_eat(size_t i, size_t arg)
{
	return (i == ARGC_NUM_EAT && (arg < MIN_NUM_EAT || arg > MAX_NUM_EAT));
}

static t_funcstat	validate_argv(t_data *d, size_t argc, char **argv)
{
	size_t	i;
	size_t	arg;

	i = 1;
	while (i < argc)
	{
		arg = ph_atoi(argv[i], d);
		if (d->errstat)
			return (FAILED);
		if (validate_num_philo(i, arg)
			|| validate_time_to_die_time_to_eat_time_to_sleep(i, arg)
			|| validate_num_eat(i, arg))
			return (FAILED);
		i++;
	}
	return (SUCCEEDED);
}

static void	set_args(t_data *d, size_t argc, char **argv)
{
	d->i.n_philo = ph_atoi(argv[1], d);
	d->i.time_to_die = ph_atoi(argv[2], d);
	d->i.time_to_eat = ph_atoi(argv[3], d);
	d->i.time_to_sleep = ph_atoi(argv[4], d);
	if (argc == 6)
		d->i.n_times_must_eat = ph_atoi(argv[5], d);
	else
		d->i.n_times_must_eat = INT_MAX;
}

static t_funcstat	validate_and_set_args(t_data *d, size_t argc, char **argv)
{
	if (validate_argc(argc))
	{
		set_errstat_and_print_errmsg(d, ARGC_ERROR, ERRMSG_ARGC);
		return (FAILED);
	}
	if (validate_argv(d, argc, argv))
	{
		set_errstat_and_print_errmsg(d, ARGV_ERROR, ERRMSG_ARGV);
		return (FAILED);
	}
	set_args(d, argc, argv);
	return (SUCCEEDED);
}

static t_funcstat	allocate_attributes(t_data *d)
{
	d->p_arr = NULL;
	d->p_arr = ph_calloc(d->i.n_philo + NUM_OF_MONITORS, sizeof(t_personal), d);
	if (d->errstat)
		return (FAILED);
	d->thread_arr = NULL;
	d->thread_arr = ph_calloc(d->i.n_philo + NUM_OF_MONITORS,
			sizeof(pthread_t), d);
	if (d->errstat)
		return (FAILED);
	d->mutexfork_arr = NULL;
	d->mutexfork_arr = ph_calloc(d->i.n_philo, sizeof(pthread_mutex_t), d);
	if (d->errstat)
		return (FAILED);
	return (SUCCEEDED);
}

static t_funcstat	set_attributes(t_data *d)
{
	size_t	i;

	if (allocate_attributes(d))
		return (FAILED);
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

t_data	*set_data(size_t argc, char **argv)
{
	t_data	*d;
	size_t	i;

	d = ph_calloc_without_d(sizeof(t_data), 1);
	if (errno)
		return (d);
	if (validate_and_set_args(d, argc, argv) || set_attributes(d))
		return (d);
	i = 0;
	while (i < d->i.n_philo)
	{
		if (pthread_mutex_init(&d->mutexfork_arr[i], NULL))
		{
			set_errstat_and_print_errmsg(d, MUTEX_INIT_ERROR, ERRMSG_MUTEX_INIT);
			break ;
		}
		i++;
	}
	d->start_time = get_time_usec(d) + 50000;
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