#include <stdio.h>
#include <pthread.h>

# define ANSI_BOLD_BLINK_RED "\033[1;5;31m"
# define ANSI_RESET "\033[m"

void	*routine0(void *passed_arg)
{
	pthread_mutex_t	mutex_print;

	mutex_print = *(pthread_mutex_t *)passed_arg;

	pthread_mutex_lock(&mutex_print);
	printf(ANSI_BOLD_BLINK_RED "Test print 0 of \"main_test_mutex\".\n" ANSI_RESET);
	pthread_mutex_unlock(&mutex_print);

	return (NULL);
}

void	*routine1(void *passed_arg)
{
	pthread_mutex_t	mutex_print;

	mutex_print = *(pthread_mutex_t *)passed_arg;

	pthread_mutex_lock(&mutex_print);
	printf(ANSI_BOLD_BLINK_RED "Test print 1 of \"main_test_mutex\".\n" ANSI_RESET);
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

	printf("end\n");

	return (0);
}
