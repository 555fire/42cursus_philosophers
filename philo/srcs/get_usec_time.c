/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_usec_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:54:47 by mamiyaza          #+#    #+#             */
/*   Updated: 2023/12/17 22:54:48 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t	get_usec_time(t_data *d)
{
	struct timeval	s_timeval;
	time_t			usec_time;

	if (gettimeofday(&s_timeval, NULL))
	{
//		__DEBUG__(d);
		d->errstat = GETTIMEOFDAY_ERROR;
		return (0);
	}
	usec_time = s_timeval.tv_sec * 1000000 + s_timeval.tv_usec;
	return (usec_time);
}

t_funcstat	wait_precise_time(t_data *d, time_t target_time)
{
	time_t	cur_time;

	cur_time = 0;
	while (1)
	{
		cur_time = get_usec_time(d);
		if (d->errstat)
		{
			__DEBUG_PRINT_FAILED__();
			return (1);
		}
		__DEBUG_PRINT_DIFF_TIME__(cur_time, target_time);
		if (cur_time >= target_time)
		{
			__DEBUG_PRINT_SUCCEEDED__();
			return (0);
		}
		__DEBUG_PRINT_WAITS__();
		if (usleep((target_time - cur_time) / 2))
		{
			d->errstat = USLEEP_ERROR;
			__DEBUG_PRINT_FAILED__();
			return (1);
		}
	}
	return (0);
}
