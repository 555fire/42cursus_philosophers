/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:54:55 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/20 22:18:46 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		*monitor_routine(void *passed_arg_in_the_form_of_void_ptr);
//
static int	did_all_reach_n_times_must_eat(const t_personal *const own_p);
static int	did_anyone_die(const t_personal *const own_p);

void	*monitor_routine(void *passed_arg_in_the_form_of_void_ptr)
{
	t_personal	*own_p;

	own_p = passed_arg_in_the_form_of_void_ptr;
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	if (own_p->d->simustat != SIMU_LASTS)
		return (NULL);
	if (wait_until_target_time(&own_p->d->printstat, own_p->d->start_time))
		return (NULL);
	while (1)
	{
		if (did_all_reach_n_times_must_eat(own_p) == HAS_REACHED)
			break ;
		if (did_anyone_die(own_p) == HAS_DIED)
			break ;
	}
	__DEBUG_PRINT_THREAD_INFO__(own_p->d, own_p);
	return (NULL);
}

//

static int	did_all_reach_n_times_must_eat(const t_personal *const own_p)
{
	size_t	i;

	i = 1;
	while (i <= own_p->d->i.n_philo)
	{
		if (own_p->d->p_arr[i].n_times_eaten < own_p->d->i.n_times_must_eat)
			return (HASNT_REACHED);
		i++;
	}
	own_p->d->simustat = REACHED_N_TIMES_MUST_EAT;
	return (HAS_REACHED);
}

static int	did_anyone_die(const t_personal *const own_p)
{
	size_t	i;
	time_t	cur_time;

	i = 1;
	while (i <= own_p->d->i.n_philo)
	{
		if (get_usec_time(&cur_time))
			return (HASNT_DIED);
		if (own_p->d->p_arr[i].last_eat_time + own_p->d->i.time_to_die
			>= (unsigned long)cur_time)
		{
			own_p->d->simustat = ANYONE_DIED;
			(void)print_philostat(own_p, DEAD);
			return (HASNT_DIED);
		}
		i++;
	}
	return (HAS_DIED);
}
