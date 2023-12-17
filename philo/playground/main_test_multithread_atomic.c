#include <stdio.h>
#include <pthread.h>

#define ANSI_BOLD_BLINK_RED "\033[1;5;31m"
#define ANSI_RESET "\033[m"

typedef enum e_printstat
{
	UNLOCKED,
	LOCKED,
}	t_printstat;

// void	lock_printstat()
// {}

// void	unlock_printstat()
// {}

void	*routine0(void *passed_arg)
{
	_Atomic t_printstat	*atomic_print;

	atomic_print = passed_arg;

	while (1)
	{
		if (*atomic_print == UNLOCKED)
		{
			*atomic_print = LOCKED;
			break ;
		}
	}

	printf(ANSI_BOLD_BLINK_RED "Test print 0 of \"main_test_multithread_atomic\".\n" ANSI_RESET);

	*atomic_print = UNLOCKED;

	return (NULL);
}

void	*routine1(void *passed_arg)
{
	_Atomic t_printstat	*atomic_print;

	atomic_print = passed_arg;

	while (1)
	{
		if (*atomic_print == UNLOCKED)
		{
			*atomic_print = LOCKED;
			break ;
		}
	}

	printf(ANSI_BOLD_BLINK_RED "Test print 1 of \"main_test_multithrad_atomic\".\n" ANSI_RESET);

	*atomic_print = UNLOCKED;

	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t			thread0;
	pthread_t			thread1;
	_Atomic t_printstat	atomic_print;

	(void)argc;
	(void)argv;
	printf("The initial value of atomic_print is [%d].\n", atomic_print);
	atomic_print = UNLOCKED;
	printf("The modified value of atomic_print is [%d].\n", atomic_print);
	pthread_create(&thread0, NULL, routine0, &atomic_print);
	pthread_create(&thread1, NULL, routine1, &atomic_print);

	pthread_join(thread0, NULL);
	pthread_join(thread1, NULL);

	printf("end\n");

	return (0);
}
