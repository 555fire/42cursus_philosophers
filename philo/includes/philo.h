#ifndef PHILO_H
# define PHILO_H

/*----include directives----*/
/* ----include standard libraries----*/
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>	// header file for "pthread_create",
						// "pthread_join", "pthread_mutex_init",
						// "pthread_mutex_destroy".
# include <sys/time.h>	// header file for "gettimeofday".
# include <string.h>	// header file for "memset".
# include <stdatomic.h>	// header file for "_Atomic".
# include <unistd.h>	// header file for "sleep", "usleep".
# include <errno.h>



/*----macroinstructions(macros)----*/
/*-----object-like macros----*/
/* -----object-like macros for error messages----*/
# define ERRMSG_ARGC "\tUSAGE:\n\
\t\texecutable file \"philo\" needs 4 or 5 positive integer args.\n\
number_of_philosophers, time_to_die, time_to_eat, \
time_to_sleep, [number_of_times_each_philosopher_must_eat].\n"
# define ERRMSG_ARGV "\tRANGE OF VALUE:\n\
\t\tnumber_of_philo : from 1 to 200.\n\
\t\tother arguments : from 60 to INT_MAX\n"
# define ERRMSG_CALLOC_ARGS "\terror: values of arguments of calloc is invalid.\n"
# define ERRMSG_MALLOC "\tfatal error: malloc failed.\n"
# define ERRMSG_THREAD_CREATE "\tfatal error: pthread_create failed.\n"
# define ERRMSG_THREAD_JOIN "\tfatal error: pthread_join failed.\n"
# define ERRMSG_MUTEX_INIT "\tfatal error: pthread_mutex_init failed.\n"
# define ERRMSG_MUTEX_DESTROY "\tfatal error: pthread_mutex_destroy failed.\n"
# define ERRMSG_MUTEX_LOCK "\tfatal error: pthread_mutex_lock failed.\n"
# define ERRMSG_MUTEX_UNLOCK "\tfatal error: pthread_mutex_unlock failed.\n"
# define ERRMSG_GETTIMEOFDAY "\tfatal error: gettimeofday failed.\n"
# define ERRMSG_USLEEP "\tfatal error: usleep failed.\n"

/* -----object-like macros for output messages----*/
# define SPC " "
# define MSG_DIED " died.\n"
# define MSG_TOOKFORK " has taken a fork.\n"
# define MSG_EATING " is eating.\n"
# define MSG_SLEEPING " is sleeping.\n"
# define MSG_THINKING " is thinking.\n"

/* -----object-like macro for ANSI escape code----*/
# define ANSI_BOLD_BLINK_RED "\033[1;5;31m"
# define ANSI_BOLD_BLINK_CYAN "\033[1;5;36m"
# define ANSI_BOLD_BLINK_MAGENTA "\033[1;5;35m"
# define ANSI_BOLD_GREEN "\033[1;32m"
# define ANSI_BOLD_YELLOW "\033[1;33m"
# define ANSI_RESET "\033[0m"

/* -----other object-like macros----*/
# define NUM_OF_MONITORS 1



/*-----function-like macros----*/
/* -----function-like macros for debugging----*/
# define __DEBUG_PRINT_ARGC__(argc) printf("%10s [argc:\033[1;5;36m%3zu\033[m].\n", __func__, argc)
//# define __DEBUG_PRINT_STR__(str) printf("%10s  [str:%3s].\n", __func__, str)
//# define __DEBUG_PRINT_CHR__(c) printf("%10s   [c:%3c].\n", __func__, c)
# define __DEBUG_PRINT_CALLOC_ARGS__(count, size) printf("%10s[count:%zu, size:%zu]\n", __func__, count, size);
//# define __DEBUG_PRINT_NUM__(num) printf("%10s  [num:\033[1;5;36m%3zu\033[m]\n", __func__, num)
# define __DEBUG_PRINT_LOOP_COUNT__(loop_count) printf(" %10s  [loop_count:\033[1;5m%8zu\033[m]\n", __func__, loop_count)

# define __DEBUG_PRINT_SUCCESS__() printf("<%s success!!>", __func__)

# define __DEBUG_PRINT_TIME__(usec_time) printf("[usec_time:%lu]\n", usec_time)

//# define __DEBUG_PRINT_THREAD_INFO__(own_p) if(own_p->threadrole==ONE_OF_PHILOS) printf("[role:\033[1;5;45mONE_OF_PHILOS\033[m"); else printf("[role:\033[1;5;45mA_MONITOR\033[m"); printf(", philo_id:%zu]\n", own_p->philo_i)
# define __DEBUG_PRINT_THREAD_INFO__(own_p) if(own_p->threadrole==ONE_OF_PHILOS) printf("[\033[1;5;45mONE_OF_PHILOS\033[m"); else printf("[\033[1;5;45mA_MONITOR\033[m    "); printf("  :%zu,", (own_p)->philo_i); printf("\033[1;5;36m%d\033[m, ", __LINE__); if (!(own_p)->philostat) printf("\033[1;43m%u\033[m", (own_p)->philostat); else printf("\033[1;5;44m%u\033[m", (own_p)->philostat); printf("\n")

