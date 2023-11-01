#include "../includes/philo.h"

time_t	get_usec_time(t_data *d)
{
	struct timeval	s_timeval;
	time_t			usec_time;

	if (gettimeofday(&s_timeval, NULL))
	{
		__DEBUG__(d);
		d->errstat = GETTIMEOFDAY_ERROR;
		return (0);
	}
	usec_time = s_timeval.tv_sec * 1000000 + s_timeval.tv_usec;

	__DEBUG__(d);

	return (usec_time);
}

t_funcstat	wait_precise_time(t_data *d, time_t target_time)
{
	time_t	cur_time;

	cur_time = 0;

	__DEBUG__(d);

	while (1)
	{
//		__DEBUG__(d);

		cur_time = get_usec_time(d);
		if (d->errstat)
		{
			__DEBUG_PRINT_FAILED__();
			__DEBUG__(d);
			return (1);
		}

		__DEBUG_PRINT_3_TIME__(cur_time, target_time);

//		if (cur_time < target_time)
		if (cur_time >= target_time)
		{
			__DEBUG_PRINT_SUCCEEDED__();
			__DEBUG__(d);
			return (0);
		}


		if (usleep((target_time - cur_time) / 2))
		{
			d->errstat = USLEEP_ERROR;
			__DEBUG_PRINT_FAILED__();
			__DEBUG__(d);
			return (1);
		}
		__DEBUG__(d);
	}
	__DEBUG__(d);
	return (0);
}
