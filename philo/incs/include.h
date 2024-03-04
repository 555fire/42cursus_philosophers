/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:02:20 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/03/01 05:13:27 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

/*----include directives----*/
/* ----include standard libraries----*/
# include <stdlib.h>	/*	header for ""size_t".			*/
# include <stdio.h>		/*	header for "perror", "size_t".	*/

# include <string.h>	/*	header for "memset".			*/
# include <unistd.h>	/*	header for "sleep", "usleep".	*/

# include <limits.h>
# include <errno.h>
# include <stdbool.h>

# include <sys/time.h>	/*	header for "gettimeofday".		*/
# include <pthread.h>
						/*	header for "pthread_create",
							"pthread_join", "pthread_mutex_init",
							"pthread_mutex_destroy".		*/
# include <stdatomic.h>	/*	header for "_Atomic".			*/

#endif