/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_objt.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:06:22 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/03/04 20:50:17 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_OBJT_H
# define MACRO_OBJT_H

/*----definitions of macroinstruction(macro)----*/
/*  -----object-like macros for ANSI escape code----*/
# define ANSI_BOLD "\033[1m"
# define ANSI_BOLD_BLINK "\033[1;5m"

# define ANSI_BOLD_RED "\033[1;31m"
# define ANSI_BOLD_BLINK_RED "\033[1;5;31m"

# define ANSI_BOLD_GREEN "\033[1;32m"
# define ANSI_BOLD_BACK_GREEN "\033[1;42m"

# define ANSI_BOLD_YELLOW "\033[1;33m"
# define ANSI_BOLD_BACK_YELLOW "\033[1;43m"

# define ANSI_BOLD_BACK_BLUE "\033[1;44m"
# define ANSI_BOLD_BLINK_BACK_BLUE "\033[1;5;44m"

# define ANSI_BOLD_CYAN "\033[1;36m"
# define ANSI_BOLD_BLINK_CYAN "\033[1;5;36m"

# define ANSI_BOLD_BLUE "\033[1;34m"

# define ANSI_BOLD_BLINK_MAGENTA "\033[1;5;35m"
# define ANSI_BOLD_BACK_MAGENTA "\033[1;45m"
# define ANSI_BOLD_BLINK_BACK_MAGENTA "\033[1;5;45m"

# define ANSI_RESET "\033[0m"

/*  -----object-like macros for error message----*/
# define ERRMSG_NUM_OF_INPUTS "USAGE (1):\n\
\tThis executable file \"philo\" takes 4 or 5 arguments; each arguments refers\n\
\t\"number_of_philosophers\", \"time_to_die\"(in milliseconds),\n\
\t\"time_to_eat\"(in milliseconds) and \"time_to_sleep\"(in milliseconds).\n\
\tIf you add 5th argument, it represents \
\"number_of_times_each_philosopher_must_eat\".\n"
# define ERRMSG_INPUT_VALUE "USAGE (2):\n\
\tThe range of values each arguments can take is as follows:\n\
\t\"number_of_philo\":\t\t\t\tan integer value between 1 and 200.\n\
\t\"time_to_die\"(in milliseconds), \"time_to_eat\"(in milliseconds)\n\
\t   and \"time_to_sleep\"(in milliseconds):\tan integer value between 60 and INT_MAX.\n\
\t\"number_of_times_each_philosophers_must_eat\":\tan integer value \
between 1 and INT_MAX.\n"
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

/*  -----object-like macros for debug message----*/
# define DBGMSG_LOCKED "\tLOCKED\n"
# define DBGMSG_UNLOCKED "\tUNLOCKED\n"

/*  -----object-like macros for normal message----*/
# define SPC " "
# define MSG_DIED " died.\n"
# define MSG_TOOKFORK " has taken a fork.\n"
# define MSG_EATING " is eating.\n"
# define MSG_SLEEPING " is sleeping.\n"
# define MSG_THINKING " is thinking.\n"

# define MIN_ARGC 5
# define MAX_ARGC 6

/* -----object-like macros for set_data----*/
# define ARGC_NUM_PHILO 1
# define MIN_NUM_PHILO 1
# define MAX_NUM_PHILO 200

# define MIN_ARGC_TIME_TO_DIE_EAT_SLEEP 2
# define MAX_ARGC_TIME_TO_DIE_EAT_SLEEP 4
# define MIN_TIME_TO_DIE_EAT_SLEEP 60
# define MAX_TIME_TO_DIE_EAT_SLEEP INT_MAX

# define ARGC_NUM_EAT 5
# define MIN_NUM_EAT 1
# define MAX_NUM_EAT INT_MAX

# define NUM_OF_MONITORS 1

# define LAG_TIME_TILL_START_TIME 50000

#endif
