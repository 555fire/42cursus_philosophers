/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:55:04 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/20 22:18:23 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		lock_printstat(_Atomic t_printstat *printstat);
void		unlock_printstat(_Atomic t_printstat *printstat);
//
void		putstr_atomic(_Atomic t_printstat *printstat, const char *s);
void		putstr_stderr_atomic(_Atomic t_printstat *printstat, const char *s);
// void		atomic_print(t_data *d, const char *s);
// void		atomic_print_ansi_bold_red(t_data *d, const char *s);
// void		set_and_print_err(t_data *d, t_errstat errstat, const char *s);
//
t_funcstat	print_philostat(const t_personal *const own_p, const t_philostat philostat);
t_funcstat	print_simustat(const t_personal *const own_p, const t_simustat simustat);

void	lock_printstat(_Atomic t_printstat *printstat)
{
	*printstat = LOCKED;
}

void	unlock_printstat(_Atomic t_printstat *printstat)
{
	*printstat = UNLOCKED;
}

void	putstr_atomic(_Atomic t_printstat *printstat, const char *s)
{
	lock_printstat(printstat);
	putstr(s);
	unlock_printstat(printstat);
}

void	putstr_stderr_atomic(_Atomic t_printstat *printstat, const char *s)
{
	lock_printstat(printstat);
	putstr_stderr(s);
	unlock_printstat(printstat);
}

// void	atomic_print_ansi_bold_red(t_data *d, const char *s)
// {
// 	lock_printstat(&d->printstat);
// 	printf(ANSI_BOLD_RED"%s"ANSI_RESET"\n", s);
// 	unlock_printstat(&d->printstat);
// }

// void	set_and_print_err(t_data *d, t_errstat errstat, const char *s)
// {
// 	d->errstat = errstat;
// 	d->simustat = ANY_ERROR_HAS_OCCURRED;
// 	atomic_print_ansi_bold_red(d, s);
// }

t_funcstat	print_philostat(const t_personal *const own_p, const t_philostat philostat)
{
	time_t	usec_time;
	time_t	relat_usec;

	if (get_usec_time(&usec_time))
		return (FAIL);
	relat_usec = usec_time - own_p->d->start_time;
	lock_printstat(&own_p->d->printstat);
	if (philostat == HASTOOKFORK)
		printf("%ld%s%zu%s", relat_usec, SPC, own_p->philo_i, MSG_TOOKFORK);
	else if (philostat == EATING)
		printf("%ld%s%zu%s", relat_usec, SPC, own_p->philo_i, MSG_EATING);
	else if (philostat == SLEEPING)
		printf("%ld%s%zu%s", relat_usec, SPC, own_p->philo_i, MSG_SLEEPING);
	else if (philostat == THINKING)
		printf("%ld%s%zu%s", relat_usec, SPC, own_p->philo_i, MSG_THINKING);
	else if (philostat == DEAD)
		printf("%ld%s%zu%s", relat_usec, SPC, own_p->philo_i, MSG_DIED);
	unlock_printstat(&own_p->d->printstat);
	return (SUCCESS);
}

t_funcstat	print_simustat(const t_personal *const own_p, const t_simustat simustat)
{
	time_t	usec_time;

	if (get_usec_time(&usec_time))
		return (FAIL);
	lock_printstat(&own_p->d->printstat);
	if (simustat == SIMU_LASTS)
		;
	else if (simustat == ANY_ERROR_HAS_OCCURRED)
		;
	else if (simustat == ANYONE_DIED)
		printf("%ld%s%zu%s%s", usec_time, SPC, own_p->philo_i, SPC, MSG_DIED);
	else if (simustat == REACHED_N_TIMES_MUST_EAT)
		;
	unlock_printstat(&own_p->d->printstat);
	return (SUCCESS);
}
