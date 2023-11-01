#include "../includes/philo.h"

void	print_errstat_without_d(t_errstat errstat)
{
	if (errstat == ARGC_ERROR)
		printf("%s", ERRMSG_ARGC);
	else if (errstat == ARGV_ERROR)
		printf("%s", ERRMSG_ARGV);
	else if (errstat == CALLOC_ARGS_ERROR)
		printf("%s", ERRMSG_CALLOC_ARGS);
	else if (errstat == MALLOC_ERROR)
		printf("%s", ERRMSG_MALLOC);
	return ;
}

void	print_errstat(t_data *d, t_errstat errstat)
{
	d->printstat = UNLOCKED;
	if (errstat == NO_ERROR)
		;
	else if (errstat == ARGC_ERROR)
		printf("%s", ERRMSG_ARGC);
	else if (errstat == ARGV_ERROR)
		printf("%s", ERRMSG_ARGV);
	else if (errstat == MALLOC_ERROR)
		printf("%s", ERRMSG_MALLOC);
	else if (errstat == CALLOC_ARGS_ERROR)
		printf("%s", ERRMSG_CALLOC_ARGS);
	else if (errstat == THREAD_CREATE_ERROR)
		printf("%s", ERRMSG_THREAD_CREATE);
	else if (errstat == THREAD_JOIN_ERROR)
		printf("%s", ERRMSG_THREAD_JOIN);
	else if (errstat == MUTEX_INIT_ERROR)
		printf("%s", ERRMSG_MUTEX_INIT);
	else if (errstat == MUTEX_DESTROY_ERROR)
		printf("%s", ERRMSG_MUTEX_DESTROY);
	else if (errstat == MUTEX_LOCK_ERROR)
		printf("%s", ERRMSG_MUTEX_LOCK);
	else if (errstat == MUTEX_UNLOCK_ERROR)
		printf("%s", ERRMSG_MUTEX_UNLOCK);
	else if (errstat == GETTIMEOFDAY_ERROR)
		printf("%s", ERRMSG_GETTIMEOFDAY);
	else if (errstat == USLEEP_ERROR)
		printf("%s", ERRMSG_USLEEP);
	d->printstat = LOCKED;
	return ;
}

t_funcstat	print_philostat(t_personal *own_p, t_philostat philostat)
{
	time_t	usec_time;
	time_t	relative_usec_time;

	usec_time = get_usec_time(own_p->d);
	if (own_p->d->errstat)
		return (1);
	relative_usec_time = usec_time - own_p->d->start_time;
	own_p->d->printstat = UNLOCKED;
	if (philostat == WAITING_FOR_TAKINGFORK)
		;
	else if (philostat == HASTOOKFORK)
		printf("%ld%s%zu%s%s", relative_usec_time, SPC, own_p->philo_i, SPC, MSG_TOOKFORK);
	else if (philostat == EATING)
		printf("%ld%s%zu%s%s", relative_usec_time, SPC, own_p->philo_i, SPC, MSG_EATING);
	else if (philostat == SLEEPING)
		printf("%ld%s%zu%s%s", relative_usec_time, SPC, own_p->philo_i, SPC, MSG_SLEEPING);
	else if (philostat == THINKING)
		printf("%ld%s%zu%s%s", relative_usec_time, SPC, own_p->philo_i, SPC, MSG_THINKING);
	else if (philostat == DEAD)
		printf("%ld%s%zu%s%s", relative_usec_time, SPC, own_p->philo_i, SPC, MSG_DIED);
	own_p->d->printstat = LOCKED;
	return (0);
}

t_funcstat	print_simustat(t_personal *own_p, t_simustat simustat)
{
	time_t	usec_time;

	usec_time = get_usec_time(own_p->d);
	if (own_p->d->errstat)
		return (1);
	own_p->d->printstat = UNLOCKED;
	if (simustat == SIMU_LASTS)
		;
	else if (simustat == ANY_ERROR_HAS_OCCURRED)
		;
	else if (simustat == ANYONE_DIED)
		printf("%ld%s%zu%s%s",usec_time, SPC, own_p->philo_i, SPC, MSG_DIED);
	else if (simustat == REACHED_N_TIMES_MUST_EAT)
		;
	own_p->d->printstat = LOCKED;
	return (0);
}
