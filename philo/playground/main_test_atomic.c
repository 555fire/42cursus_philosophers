#include <stdio.h>
#include <stdatomic.h>

# define ANSI_BOLD_BLINK_RED "\033[1;5;31m"
# define ANSI_RESET "\033[m"

typedef enum e_printstat
{
	UNLOCKED,
	LOCKED,
}	t_printstat;

int	main(int argc, char **argv)
{
	_Atomic t_printstat	printstat;

	(void)argc;
	(void)argv;

	printf("The initial value of the printstat is [%d].\n", printstat);

//	printstat = ATOMIC_VAR_INIT(42);
	printstat = 42;

	printf("The initial of the printstat is [%d].\n", printstat);

	printstat = 0;

	printf("The value of the printstat is [%d].\n", printstat);

	printstat = LOCKED;

	printf("The value of the printstat is [%d].\n", printstat);

	printstat = UNLOCKED;

	printf("The value of the printstat is [%d].\n", printstat);

	while (1)
	{
		if (printstat == UNLOCKED)
		{
			printstat = LOCKED;
			break ;
		}
	}
	printf("%s", ANSI_BOLD_BLINK_RED"TEST!!!\n"ANSI_RESET);
	printstat = UNLOCKED;

	return (0);
}
