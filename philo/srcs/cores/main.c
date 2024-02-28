/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:54:51 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/22 21:23:41 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#ifndef CALL_DESTRUCTOR
# define CALL_DESTRUCTOR 0
#endif

int					main(const int argc, char **const argv);
//
static t_funcstat	allocate_data(t_data **d);
static void			wait_till_simu_ends(const t_simustat simustat);

int	main(int argc, char **argv)
{
	t_data		*d;

	__DEBUG_PRINT_SIMUSTART__();
	if (validate_input(argc, argv)
		|| allocate_data(&d)
		|| set_data(d, argc, argv))
		return (0);
	if (create_threads(d, d->i.n_philo, &d->p_arr, &d->thread_arr))
	{
		clean_resources(d);
		return (0);
	}
	wait_till_simu_ends(d->simustat);
	clean_resources(d);
	__DEBUG_PRINT_SIMUEND__();
	return (0);
}

//

static t_funcstat	allocate_data(t_data **d)
{
	*d = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!d)
	{
		putstr_stderr_atomic(&(*d)->printstat, ANSI_BOLD_RED ERRMSG_MALLOC ANSI_RESET);
		return (FAIL);
	}
	return (SUCCESS);
}

static void	wait_till_simu_ends(const t_simustat simustat)
{
	while (1)
	{
		if (simustat != SIMU_LASTS)
			break ;
	}
}

#if CALL_DESTRUCTOR

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks philo");
}
#endif

/*
(*d).i.n_philo = ft_atoi(argv[1]);
d->i.n_philo = ft_atoi(argv[1]);
these 2 are same meaning.

*d->i.n_philo = ft_atoi(argv[1]);
*(d->i.n_philo) = ft_atoi(argv[1]);
these 2 are same meaning.
*/
