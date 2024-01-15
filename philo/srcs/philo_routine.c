/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:55:00 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/01/15 18:43:39 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_funcstat	try_to_take_forks(t_personal *own_p);
static t_funcstat	philo_eat(t_personal *own_p);
static t_funcstat	philo_sleep(t_personal *own_p);
void				*philo_routine(void *passed_arg_in_the_form_of_void_ptr);

static t_funcstat	try_to_take_forks(t_personal *own_p)
{
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	if (own_p->philo_i % 2 == 0)
	{
		if (wait_precise_time(own_p->d, 100))
			return (1);
	}
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	if (pthread_mutex_lock(&own_p->d->mutexfork_arr[own_p->rhf_i]))
	{
		set_errstat_and_print_errmsg(own_p->d, MUTEX_LOCK_ERROR, ERRMSG_MUTEX_LOCK);
		return (1);
	}
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	print_philostat(own_p, HASTOOKFORK);
	if (pthread_mutex_lock(&own_p->d->mutexfork_arr[own_p->lhf_i]))
	{
		set_errstat_and_print_errmsg(own_p->d, MUTEX_LOCK_ERROR, ERRMSG_MUTEX_LOCK);
		return (1);
	}
	print_philostat(own_p, HASTOOKFORK);
	print_philostat(own_p, EATING);
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	return (0);
}

/*	Wait for the mutex to be unlocked.*/

static t_funcstat	philo_eat(t_personal *own_p)
{
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	if (try_to_take_forks(own_p))
		return (1);
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	if (wait_precise_time(own_p->d, own_p->d->i.time_to_eat))
		return (1);
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	if (pthread_mutex_unlock(&own_p->d->mutexfork_arr[own_p->rhf_i]))
	{
		set_errstat_and_print_errmsg(own_p->d, MUTEX_UNLOCK_ERROR, ERRMSG_MUTEX_UNLOCK);
		return (1);
	}
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	if (pthread_mutex_unlock(&own_p->d->mutexfork_arr[own_p->lhf_i]))
	{
		set_errstat_and_print_errmsg(own_p->d, MUTEX_UNLOCK_ERROR, ERRMSG_MUTEX_UNLOCK);
		return (1);
	}
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	return (0);
}

static t_funcstat	philo_sleep(t_personal *own_p)
{
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	print_philostat(own_p, SLEEPING);
	if (wait_precise_time(own_p->d, own_p->d->i.time_to_sleep))
		return (1);
	return (0);
}

void	*philo_routine(void *passed_arg_in_the_form_of_void_ptr)
{
	t_personal	*own_p;

	own_p = passed_arg_in_the_form_of_void_ptr;
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	if (wait_precise_time(own_p->d, own_p->d->start_time))
		return (NULL);
	while (1)
	{
		if (philo_eat(own_p))
			break ;
		if (philo_sleep(own_p))
			break ;
	}
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	return (NULL);
}

/*
|    eat    |
     ^other philo died and toggle the flag ON
           ^check whether the flag is ON
*/