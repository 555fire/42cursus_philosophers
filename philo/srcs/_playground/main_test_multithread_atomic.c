/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_multithread_atomic.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:05:51 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/01/15 16:49:22 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

#define ANSI_BOLD_BLINK_RED "\033[1;5;31m"
#define ANSI_RESET "\033[m"
#define MSG0 "Test print 0 of \"main_test_multithread_atomic\".\n"
#define MSG1 "Test print 1 of \"main_test_multithread_atomic\".\n"
#define MSG2 "The initial value of atomic_print is [%d].\n"
#define MSG3 "The modified value of atomic_print is [%d].\n"
#define MSG4 "end\n"

typedef enum e_printstat
{
	UNLOCKED,
	LOCKED,
}	t_printstat;

void	*routine0(void *passed_arg)
{
	_Atomic t_printstat	*atomic_put_stdout;

	atomic_put_stdout = passed_arg;
	while (1)
	{
		if (*atomic_put_stdout == UNLOCKED)
		{
			*atomic_put_stdout = LOCKED;
			break ;
		}
	}
	printf(ANSI_BOLD_BLINK_RED MSG0 ANSI_RESET);
	*atomic_put_stdout = UNLOCKED;
	return (NULL);
}

void	*routine1(void *passed_arg)
{
	_Atomic t_printstat	*atomic_put_stdout;

	atomic_put_stdout = passed_arg;
	while (1)
	{
		if (*atomic_put_stdout == UNLOCKED)
		{
			*atomic_put_stdout = LOCKED;
			break ;
		}
	}
	printf(ANSI_BOLD_BLINK_RED MSG1 ANSI_RESET);
	*atomic_put_stdout = UNLOCKED;
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t			thread0;
	pthread_t			thread1;
	_Atomic t_printstat	atomic_put_stdout;

	(void)argc;
	(void)argv;
	printf(MSG2, atomic_put_stdout);
	atomic_put_stdout = UNLOCKED;
	printf(MSG3, atomic_put_stdout);
	pthread_create(&thread0, NULL, routine0, &atomic_put_stdout);
	pthread_create(&thread1, NULL, routine1, &atomic_put_stdout);
	pthread_join(thread0, NULL);
	pthread_join(thread1, NULL);
	printf(MSG4);
	return (0);
}
