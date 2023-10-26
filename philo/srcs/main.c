#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	d = NULL;

//	__DEBUG_RING_SINGLE_BELL_AND_PRINT_THE_BELL_RANG__();
//	__DEBUG_PRINT_THE_BELL_RANG__();
//	__DEBUG_RING_SINGLE_BELL__();
//	__DEBUG_PRINT_THE_BELL_RANG__();

	d = set_data(d, argc, argv);

	__DEBUG__(d);

	create_threads(d);

	__DEBUG__(d);

	clean_resources(d);

	__DEBUG__(d);

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