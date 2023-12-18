/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:54:29 by mamiyaza          #+#    #+#             */
/*   Updated: 2023/12/18 09:37:21 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*----include directives----*/
/* ----include standard libraries----*/
# include <stdlib.h>
# include <stdio.h>		/*	header for "perror".			*/
# include <string.h>	/*	header for "memset".			*/
# include <unistd.h>	/*	header for "sleep", "usleep".	*/
# include <limits.h>
# include <errno.h>
# include <sys/time.h>	/*	header for "gettimeofday".		*/
# include <pthread.h>	/*	header for "pthread_create",
							"pthread_join", "pthread_mutex_init",
							"pthread_mutex_destroy".		*/
# include <stdatomic.h>	/*	header for "_Atomic".			*/

/*----macroinstructions(macros)----*/
/* -----function-like macros----*/
/*  -----function-like macros for debugging----*/
# define __DEBUG_PRINT_LOOP_COUNT__(d, loop_count) lock_printstat(d); printf(" %10s  [loop_count:"ANSI_BOLD_BLINK"%8zu"ANSI_RESET"]\n", __func__, loop_count); fflush(stdout); unlock_printstat(d)

# define __DEBUG_PRINT_SUCCEEDED__(d) lock_printstat(d); printf("\n<%s succeeded!>%d\n", __func__, __LINE__); fflush(stdout); unlock_printstat(d)
# define __DEBUG_PRINT_WAITS__(d) lock_printstat(d); printf("\n<%s is still waiting...>%d\n", __func__, __LINE__); fflush(stdout); unlock_printstat(d)
# define __DEBUG_PRINT_FAILED__(d) lock_printstat(d); printf("\n<%s failed...>%d\n", __func__, __LINE__); fflush(stdout); unlock_printstat(d)

# define __DEBUG_PRINT_SIMUSTART__() printf("----------Now simulation has started.---------\n"); fflush(stdout)
# define __DEBUG_PRINT_SIMUEND__() printf("----------Now simulation is over.---------\n\n"); fflush(stdout)

# define __DEBUG_PRINT_TARGET_TIME__(d, target_time) lock_printstat(d); printf("[   target_time :%16ld]\n", target_time); fflush(stdout); unlock_printstat(d)
# define __DEBUG_PRINT_DIFF_TIME__(d, cur_time, target_time) lock_printstat(d); printf("[(target-cur)/2 :%16ld]%s|%d\n", target_time - cur_time, __func__, __LINE__); fflush(stdout); unlock_printstat(d)

//# define __DEBUG_PRINT_THREAD_INFO__(d, own_p) lock_printstat(d); printf("\n"); fflush(stdout); if(own_p->threadrole==ONE_OF_PHILOS) {printf("["ANSI_BOLD_BACK_MAGENTA"ONE_OF_PHILOS"ANSI_RESET); fflush(stdout);} else {printf("["ANSI_BOLD_BACK_MAGENTA"A_MONITOR"ANSI_RESET"    "); fflush(stdout);} printf("  :%zu,", (own_p)->philo_i); fflush(stdout); printf(ANSI_BOLD_CYAN"%d"ANSI_RESET", ", __LINE__); fflush(stdout); if (!(own_p)->philostat) {printf(ANSI_BOLD_BACK_YELLOW"%u"ANSI_RESET, (own_p)->philostat); fflush(stdout);} else {printf(ANSI_BOLD_BLINK_BACK_BLUE"%u"ANSI_RESET, (own_p)->philostat); fflush(stdout);} printf("\n\n"); fflush(stdout); unlock_printstat(d)
# define __DEBUG_PRINT_THREAD_INFO__(d, own_p) lock_printstat(d); if(own_p->threadrole==ONE_OF_PHILOS) {printf("["ANSI_BOLD_BACK_MAGENTA"ONE_OF_PHILOS"ANSI_RESET); fflush(stdout);} else {printf("["ANSI_BOLD_BACK_MAGENTA"A_MONITOR"ANSI_RESET"    "); fflush(stdout);} printf("  :%zu,", (own_p)->philo_i); fflush(stdout); printf(ANSI_BOLD_CYAN"%d"ANSI_RESET", ", __LINE__); fflush(stdout); if (!(own_p)->philostat) {printf(ANSI_BOLD_BACK_YELLOW"%u"ANSI_RESET"\n", (own_p)->philostat); fflush(stdout);} else {printf(ANSI_BOLD_BLINK_BACK_BLUE"%u"ANSI_RESET"\n", (own_p)->philostat); fflush(stdout);} unlock_printstat(d)

