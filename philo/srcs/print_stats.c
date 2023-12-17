#include "../includes/philo.h"

static void	lock_printstat(t_data *d)
{
	printf("The current value of printstat is [%d]. (%s, %d)\n", d->printstat, __func__, __LINE__);
	while (1)
	{
		if (d->printstat == UNLOCKED)
		{
			d->printstat = LOCKED;
			break ;
		}
	}
}

static void	unlock_printstat(t_data *d)
{
	printf("The current value of printstat is [%d]. (%s, %d)\n", d->printstat, __func__, __LINE__);
	if (d->printstat == UNLOCKED)
	{
		d->errstat = PRINTSTAT_ERROR;
		printf(ERRMSG_PRINTSTAT);
	}
	else
		d->printstat = UNLOCKED;
}

// //static t_funcstat	lock_printstat(t_printstat *printstat)
// static t_funcstat	lock_printstat(t_data *d)
// {
// 	if (d->printstat == LOCKED)
// 	{
// 		printf("%s", ERRMSG_PRINTSTAT_LOCKED);
// 		return (FAILED);
// 	}
// 	d->printstat = LOCKED;
// 	return (SUCCEEDED);
// }
//
// //static t_funcstat	unlock_printstat(t_printstat *printstat)
// static t_funcstat	unlock_printstat(t_data *d)
// {
// 	if (d->printstat == UNLOCKED)
// 	{
// 		printf("%s", ERRMSG_PRINTSTAT_UNLOCKED);
// 		return (FAILED);
// 	}
// 	d->printstat = UNLOCKED;
// 	return (SUCCEEDED);
// }

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
	lock_printstat(d);
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
	unlock_printstat(d);
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
	lock_printstat(own_p->d);
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
	unlock_printstat(own_p->d);
	return (0);
}

t_funcstat	print_simustat(t_personal *own_p, t_simustat simustat)
{
	time_t	usec_time;

	usec_time = get_usec_time(own_p->d);
	if (own_p->d->errstat)
		return (1);
//	own_p->d->printstat = UNLOCKED;
//	own_p->d->printstat = LOCKED;
	lock_printstat(own_p->d);
	if (simustat == SIMU_LASTS)
		;
	else if (simustat == ANY_ERROR_HAS_OCCURRED)
		;
	else if (simustat == ANYONE_DIED)
		printf("%ld%s%zu%s%s",usec_time, SPC, own_p->philo_i, SPC, MSG_DIED);
	else if (simustat == REACHED_N_TIMES_MUST_EAT)
		;
//	own_p->d->printstat = LOCKED;
//	own_p->d->printstat = UNLOCKED;
	unlock_printstat(own_p->d);
	return (0);
}
