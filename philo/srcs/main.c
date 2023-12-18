/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:54:51 by mamiyaza          #+#    #+#             */
/*   Updated: 2023/12/18 10:46:54 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data				*d;

	__DEBUG_PRINT_SIMUSTART__();
	d = NULL;
	d = set_data(d, argc, argv);
	create_threads(d);
	clean_resources(d);
	__DEBUG_PRINT_SIMUEND__();
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks philo");
// }

/*
(*d).i.n_philo = ph_atoi(argv[1]);
d->i.n_philo = ph_atoi(argv[1]);
these 2 are same meaning.

*d->i.n_philo = ph_atoi(argv[1]);
*(d->i.n_philo) = ph_atoi(argv[1]);
these 2 are same meaning.
*/