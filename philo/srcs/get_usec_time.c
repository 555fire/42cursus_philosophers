#include "../includes/philo.h"

time_t	get_usec_time(t_data *d)
{
	struct timeval	s_timeval;
	time_t			usec_time;

//	__DEBUG__(d);

	if (gettimeofday(&s_timeval, NULL))
	{
		__DEBUG__(d);
		d->errstat = GETTIMEOFDAY_ERROR;
		return (0);
	}

//	__DEBUG_PRINT_TIME__(s_timeval.tv_sec);
//	__DEBUG_PRINT_TIME__((unsigned long)s_timeval.tv_usec);
//	__DEBUG_PRINT_TIME__((unsigned long)s_timeval.tv_sec * 1000000);
//	__DEBUG_PRINT_TIME__(s_timeval.tv_sec * 1000000 + s_timeval.tv_usec);
	usec_time = s_timeval.tv_sec * 1000000 + s_timeval.tv_usec;
//	__DEBUG_PRINT_TIME__(usec_time);

	__DEBUG__(d);

	return (usec_time);
}

t_funcstat	wait_precise_time(t_data *d, time_t target_time)
{
	time_t	cur_time;

	cur_time = 0;
	__DEBUG__(d);
//	while (cur_time < target_time)
	while (1)
	{
		__DEBUG__(d);

		cur_time = get_usec_time(d);
		if (d->errstat)
		{
			__DEBUG__(d);
//			return (0);
			return (1);
		}

		__DEBUG_PRINT_TIME__(cur_time);

		if (cur_time < target_time)
		{
			__DEBUG__(d);
			return (0);
		}

//		__DEBUG_PRINT_TIME__(target_time - cur_time / 2);
		__DEBUG_PRINT_TIME__((target_time - cur_time) / 2);

//		if (usleep(target_time - cur_time / 2))
		if (usleep((target_time - cur_time) / 2))
		{
			d->errstat = USLEEP_ERROR;
			__DEBUG__(d);
			return (1);
		}
		__DEBUG__(d);
	}
	__DEBUG__(d);
	__DEBUG_PRINT_SUCCESS__();
//	return (1);
	return (0);
}
