#include "../includes/philo.h"

static t_funcstat	try_to_take_forks(t_personal *own_p)
{
	if (own_p->philo_i % 2 == 0)
	{
		if (wait_precise_time(own_p->d, 100))
			return (1);
	}
	if (pthread_mutex_lock(&own_p->d->mutexfork_arr[own_p->rhf_i]))
	{
		own_p->d->errstat = MUTEX_LOCK_ERROR;
		return (1);
	}
	print_philostat(own_p, HASTOOKFORK);
	pthread_mutex_lock(&own_p->d->mutexfork_arr[own_p->lhf_i]);
	{
		own_p->d->errstat = MUTEX_LOCK_ERROR;
		return (1);
	}
	print_philostat(own_p, HASTOOKFORK);
	print_philostat(own_p, EATING);
	return (0);
}

/*	Wait for the mutex to be unlocked.*/

static t_funcstat	philo_eat(t_personal *own_p)
{
	if (try_to_take_forks(own_p))
		return (1);
	if (wait_precise_time(own_p->d, own_p->d->i.time_to_eat))
		return (1);
	if (pthread_mutex_unlock(&own_p->d->mutexfork_arr[own_p->rhf_i]))
	{
		own_p->d->errstat = MUTEX_UNLOCK_ERROR;
		return (1);
	}
	if (pthread_mutex_unlock(&own_p->d->mutexfork_arr[own_p->lhf_i]))
	{
		own_p->d->errstat = MUTEX_UNLOCK_ERROR;
		return (1);
	}
	return (0);
}

static t_funcstat	philo_sleep(t_personal *own_p)
{
	print_philostat(own_p, SLEEPING);
	if (wait_precise_time(own_p->d, own_p->d->i.time_to_sleep))
		return (1);
	return (0);
}

void	*philo_routine(void *passed_arg_in_the_form_of_void_ptr)
{
	t_personal	*own_p;

	own_p = passed_arg_in_the_form_of_void_ptr;

	__DEBUG_PRINT_THREAD_INFO__(own_p);
	__DEBUG_WITH_OWN_P__(own_p->d, own_p);

	if (wait_precise_time(own_p->d, own_p->d->start_time))
	{
		__DEBUG__(own_p->d);
		return (NULL);
	}
	__DEBUG__(own_p->d);
	while (1)
	{
		__DEBUG__(own_p->d);
		if (philo_eat(own_p))
			break ;
		__DEBUG__(own_p->d);
		if (philo_sleep(own_p))
			break ;
		__DEBUG__(own_p->d);
	}
	__DEBUG__(own_p->d);
	return (NULL);
}

/*
|    eat    |
     ^other philo died and toggle the flag ON
           ^check whether the flag is ON
*/