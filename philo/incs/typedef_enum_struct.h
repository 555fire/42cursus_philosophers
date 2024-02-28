/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef_enum_struct.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:14:53 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/20 20:51:42 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_STRUCT_ENUM_H
# define TYPEDEF_STRUCT_ENUM_H

# include "include.h" // for size_t, pthread_t, pthread_mutex_t, time_t

/* ----definitions of typedefs, structures,
						enumerations and unions----*/

/*  ----typedefs----*/
typedef enum e_errstat				t_errstat;
typedef enum e_simustat				t_simustat;
typedef enum e_philostat			t_philostat;
typedef enum e_funcstat				t_funcstat;
typedef enum e_printstat			t_printstat;
typedef enum e_threadrole			t_threadrole;
typedef enum e_has_everyone_reached	t_has_everyone_reached;
typedef enum e_did_anyone_die		t_did_anyone_die;

typedef struct s_input				t_input;
typedef struct s_personal			t_personal;
typedef struct s_data				t_data;

/*  ----enums----*/
typedef enum e_errstat				t_errstat;
enum e_errstat
{
	NO_ERROR = 0,
	NUM_OF_INPUTS_ERROR = 1001,
	INPUT_VALUE_ERROR = 1002,
	CALLOC_ARGS_ERROR = 2001,
	MALLOC_ERROR = 2002,
	MUTEX_INIT_ERROR = 3001,
	GETTIMEOFDAY_ERROR = 3002,
	THREAD_CREATE_ERROR = 3003,
	MUTEX_LOCK_ERROR = 3004,
	MUTEX_UNLOCK_ERROR = 3005,
	PRINTSTAT_ERROR = 3006,
	USLEEP_ERROR = 3007,
	THREAD_JOIN_ERROR = 3008,
	MUTEX_DESTROY_ERROR = 3009,
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
	SUCCESS,
	FAIL,
};

/*
	In the beginning, the status is set in "unlocked".
*/
typedef enum e_printstat			t_printstat;
enum e_printstat
{
	UNLOCKED,
	LOCKED,
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
	HASNT_DIED,
	HAS_DIED,
};

/*  ----structures----*/
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

/*
	p_arr is array of "t_personal" and need to know own "philo_id".
	So each philo has to have own "t_personal" data.
*/
typedef struct s_data				t_data;
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

#endif
