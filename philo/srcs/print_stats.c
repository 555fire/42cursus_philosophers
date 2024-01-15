/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:55:04 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/01/15 21:24:01 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		lock_printstat(t_data *d);
void		unlock_printstat(t_data *d);
//
void		atomic_print(t_data *d, const char *s);
void		atomic_print_ansi_bold_red(t_data *d, const char *s);
//
void		set_errstat_simustat_and_print_errmsg(t_data *d, t_errstat errstat, const char *s);
//
t_funcstat	print_philostat(t_personal *own_p, t_philostat philostat);
t_funcstat	print_simustat(t_personal *own_p, t_simustat simustat);

void	lock_printstat(t_data *d)
{
	d->printstat = LOCKED;
}

void	unlock_printstat(t_data *d)
{
	d->printstat = UNLOCKED;
}

void	atomic_print(t_data *d, const char *s)
{
	lock_printstat(d);
	printf("%s\n", s);
	unlock_printstat(d);
}

void	atomic_print_ansi_bold_red(t_data *d, const char *s)
{
	lock_printstat(d);
	printf(ANSI_BOLD_RED"%s"ANSI_RESET"\n", s);
	unlock_printstat(d);
}

void	set_errstat_simustat_and_print_errmsg(t_data *d, t_errstat errstat, const char *s)
{
	d->errstat = errstat;
	d->simustat = ANY_ERROR_HAS_OCCURRED;
	atomic_print_ansi_bold_red(d, s);
}

// void	print_errstat(t_data *d, t_errstat errstat)
// {
// 	if (errstat == ARGC_ERROR)
// 		printf(ANSI_BOLD_RED ERRMSG_ARGC ANSI_RESET);
// 	else if (errstat == ARGV_ERROR)
// 		printf(ANSI_BOLD_RED ERRMSG_ARGV ANSI_RESET);
// 	else if (errstat == MALLOC_ERROR)
// 		printf(ANSI_BOLD_RED ERRMSG_MALLOC ANSI_RESET);
// 	else if (errstat == CALLOC_ARGS_ERROR)
// 		printf(ANSI_BOLD_RED ERRMSG_CALLOC_ARGS ANSI_RESET);
// 	else if (errstat == THREAD_CREATE_ERROR)
// 		printf(ANSI_BOLD_RED ERRMSG_THREAD_CREATE ANSI_RESET);
// 	else if (errstat == THREAD_JOIN_ERROR)
// 		printf(ANSI_BOLD_RED ERRMSG_THREAD_JOIN ANSI_RESET);
// 	else if (errstat == MUTEX_INIT_ERROR)
// 		printf(ANSI_BOLD_RED ERRMSG_MUTEX_INIT ANSI_RESET);
// 	else if (errstat == MUTEX_DESTROY_ERROR)
// 		printf(ANSI_BOLD_RED ERRMSG_MUTEX_DESTROY ANSI_RESET);
// 	else if (errstat == MUTEX_LOCK_ERROR)
// 		printf(ANSI_BOLD_RED ERRMSG_MUTEX_LOCK ANSI_RESET);
// 	else if (errstat == MUTEX_UNLOCK_ERROR)
// 		printf(ANSI_BOLD_RED ERRMSG_MUTEX_UNLOCK ANSI_RESET);
// 	else if (errstat == GETTIMEOFDAY_ERROR)
// 		printf(ANSI_BOLD_RED ERRMSG_GETTIMEOFDAY ANSI_RESET);
// 	else if (errstat == USLEEP_ERROR)
// 		printf(ANSI_BOLD_RED ERRMSG_USLEEP ANSI_RESET);
// }

t_funcstat	print_philostat(t_personal *own_p, t_philostat philostat)
{
	time_t	usec_time;
	time_t	relat_usec;

	usec_time = get_time_usec(own_p->d);
	if (own_p->d->errstat)
		return (1);
	relat_usec = usec_time - own_p->d->start_time;
	lock_printstat(own_p->d);
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
	unlock_printstat(own_p->d);
	return (0);
}

t_funcstat	print_simustat(t_personal *own_p, t_simustat simustat)
{
	time_t	usec_time;

	usec_time = get_time_usec(own_p->d);
	if (own_p->d->errstat)
		return (1);
	lock_printstat(own_p->d);
	if (simustat == SIMU_LASTS)
		;
	else if (simustat == ANY_ERROR_HAS_OCCURRED)
		;
	else if (simustat == ANYONE_DIED)
		printf("%ld%s%zu%s%s", usec_time, SPC, own_p->philo_i, SPC, MSG_DIED);
	else if (simustat == REACHED_N_TIMES_MUST_EAT)
		;
	unlock_printstat(own_p->d);
	return (0);
}
