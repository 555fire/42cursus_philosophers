/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:05:59 by mamiyaza          #+#    #+#             */
/*   Updated: 2023/12/17 23:16:43 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

#define ANSI_BOLD_BLINK_RED "\033[1;5;31m"
#define ANSI_RESET "\033[m"
#define MSG0 "Test print of \"main_test_mutex\".\n"

int	main(int argc, char **argv)
{
	pthread_mutex_t	mutex_print;

	(void)argc;
	(void)argv;
	pthread_mutex_init(&mutex_print, NULL);
	pthread_mutex_lock(&mutex_print);
	printf(ANSI_BOLD_BLINK_RED MSG0 ANSI_RESET);
	pthread_mutex_unlock(&mutex_print);
	pthread_mutex_destroy(&mutex_print);
	return (0);
}
