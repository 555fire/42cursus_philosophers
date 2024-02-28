/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:54:47 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/20 21:12:02 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_funcstat	get_usec_time(time_t *const time);
t_funcstat	wait_for_certain_time(_Atomic t_printstat *printstat,
						const time_t certain_time);
t_funcstat	wait_until_target_time(_Atomic t_printstat *printstat,
						const time_t target_time);

t_funcstat	get_usec_time(time_t *const usec_time)
{
	struct timeval	s_timeval;

	if (gettimeofday(&s_timeval, NULL))
		return (FAIL);
	*usec_time = s_timeval.tv_sec * 1000000 + s_timeval.tv_usec;
	return (SUCCESS);
}

t_funcstat	wait_for_certain_time(_Atomic t_printstat *printstat, const time_t certain_time)
{
	time_t	cur_time;
	time_t	target_time;

	while (1)
	{
		if (get_usec_time(&cur_time))
		{
			putstr_stderr_atomic(printstat, ANSI_BOLD_RED ERRMSG_GETTIMEOFDAY ANSI_RESET);
			return (FAIL);
		}
		target_time = cur_time + certain_time;
		if (cur_time >= target_time)
			return (SUCCESS);
		if (usleep((target_time - cur_time) / 2))
		{
			putstr_stderr_atomic(printstat, ANSI_BOLD_RED ERRMSG_USLEEP ANSI_RESET);
			return (FAIL);
		}
	}
	return (SUCCESS);
}

t_funcstat	wait_until_target_time(_Atomic t_printstat *printstat, const time_t target_time)
{
	time_t	cur_time;

	while (1)
	{
		if (get_usec_time(&cur_time))
		{
			putstr_stderr_atomic(printstat, ANSI_BOLD_RED ERRMSG_GETTIMEOFDAY ANSI_RESET);
			return (FAIL);
		}
		if (cur_time >= target_time)
			return (SUCCESS);
		if (usleep((target_time - cur_time) / 2))
		{
			putstr_stderr_atomic(printstat, ANSI_BOLD_RED ERRMSG_USLEEP ANSI_RESET);
			return (FAIL);
		}
	}
	return (SUCCESS);
}