# define __DEBUG__(d) lock_printstat(d); printf("["ANSI_BOLD_GREEN"%17s"ANSI_BOLD_CYAN"%3d"ANSI_RESET", "ANSI_BOLD_YELLOW"%-22s"ANSI_RESET" ", __func__, __LINE__, __FILE__); fflush(stdout); if (!errno) {printf("errno:"ANSI_BOLD"%d"ANSI_RESET" ", errno); fflush(stdout);} else {printf("errno:"ANSI_BOLD_BLINK_RED"%d"ANSI_RESET" ", errno); fflush(stdout);} if (!d->errstat) {printf("errstat:"ANSI_BOLD"%d"ANSI_RESET, d->errstat); fflush(stdout);} else {printf("errstat:"ANSI_BOLD_BLINK_RED"%d"ANSI_RESET, d->errstat); fflush(stdout);} printf("]\n"); fflush(stdout); unlock_printstat(d)
// # define __DEBUG_PRINT_LOOP_COUNT__(loop_count) printf(" %10s  [loop_count:"ANSI_BOLD_BLINK"%8zu"ANSI_RESET"]\n", __func__, loop_count); fflush(stdout)
//
// # define __DEBUG_PRINT_SUCCEEDED__() printf("\n<%s succeeded!>%d\n", __func__, __LINE__); fflush(stdout)
// # define __DEBUG_PRINT_WAITS__() printf("\n<%s is still waiting...>%d\n", __func__, __LINE__); fflush(stdout)
// # define __DEBUG_PRINT_FAILED__() printf("\n<%s failed...>%d\n", __func__, __LINE__); fflush(stdout)
//
// # define __DEBUG_PRINT_SIMUSTART__() printf("----------Now simulation has started.---------\n"); fflush(stdout)
// # define __DEBUG_PRINT_SIMUEND__() printf("----------Now simulation is over.---------\n\n"); fflush(stdout)
//
// # define __DEBUG_PRINT_TARGET_TIME__(target_time) printf("[   target_time :%16ld]\n", target_time); fflush(stdout)
// # define __DEBUG_PRINT_DIFF_TIME__(cur_time, target_time) printf("[(target-cur)/2 :%16ld]%s|%d\n", target_time - cur_time, __func__, __LINE__); fflush(stdout)
//
// # define __DEBUG_PRINT_THREAD_INFO__(own_p) printf("\n"); fflush(stdout); if(own_p->threadrole==ONE_OF_PHILOS) {printf("["ANSI_BOLD_BACK_MAGENTA"ONE_OF_PHILOS"ANSI_RESET); fflush(stdout);} else {printf("["ANSI_BOLD_BACK_MAGENTA"A_MONITOR"ANSI_RESET"    "); fflush(stdout);} printf("  :%zu,", (own_p)->philo_i); fflush(stdout); printf(ANSI_BOLD_CYAN"%d"ANSI_RESET", ", __LINE__); fflush(stdout); if (!(own_p)->philostat) {printf(ANSI_BOLD_BACK_YELLOW"%u"ANSI_RESET, (own_p)->philostat); fflush(stdout);} else {printf(ANSI_BOLD_BLINK_BACK_BLUE"%u"ANSI_RESET, (own_p)->philostat); fflush(stdout);} printf("\n\n"); fflush(stdout)
//
// # define __DEBUG__(d) printf("["ANSI_BOLD_GREEN"%17s"ANSI_BOLD_CYAN"%3d"ANSI_RESET", "ANSI_BOLD_YELLOW"%-22s"ANSI_RESET" ", __func__, __LINE__, __FILE__); fflush(stdout); if (!errno) {printf("errno:"ANSI_BOLD"%d"ANSI_RESET" ", errno); fflush(stdout);} else {printf("errno:"ANSI_BOLD_BLINK_RED"%d"ANSI_RESET" ", errno); fflush(stdout);} if (!d->errstat) {printf("errstat:"ANSI_BOLD"%d"ANSI_RESET, d->errstat); fflush(stdout);} else {printf("errstat:"ANSI_BOLD_BLINK_RED"%d"ANSI_RESET, d->errstat); fflush(stdout);} printf("]\n"); fflush(stdout)

/* -----object-like macros----*/

/*  -----object-like macro for ANSI escape code----*/
# define ANSI_BOLD "\033[1m"
# define ANSI_BOLD_BLINK "\033[1;5m"

# define ANSI_BOLD_RED "\033[1;31m"
# define ANSI_BOLD_BLINK_RED "\033[1;5;31m"

# define ANSI_BOLD_GREEN "\033[1;32m"
# define ANSI_BOLD_BACK_GREEN "\033[1;42m"

# define ANSI_BOLD_YELLOW "\033[1;33m"
# define ANSI_BOLD_BACK_YELLOW "\033[1;43m"

# define ANSI_BOLD_BLINK_BACK_BLUE "\033[1;5;44m"

