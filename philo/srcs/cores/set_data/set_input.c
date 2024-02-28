/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:37:24 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/22 21:22:15 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_input(t_input *const input, const size_t argc,
			char **const argv);

void	set_input(t_input *const input, const size_t argc,
	char **const argv)
{
	input->n_philo = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->n_times_must_eat = ft_atoi(argv[5]);
	else
		input->n_times_must_eat = INT_MAX;
}
