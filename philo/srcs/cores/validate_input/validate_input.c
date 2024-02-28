/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:40:42 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/22 21:11:41 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_funcstat			validate_input(const size_t argc, char **const argv);
//
static t_funcstat	validate_num_input(const size_t argc);

t_funcstat	validate_input(const size_t argc, char **const argv)
{
	if (validate_num_input(argc))
	{
		putstr_stderr(ANSI_BOLD_RED ERRMSG_NUM_OF_INPUTS ANSI_RESET);
		return (FAIL);
	}
	if (validate_input_value(argc, argv))
	{
		putstr_stderr(ANSI_BOLD_RED ERRMSG_INPUT_VALUE ANSI_RESET);
		return (FAIL);
	}
	return (SUCCESS);
}

//

static t_funcstat	validate_num_input(const size_t argc)
{
	return (argc < MIN_ARGC || argc > MAX_ARGC);
}
