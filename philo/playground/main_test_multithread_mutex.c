/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_multithread_mutex.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:05:55 by mamiyaza          #+#    #+#             */
/*   Updated: 2023/12/17 23:16:13 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

#define ANSI_BOLD_BLINK_RED "\033[1;5;31m"
#define ANSI_RESET "\033[m"
#define MSG0 "Test print 0 of \"main_test_mutex\".\n"
#define MSG1 "Test print 1 of \"main_test_mutex\".\n"
#define MSG2 "end\n"

void	*routine0(void *passed_arg)
{
	pthread_mutex_t	mutex_print;

	mutex_print = *(pthread_mutex_t *)passed_arg;
	pthread_mutex_lock(&mutex_print);
	printf(ANSI_BOLD_BLINK_RED MSG0 ANSI_RESET);
	pthread_mutex_unlock(&mutex_print);
	return (NULL);
}

void	*routine1(void *passed_arg)
{
	pthread_mutex_t	mutex_print;

	mutex_print = *(pthread_mutex_t *)passed_arg;
	pthread_mutex_lock(&mutex_print);
	printf(ANSI_BOLD_BLINK_RED MSG1 ANSI_RESET);
	pthread_mutex_unlock(&mutex_print);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t		thread0;
	pthread_t		thread1;
	pthread_mutex_t	mutex_print;

	(void)argc;
	(void)argv;
	pthread_mutex_init(&mutex_print, NULL);
	pthread_create(&thread0, NULL, routine0, &mutex_print);
	pthread_create(&thread1, NULL, routine1, &mutex_print);
	pthread_join(thread0, NULL);
	pthread_join(thread1, NULL);
	pthread_mutex_destroy(&mutex_print);
	printf(MSG2);
	return (0);
}