# define __DEBUG_PRINT_ERRSTAT_AND_SIMUSTAT__(d) if (d->errstat == NO_ERROR) printf("NO_ERROR\n"); else if (d->errstat == ARGC_ERROR) printf("%s", ERRMSG_ARGC); else if (d->errstat == ARGV_ERROR) printf("%s", ERRMSG_ARGV); else if (d->errstat == MALLOC_ERROR) printf("%s", ERRMSG_MALLOC); else if (d->errstat == CALLOC_ARGS_ERROR) printf("%s", ERRMSG_CALLOC_ARGS); else if (d->errstat == THREAD_CREATE_ERROR) printf("%s", ERRMSG_THREAD_CREATE); else if (d->errstat == THREAD_JOIN_ERROR) printf("%s", ERRMSG_THREAD_JOIN); else if (d->errstat == MUTEX_INIT_ERROR) printf("%s", ERRMSG_MUTEX_INIT); else if (d->errstat == MUTEX_DESTROY_ERROR) printf("%s", ERRMSG_MUTEX_DESTROY); else if (d->errstat == MUTEX_LOCK_ERROR) printf("%s", ERRMSG_MUTEX_LOCK); else if (d->errstat == MUTEX_UNLOCK_ERROR) printf("%s", ERRMSG_MUTEX_UNLOCK); else if (d->errstat == GETTIMEOFDAY_ERROR) printf("%s", ERRMSG_GETTIMEOFDAY); else if (d->errstat == USLEEP_ERROR) printf("%s", ERRMSG_USLEEP); if (d->simustat == SIMU_LASTS) printf("SIMU_LASTS\n"); else if (d->simustat == ANY_ERROR_HAS_OCCURRED) printf("ANY_ERROR_HAS_OCCURRED\n"); else if (d->simustat == ANYONE_DIED) printf("ANYONE_DIED\n"); else if (d->simustat == REACHED_N_TIMES_MUST_EAT) printf("REACHED_N_TIMES_MUST_EAT\n")

/* ----function-like macro for ringing bell----*/
//# define __DEBUG_RING_SINGLE_BELL_AND_PRINT_THE_BELL_RANG__(void) printf("\033[x07m"); printf("The bell rang!!\n")
//# define __DEBUG_PRINT_THE_BELL_RANG__(void) printf("The bell rang!\n")
//# define __DEBUG_RING_SINGLE_BELL__(void) printf("\033[x07m")

# define __DEBUG__(d) printf("[\033[1;32m%17s\033[5;36m%3d\033[m, \033[;1;33m%-22s\033[m ", __func__, __LINE__, __FILE__); if (!errno) printf("errno:\033[1m%d\033[m ", errno); else printf("errno:\033[1;5;31m%d\033[m ", errno); if (!d->errstat) printf("errstat:\033[1m%d\033[m", d->errstat); else printf("errstat:\033[1;5;31m%d\033[m", d->errstat); printf("]\n")

//# define __DEBUG_THREAD_ROLE_AND_PHILO_ID__(own_p) printf("[\033[1;32m%15s\033[5;36m", __func__, __LINE__); if (!errno) printf(); else printf(); if (!(own_p)->d->errstat) printf(); else printf(); if (!(own_p)->d->simustat) printf(); else printf(); if (!(own_p)->d->philostat) printf(); else printf(); printf("]\n")

//# define __DEBUG_WITH_OWN_P__(d, own_p) printf("\n[\033[1;42m%-18s\033[0;1;5;36m%3d\033[m, \033[1;33m%-22s\033[m errno:\033[1;31m%d\033[m errstat:\033[1;31m%d\033[m]\n	[p_i:%zu] [philo_i:%zu] [rhf_i:%zu] [lhf_i:%zu]\n\n", __func__, __LINE__, __FILE__, errno, d->errstat, (own_p)->p_arr_i, (own_p)->philo_i, (own_p)->rhf_i, (own_p)->lhf_i)
# define __DEBUG_WITH_OWN_P__(d, own_p) printf("[\033[1;42m%17s\033[0;1;5;36m%3d\033[m, \033[1;33m%-22s\033[m", __func__, __LINE__, __FILE__); if (!errno) printf("errno:\033[1m%d\033[m ", errno); else printf("errno:\033[1;5;31m%d\033[m ", errno); if (!d->errstat) printf("errstat:\033[1m%d\033[m]", d->errstat); else printf("errstat:\033[1;5;31m%d\033[m]", d->errstat); printf("\n"); printf("  [p_i:%zu, philo_i:%zu, rhf_i:%zu, lhf_i:%zu]\n", (own_p)->p_arr_i, (own_p)->philo_i, (own_p)->rhf_i, (own_p)->lhf_i)

