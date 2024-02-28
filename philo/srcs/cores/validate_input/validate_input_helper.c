/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:47:53 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/22 21:14:36 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_funcstat			validate_input_value(const size_t argc,
						char **const argv);
//
static t_funcstat	validate_num_philo(const size_t i, const size_t arg);
static t_funcstat	validate_time_to_die_eat_sleep(const size_t i,
						const size_t arg);
static t_funcstat	validate_num_eat(const size_t i, const size_t arg);

t_funcstat	validate_input_value(const size_t argc, char **const argv)
{
	size_t	i;
	size_t	arg;

	i = ARGC_NUM_PHILO;
	while (i < argc)
	{
		arg = ft_atoi(argv[i]);
		if (validate_num_philo(i, arg)
			|| validate_time_to_die_eat_sleep(i, arg)
			|| validate_num_eat(i, arg))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static t_funcstat	validate_num_philo(const size_t i, const size_t arg)
{
	return (i == ARGC_NUM_PHILO
		&& (arg < MIN_NUM_PHILO || arg > MAX_NUM_PHILO));
}

static t_funcstat	validate_time_to_die_eat_sleep(const size_t i,
	const size_t arg)
{
	return ((i >= MIN_ARGC_TIME_TO_DIE_EAT_SLEEP
			&& i <= MAX_ARGC_TIME_TO_DIE_EAT_SLEEP)
		&& (arg < MIN_TIME_TO_DIE_EAT_SLEEP
			|| arg > MAX_TIME_TO_DIE_EAT_SLEEP));
}

static t_funcstat	validate_num_eat(const size_t i, const size_t arg)
{
	return (i == ARGC_NUM_EAT && (arg < MIN_NUM_EAT || arg > MAX_NUM_EAT));
}
