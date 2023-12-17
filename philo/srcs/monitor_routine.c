/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:54:55 by mamiyaza          #+#    #+#             */
/*   Updated: 2023/12/17 22:54:56 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	have_everyone_reached_n_times_must_eat(t_personal *own_p)
{
	size_t	i;

	i = 0;
	__DEBUG__(own_p->d);
	while (i < own_p->d->i.n_philo)
	{
		if (own_p->d->p_arr[i].n_times_eaten < own_p->d->i.n_times_must_eat)
			return (HASNT_REACHED);
		i++;
	}
	own_p->d->simustat = REACHED_N_TIMES_MUST_EAT;
	return (HAS_REACHED);
}

static int	did_anyone_died(t_personal *own_p)
{
	size_t	i;
	time_t	cur_time;

	i = 0;
	__DEBUG__(own_p->d);
	while (i < own_p->d->i.n_philo)
	{
		cur_time = get_usec_time(own_p->d);
		if (own_p->d->errstat)
			return (DIED_OR_AN_ERROR_HAS_OCCURRED);
		if (own_p->d->p_arr[i].last_eat_time + own_p->d->i.time_to_die >= (unsigned long)cur_time)
		{
			own_p->d->simustat = ANYONE_DIED;
			(void)print_philostat(own_p, DEAD);
			return (DIED_OR_AN_ERROR_HAS_OCCURRED);
		}
		i++;
	}
	return (DIDNT_DIE);
}

void	*monitor_routine(void *passed_arg_in_the_form_of_void_ptr)
{
	t_personal	*own_p;

	own_p = passed_arg_in_the_form_of_void_ptr;
	__DEBUG_PRINT_THREAD_INFO__(own_p);
	if (own_p->d->errstat)
		return (NULL);
//	__DEBUG__(own_p->d);
	if (wait_precise_time(own_p->d, own_p->d->start_time))
		return (NULL);
//	__DEBUG__(own_p->d);
	while (1)
	{
//		__DEBUG__(own_p->d);
		if (have_everyone_reached_n_times_must_eat(own_p) == HAS_REACHED)
			break ;
//		__DEBUG__(own_p->d);
		if (did_anyone_died(own_p) == DIED_OR_AN_ERROR_HAS_OCCURRED)
			break ;
//		__DEBUG__(own_p->d);
	}
//	__DEBUG__(own_p->d);
	return (NULL);
}
