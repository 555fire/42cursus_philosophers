/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:55:00 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/20 22:19:51 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void				*philo_routine(void *passed_arg_in_the_form_of_void_ptr);
//
static t_funcstat	try_to_take_forks(const t_personal *const own_p);
static t_funcstat	philo_eat(const t_personal *const own_p);
static t_funcstat	philo_sleep(const t_personal *const own_p);

void	*philo_routine(void *passed_arg_in_the_form_of_void_ptr)
{
	t_personal	*own_p;

	own_p = passed_arg_in_the_form_of_void_ptr;
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	if (wait_until_target_time(&own_p->d->printstat, own_p->d->start_time))
		return (NULL);
	while (1)
	{
		if (philo_eat(own_p) || philo_sleep(own_p))
			break ;
	}
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	return (NULL);
}

//

/*	Wait for the mutex to be unlocked.*/
static t_funcstat	try_to_take_forks(const t_personal *const own_p)
{
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	if (own_p->philo_i % 2 == 0)
	{
		if (wait_until_target_time(&own_p->d->printstat, 100))
			return (FAIL);
	}
	if (pthread_mutex_lock(&own_p->d->mutexfork_arr[own_p->rhf_i]))
	{
		putstr_stderr_atomic(&own_p->d->printstat, ANSI_BOLD_RED ERRMSG_MUTEX_LOCK ANSI_RESET);
		return (FAIL);
	}
	print_philostat(own_p, HASTOOKFORK);
	if (pthread_mutex_lock(&own_p->d->mutexfork_arr[own_p->lhf_i]))
	{
		putstr_stderr_atomic(&own_p->d->printstat, ANSI_BOLD_RED ERRMSG_MUTEX_LOCK ANSI_RESET);
		return (FAIL);
	}
	print_philostat(own_p, HASTOOKFORK);
	print_philostat(own_p, EATING);
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	return (SUCCESS);
}

static t_funcstat	philo_eat(const t_personal *const own_p)
{
	if (try_to_take_forks(own_p))
		return (1);
	if (wait_until_target_time(&own_p->d->printstat, own_p->d->i.time_to_eat))
		return (1);
	if (pthread_mutex_unlock(&own_p->d->mutexfork_arr[own_p->rhf_i])
		|| pthread_mutex_unlock(&own_p->d->mutexfork_arr[own_p->lhf_i]))
	{
		putstr_stderr_atomic(&own_p->d->printstat, ANSI_BOLD_RED ERRMSG_MUTEX_UNLOCK ANSI_RESET);
		return (FAIL);
	}
	return (SUCCESS);
}

static t_funcstat	philo_sleep(const t_personal *const own_p)
{
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	print_philostat(own_p, SLEEPING);
	if (wait_until_target_time(&own_p->d->printstat, own_p->d->i.time_to_sleep))
		return (FAIL);
	return (SUCCESS);
}

/*
|    eat    |
     ^other philo died and toggle the flag ON
           ^check whether the flag is ON
*/
