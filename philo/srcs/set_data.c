#include "../includes/philo.h"

static t_funcstat	valid_args(t_data *d, size_t argc, char **argv)
{
	size_t	i;

	if (argc != 5 && argc != 6)
	{
		d->errstat = ARGC_ERROR;
		return (1);
	}
	i = 1;
	while (i <= argc - 1)
	{
		ph_atoi(argv[i], d);
		if (d->errstat)
			return (1);
		i++;
	}
	return (0);
}

static t_funcstat	set_args(t_data *d, size_t argc, char **argv)
{
	d->i.n_philo = ph_atoi(argv[1], d);
	d->i.time_to_die = ph_atoi(argv[2], d);
	d->i.time_to_eat = ph_atoi(argv[3], d);
	d->i.time_to_sleep = ph_atoi(argv[4], d);
	if (argc == 6)
		d->i.n_times_must_eat = ph_atoi(argv[5], d);
	else
		d->i.n_times_must_eat = INT_MAX;
//	__DEBUG_WITH_INPUT__(d);
	return (0);
}

t_data	*set_data(t_data *d, size_t argc, char **argv)
{
	size_t	i;

	d = ph_calloc_without_d(sizeof(t_data), 1);
	if (errno)
		return (d);

//	__DEBUG_PRINT_ARGC__(argc);

	if (valid_args(d, argc, argv))
		return (d);
	set_args(d, argc, argv);
//	__DEBUG_WITH_INPUT__(d);

	d->p_arr = NULL;
	d->p_arr = ph_calloc(d->i.n_philo + NUM_OF_MONITORS, sizeof(t_personal), d);
	if (d->errstat)
		return (d);

	d->thread_arr = NULL;
	d->thread_arr = ph_calloc(d->i.n_philo + NUM_OF_MONITORS, sizeof(pthread_t), d);
	if (d->errstat)
		return (d);

	d->mutexfork_arr = NULL;
	d->mutexfork_arr = ph_calloc(d->i.n_philo, sizeof(pthread_mutex_t), d);
	if (d->errstat)
	{
		__DEBUG__(d);
		return (d);
	}

//	__DEBUG_PRINT_NL__();

	i = 0;
	while (i < d->i.n_philo + NUM_OF_MONITORS)
	{
		d->p_arr[i].p_arr_i = i;
		if (i < d->i.n_philo)
			d->p_arr[i].philo_i = i + 1;
//		__DEBUG_WITH_OWN_P__(d, &d->p_arr[i]);
		i++;
	}

//	__DEBUG_PRINT_NL__();

	i = 0;
	while (i < d->i.n_philo + NUM_OF_MONITORS)
	{
		d->p_arr[i].rhf_i = i;
		if (i < d->i.n_philo - 1)
			d->p_arr[i].lhf_i = i + 1;
		else
			d->p_arr[i].lhf_i = 0;
//		__DEBUG_WITH_OWN_P__(d, &d->p_arr[i]);
		i++;
	}

	__DEBUG_PRINT_NL__();

	i = 0;
	while (i < d->i.n_philo)
	{
		if (pthread_mutex_init(&d->mutexfork_arr[i], NULL))
		{
			d->errstat = MUTEX_INIT_ERROR;
			__DEBUG__(d);
			break ;
		}
		i++;
	}

	d->start_time = get_usec_time(d) + 50000;
	__DEBUG_PRINT_TARGET_TIME__(d->start_time);

	return (d);
}

/*
	line 85-95
	Set indexes of right and left fork of each philosopher.
*/

/*
 Relations of philo ids and fork ids.
 Case of n_philo is 5.
(philo_i - 1):  0 1 2 3 4
      i      :  0 1 2 3 4
   philo_i   :  1 2 3 4 5
   (fork_i)  : 0 1 2 3 4
    rhf_i    :  0 1 2 3 4
    lhf_i    :  1 2 3 4 0
*/