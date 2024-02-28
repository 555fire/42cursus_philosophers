/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:24:56 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/22 21:29:01 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

#include "include.h"
#include "typedef_enum_struct.h"

/*----prototype declarations of external linkage functions----*/

/*-----cores----*/
/* -----main.c----*/
int			main(int argc, char **argv);


/* -----validate_input----*/
/*  -----validate_input.c----*/
t_funcstat	validate_input(const size_t argc, char **const argv);
/*  -----validate_input_helper.c----*/
t_funcstat	validate_input_value(const size_t argc, char **const argv);


/* -----set_data----*/
/*  -----set_input.c----*/
void		set_input(t_input *const input, const size_t argc, char **const argv);
/*  -----set_data.c----*/
/*	sets data in t_data structure variable.	*/
t_funcstat	set_data(t_data *const d, const size_t argc, char **const argv);


/* -----create_threads.c----*/
t_funcstat	create_threads(t_data *d, const size_t n_philo,
	t_personal **const p_arr, pthread_t **const thread_arr);


/* -----thread_routine----*/
/*  -----philo_routine.c----*/
void		*philo_routine(void *passed_arg_in_the_form_of_void_ptr);
/*  -----monitor_routine.c----*/
void		*monitor_routine(void *passed_arg_in_the_form_of_void_ptr);


/* -----clean resources.c----*/
void		clean_resources(t_data *d);
void		free_heaps(t_personal *p_arr, pthread_t *thread_arr,
	pthread_mutex_t *mutexfork_arr, t_data *d);


/* -----handle_time----*/
/*  -----handle_time.c----*/
t_funcstat	get_usec_time(time_t *const time);
t_funcstat	wait_for_certain_time(_Atomic t_printstat *printstat,
	const time_t certain_time);
t_funcstat	wait_until_target_time(_Atomic t_printstat *printstat,
	const time_t target_time);


/* -----print----*/
/*  -----print_stats.c----*/
void		lock_printstat(_Atomic t_printstat *printstat);
void		unlock_printstat(_Atomic t_printstat *printstat);

void		putstr_atomic(_Atomic t_printstat *printstat, const char *s);
void		putstr_stderr_atomic(_Atomic t_printstat *printstat, const char *s);

// void		atomic_print_ansi_bold_red(t_data *d, const char *s);
// void		set_and_print_err(t_data *d, t_errstat errstat, const char *s);

t_funcstat	print_philostat(const t_personal *const own_p, const t_philostat philostat);
t_funcstat	print_simustat(const t_personal *const own_p, const t_simustat simustat);



/*-----utils----*/
/* -----handle_heap.c----*/
void		*ft_calloc(size_t size, size_t count);
// void		*ft_calloc_with_d(size_t size, size_t count, t_data *const d);
void		free_safely(void *mem);
/* -----handle_string.c----*/
size_t		ft_strlen(const char *s);
size_t		ft_atoi(const char *s);
/* -----print_string.c----*/
void		putstr(const char *s);
void		putstr_stderr(const char *s);

#endif
