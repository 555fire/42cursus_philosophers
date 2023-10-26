#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>	// for gettimeofday, struct timeeval.
#include <time.h>		// for time_t.

#define STR_TO_OUTPUT "GoGo42!\n"
#define ERRMSG_GETTIMEOFDAY "fatal error: gettimeofday\n"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*s++)
		i++;
	return (i);
}

// unsigned long long	do_gettimeofday_and_print(void)
static void	do_gettimeofday_and_print(void)
{
	struct timeval	tv;
	time_t			tv1;
	time_t			tv2;

	if (gettimeofday(&tv, NULL))
	{
		printf("%s", ERRMSG_GETTIMEOFDAY);
		return ;
	}
	printf("tv_sec :[%lu]\n", tv.tv_sec);
	printf("tv_usec:[%d]\n\n", tv.tv_usec);
	// printf("tv_usec:[%lu]\n\n", tv.tv_usec);
	tv1 = tv.tv_sec * 1000000 + tv.tv_usec;
	tv2 = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	// printf("tv in microsec:[%lu]\n", tv.tv_sec * 1000000 + tv.tv_usec);
	// printf("tv in millisec:[%lu]\n", tv.tv_sec * 1000 + tv.tv_usec / 1000);
	printf("tv in microsec:[%lu]\n", tv1);
	printf("tv in millisec:[%lu]\n", tv2);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	write(STDOUT_FILENO, STR_TO_OUTPUT, ft_strlen(STR_TO_OUTPUT) + 1);
	do_gettimeofday_and_print();
	return (0);
}
