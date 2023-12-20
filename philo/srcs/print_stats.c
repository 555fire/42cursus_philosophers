/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:55:04 by mamiyaza          #+#    #+#             */
/*   Updated: 2023/12/20 21:51:33 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	lock_printstat(t_data *d)
{
	d->printstat = LOCKED;
}

void	unlock_printstat(t_data *d)
{
	d->printstat = UNLOCKED;
}

void	print_atomically(t_data *d, char *s)
{
	lock_printstat(d);
	printf("%s", s);
	unlock_printstat(d);
}

void	perror_atomically(t_data *d, char *s, const char *func, int line)
{
	lock_printstat(d);
	printf(ANSI_BOLD_RED"%s"ANSI_RESET"in %s, %d\n", s, func, line);
	unlock_printstat(d);
}

void	handle_error(t_data *d, t_errstat errstat)
{
	lock_printstat(d);
	d->errstat = errstat;
	print_errstat(d, errstat);
	unlock_printstat(d);
}

void	handle_errors(t_data *d, t_errstat errstat, const char *func, int line)
{
	lock_printstat(d);
	d->errstat = errstat;
	print_errstats(errstat, func, line);
	unlock_printstat(d);
}

void	print_errstat(t_data *d, t_errstat errstat)
{
	lock_printstat(d);
	if (errstat == ARGC_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_ARGC ANSI_RESET);
	else if (errstat == ARGV_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_ARGV ANSI_RESET);
	else if (errstat == MALLOC_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_MALLOC ANSI_RESET);
	else if (errstat == CALLOC_ARGS_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_CALLOC_ARGS ANSI_RESET);
	else if (errstat == THREAD_CREATE_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_THREAD_CREATE ANSI_RESET);
	else if (errstat == THREAD_JOIN_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_THREAD_JOIN ANSI_RESET);
	else if (errstat == MUTEX_INIT_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_MUTEX_INIT ANSI_RESET);
	else if (errstat == MUTEX_DESTROY_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_MUTEX_DESTROY ANSI_RESET);
	else if (errstat == MUTEX_LOCK_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_MUTEX_LOCK ANSI_RESET);
	else if (errstat == MUTEX_UNLOCK_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_MUTEX_UNLOCK ANSI_RESET);
	else if (errstat == GETTIMEOFDAY_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_GETTIMEOFDAY ANSI_RESET);
	else if (errstat == USLEEP_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_USLEEP ANSI_RESET);
	unlock_printstat(d);
}

void	print_errstats(t_errstat errstat, const char *func, int line)
{
	if (errstat == ARGC_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_ARGC ANSI_RESET"%s, %d\n",
			func, line);
	else if (errstat == ARGV_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_ARGV ANSI_RESET"%s, %d\n",
			func, line);
	else if (errstat == MALLOC_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_MALLOC ANSI_RESET"%s, %d\n",
			func, line);
	else if (errstat == CALLOC_ARGS_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_CALLOC_ARGS ANSI_RESET"%s, %d\n",
			func, line);
	else if (errstat == THREAD_CREATE_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_THREAD_CREATE ANSI_RESET"%s, %d\n",
			func, line);
	else if (errstat == THREAD_JOIN_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_THREAD_JOIN ANSI_RESET"%s, %d\n",
			func, line);
	else if (errstat == MUTEX_INIT_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_MUTEX_INIT ANSI_RESET"%s, %d\n",
			func, line);
	else if (errstat == MUTEX_DESTROY_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_MUTEX_DESTROY ANSI_RESET"%s, %d\n",
			func, line);
	else if (errstat == MUTEX_LOCK_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_MUTEX_LOCK ANSI_RESET"%s, %d\n",
			func, line);
	else if (errstat == MUTEX_UNLOCK_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_MUTEX_UNLOCK ANSI_RESET"%s, %d\n",
			func, line);
	else if (errstat == GETTIMEOFDAY_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_GETTIMEOFDAY ANSI_RESET"%s, %d\n",
			func, line);
	else if (errstat == USLEEP_ERROR)
		printf(ANSI_BOLD_RED ERRMSG_USLEEP ANSI_RESET"%s, %d\n",
			func, line);
}

t_funcstat	print_philostat(t_personal *own_p, t_philostat philostat)
{
	time_t	usec_time;
	time_t	relat_usec;

	usec_time = get_usec_time(own_p->d);
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

	usec_time = get_usec_time(own_p->d);
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