# define ANSI_BOLD_CYAN "\033[1;36m"
# define ANSI_BOLD_BLINK_CYAN "\033[1;5;36m"

# define ANSI_BOLD_BLUE "\033[1;34m"

# define ANSI_BOLD_BLINK_MAGENTA "\033[1;5;35m"
# define ANSI_BOLD_BACK_MAGENTA "\033[1;45m"
# define ANSI_BOLD_BLINK_BACK_MAGENTA "\033[1;5;45m"

# define ANSI_RESET "\033[0m"

/*  -----object-like macros for error messages----*/
# define ERRMSG_ARGC "\033[1;31mUSAGE:\n\
\tThis executable file \"philo\" takes 4 or 5 arguments.\n\
\tEach arguments refers \"number_of_philosophers\", \"time_to_die\"(in milliseconds),\n\
\t\"time_to_eat\"(in milliseconds) and \"time_to_sleep\"(in milliseconds).\n\
\tIf you add 5th argument, it represents \"number_of_times_each_philosopher_must_eat\".\n\033[0m"
# define ERRMSG_ARGV "\033[1;31mUSAGE:\n\
\tThe range of possible values is as follows:\n\
\t\"number_of_philo\" : integer from 1 to 200.\n\
\tother arguments : integer from 60 to INT_MAX\n\033[m"
# define ERRMSG_CALLOC_ARGS "\terror: values of arguments of calloc is invalid!\n"
# define ERRMSG_MALLOC "\tfatal error: malloc failed.\n"
# define ERRMSG_THREAD_CREATE "\tfatal error: pthread_create failed.\n"
# define ERRMSG_MUTEX_INIT "\tfatal error: pthread_mutex_init failed.\n"
# define ERRMSG_MUTEX_LOCK "\tfatal error: pthread_mutex_lock failed.\n"
# define ERRMSG_MUTEX_UNLOCK "\tfatal error: pthread_mutex_unlock failed.\n"
# define ERRMSG_GETTIMEOFDAY "\tfatal error: gettimeofday failed.\n"
# define ERRMSG_USLEEP "\tfatal error: usleep failed.\n"
# define ERRMSG_THREAD_JOIN "\tfatal error: pthread_join failed.\n"
# define ERRMSG_MUTEX_DESTROY "\tfatal error: pthread_mutex_destroy failed.\n"
# define ERRMSG_PRINTSTAT "\terror: printstat\n"

/*  -----object-like macros for standard messages----*/
# define SPC " "
# define MSG_DIED " died.\n"
# define MSG_TOOKFORK " has taken a fork.\n"
# define MSG_EATING " is eating.\n"
# define MSG_SLEEPING " is sleeping.\n"
# define MSG_THINKING " is thinking.\n"

/*  -----other object-like macros----*/
# define NUM_OF_MONITORS 1

/*----structures, enumerations, unions and typedefs----*/
typedef enum e_errstat				t_errstat;
enum e_errstat
{
	NO_ERROR,
	ARGC_ERROR,
	ARGV_ERROR,
	CALLOC_ARGS_ERROR,
	MALLOC_ERROR,
	MUTEX_INIT_ERROR,
	GETTIMEOFDAY_ERROR,
	THREAD_CREATE_ERROR,
	MUTEX_LOCK_ERROR,
	MUTEX_UNLOCK_ERROR,
	PRINTSTAT_ERROR,
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
	UNLOCKED,
	LOCKED,
};
/* In the beginning, the status is set in "unlocked".*/

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

	pthread_t			*thread_arr;

	pthread_mutex_t		*mutexfork_arr;
	_Atomic t_printstat	printstat;

	_Atomic t_errstat	errstat;
	t_simustat			simustat;

	time_t				start_time;
};

/*
	p_arr is array of "t_personal" and need to know own "philo_id".
	So each philo has to have own "t_personal" data.
*/

/*----prototype declarations of external linkage functions----*/
/* -----main.c----*/

/* -----set_data.c----*/
t_data		*set_data(t_data *d, size_t argc, char **argv);

/* -----get_time_in_microsec.c----*/
time_t		get_usec_time(t_data *d);
t_funcstat	wait_precise_time(t_data *d, time_t target_time);

/* -----create_threads.c----*/
void		create_threads(t_data *d);

/* -----philo_routine.c----*/
void		*philo_routine(void *passed_arg_in_the_form_of_void_ptr);

/* -----monitor_routine.c----*/
void		*monitor_routine(void *passed_arg_in_the_form_of_void_ptr);

/* -----clean resources.c----*/
void		clean_resources(t_data *d);

/* -----print_stats.c----*/
void		lock_printstat(t_data *d);
void		unlock_printstat(t_data *d);
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