//# define __DEBUG_WITH_INPUT__(d) printf("[\033[1;42m%-18s\033[0;1;5;36m%3d\033[m, \033[1;43m%-22s\033[m errno:\033[1;31m%d\033[m errstat:\033[1;31m%d\033[m]\n	[n_philo:%zu] [time_to_die:%zu] [time_to_eat:%zu] [time_to_sleep:%zu] [n_times_must_eat:%zu]\n", __func__, __LINE__, __FILE__, errno, d->errstat, d->i.n_philo, d->i.time_to_die, d->i.time_to_eat, d->i.time_to_sleep, d->i.n_times_must_eat)
# define __DEBUG_WITH_INPUT__(d) printf("[\033[1;42m%17s\033[0;1;5;36m%3d\033[m, \033[1;33m%-22s\033[m", __func__, __LINE__, __FILE__); if (!errno) printf("errno:\033[1m%d\033[m ", errno); else printf("errno:\033[1;5;31m%d\033[m ", errno); if (!d->errstat) printf("errstat:\033[1m%d\033[m]", d->errstat); else printf("errstat:\033[1;5;31m%d\033[m]", d->errstat); printf("\n"); printf("  [n_philo:%zu, time_to_die:%zu, time_to_eat:%zu, time_to_sleep:%zu, n_times_must_eat:%zu]\n", d->i.n_philo, d->i.time_to_die, d->i.time_to_eat, d->i.time_to_sleep, d->i.n_times_must_eat)



/*----structures, enumerations, unions and typedefs----*/
typedef enum e_errstat				t_errstat;
enum e_errstat
{
	NO_ERROR,
	ARGC_ERROR,
	ARGV_ERROR,
	CALLOC_ARGS_ERROR,
	MALLOC_ERROR,
	THREAD_CREATE_ERROR,
	MUTEX_INIT_ERROR,
	MUTEX_LOCK_ERROR,
	MUTEX_UNLOCK_ERROR,
	GETTIMEOFDAY_ERROR,
	USLEEP_ERROR,
	THREAD_JOIN_ERROR,
	MUTEX_DESTROY_ERROR,
};

typedef enum e_simustat				t_simustat;
enum e_simustat
{
	SIMU_LASTS,
	ANY_ERROR_HAS_OCCURRED,
	ANYONE_DIED,
	REACHED_N_TIMES_MUST_EAT,
};

typedef enum e_philostat			t_philostat;
enum e_philostat
{
	WAITING_FOR_TAKINGFORK,
	HASTOOKFORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
};

typedef enum e_funcstat				t_funcstat;
enum e_funcstat
{
	SUCCEEDED,
	FAILED,
};

typedef enum e_printstat			t_printstat;
enum e_printstat
{
	LOCKED,
	UNLOCKED,
};

typedef enum e_threadrole			t_threadrole;
enum e_threadrole
{
	A_MONITOR,
	ONE_OF_PHILOS,
};

typedef enum e_has_everyone_reached	t_has_everyone_reached;
enum e_have_everyone_reached
{
	HASNT_REACHED,
	HAS_REACHED,
};

typedef enum e_did_anyone_die		t_did_anyone_die;
enum e_did_anyone_die
{
	DIDNT_DIE,
	DIED_OR_AN_ERROR_HAS_OCCURRED,
};

typedef struct s_input				t_input;
struct s_input
{
	size_t	n_philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	n_times_must_eat;
};

typedef struct s_personal			t_personal;
typedef struct s_data				t_data;

struct s_personal
{
	t_data			*d;

	size_t			p_arr_i;
	t_threadrole	threadrole;

	size_t			philo_i;
	size_t			rhf_i;
	size_t			lhf_i;

	t_philostat		philostat;

	time_t			last_eat_time;
	size_t			n_times_eaten;
};

struct s_data
{
	t_input				i;
	t_personal			*p_arr;
//	p_arr is array of "t_personal" and need to know own "philo_id".
//	So each philo has to have own "t_personal" data.

	pthread_t			*thread_arr;

	pthread_mutex_t		*mutexfork_arr;
	_Atomic t_printstat	printstat;

	_Atomic t_errstat	errstat;
	t_simustat			simustat;

	time_t				start_time;
};



/*----prototype declarations of non-static function----*/
/* -----main.c----*/

/* -----set_data.c----*/
t_data		*set_data(t_data *d, size_t argc, char **argv);

/* -----get_time_in_microsec.c----*/
time_t		get_usec_time(t_data *d);
t_funcstat	wait_precise_time(t_data *d, time_t target_time);

/* -----create_threads.c----*/
void		create_threads(t_data *d);

/* -----philo_routine.c----*/
void 		*philo_routine(void *passed_arg_in_the_form_of_void_ptr);

/* -----monitor_routine.c----*/
void		*monitor_routine(void *passed_arg_in_the_form_of_void_ptr);

/* -----clean resources.c----*/
void		clean_resources(t_data *d);

/* -----print_stats.c----*/
void		print_errstat_without_d(t_errstat errstat);
void		print_errstat(t_data *d, t_errstat errstat);
t_funcstat	print_philostat(t_personal *own_p, t_philostat philostat);
t_funcstat	print_simustat(t_personal *own_p, t_simustat simustat);

/* -----utils.c----*/
size_t		ph_atoi(char *s, t_data *d);
void		*ph_calloc_without_d(size_t size, size_t count);
void		*ph_calloc(size_t size, size_t count, t_data *d);
void		free_safely(void *mem);

#endif
