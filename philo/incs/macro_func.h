/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_func.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:04:38 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/20 22:13:34 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_FUNC_H
# define MACRO_FUNC_H

/*----definitions of macroinstructions(macros)----*/
/* -----definitions of function-like macros----*/
/*  -----function-like macros for debug----*/
# define __DEBUG_PRINT_LOOP_COUNT__(d, loop_count) lock_printstat(d); printf(" %10s  [loop_count:"ANSI_BOLD"%8zu"ANSI_RESET"]\n", __func__, loop_count); fflush(stdout); unlock_printstat(d)

# define __DEBUG_PRINT_SUCCEEDED__(d) lock_printstat(d); printf("<%s succeeded>%d\n", __func__, __LINE__); fflush(stdout); unlock_printstat(d)
# define __DEBUG_PRINT_WAITS__(d) lock_printstat(d); printf("<%s is waiting>%d\n", __func__, __LINE__); fflush(stdout); unlock_printstat(d)
# define __DEBUG_PRINT_FAILED__(d) lock_printstat(d); printf("<%s failed>%d\n", __func__, __LINE__); fflush(stdout); unlock_printstat(d)

# define __DEBUG_PRINT_SIMUSTART__(t) fflush(stdout); printf("----------Now simulation has started.---------\n"); fflush(stdout)
# define __DEBUG_PRINT_SIMUEND__() fflush(stdout); printf("----------Now simulation is over.---------\n\n"); fflush(stdout)

# define __DEBUG_PRINT_TARGET_TIME__(d, target_time) lock_printstat(d); printf("[   target_time :%16ld]\n", target_time); fflush(stdout); unlock_printstat(d)
# define __DEBUG_PRINT_DIFF_TIME__(d, cur_time, target_time) lock_printstat(d); printf("[(target-cur)/2 :%16ld]%s|%d\n", target_time - cur_time, __func__, __LINE__); fflush(stdout); unlock_printstat(d)

//# define __DEBUG_PRINT_THREAD_INFO__(d, own_p) lock_printstat(d); if(own_p->threadrole==ONE_OF_PHILOS) {printf("  "ANSI_BOLD_BACK_MAGENTA"PHILO"ANSI_RESET); fflush(stdout);} else {printf(ANSI_BOLD_BACK_MAGENTA"MONITOR"ANSI_RESET); fflush(stdout);} printf("%zu, ", (own_p)->philo_i); fflush(stdout); printf(ANSI_BOLD_CYAN"%d"ANSI_RESET", ", __LINE__); fflush(stdout); if (!(own_p)->philostat) {printf(ANSI_BOLD_BACK_YELLOW"%u"ANSI_RESET"\n", (own_p)->philostat); fflush(stdout);} else {printf(ANSI_BOLD_BLINK_BACK_BLUE"%u"ANSI_RESET"\n", (own_p)->philostat); fflush(stdout);} unlock_printstat(d)
# define __DEBUG_PRINT_THREAD_INFO__(d, own_p) lock_printstat(&d->printstat); if(own_p->threadrole==ONE_OF_PHILOS) {printf("["ANSI_BOLD_BACK_MAGENTA"PHI"ANSI_RESET);} else {printf("["ANSI_BOLD_BACK_MAGENTA"MON"ANSI_RESET);} fflush(stdout); printf("%zu, ", (own_p)->philo_i); fflush(stdout); if (!(own_p)->philostat) {printf(ANSI_BOLD_BACK_YELLOW"%u"ANSI_RESET" ", (own_p)->philostat);} else {printf(ANSI_BOLD_BACK_BLUE"%u"ANSI_RESET" ", (own_p)->philostat);} fflush(stdout); printf(ANSI_BOLD_GREEN"%26s"ANSI_BOLD_CYAN" %d"ANSI_RESET", ", __func__, __LINE__); fflush(stdout); if (!errno) {printf("errno:"ANSI_BOLD"%d"ANSI_RESET" ", errno); fflush(stdout);} else {printf("errno:"ANSI_BOLD_BLINK_RED"%d"ANSI_RESET" ", errno); fflush(stdout);} if (!d->errstat) {printf("errstat:"ANSI_BOLD"%d"ANSI_RESET, d->errstat); fflush(stdout);} else {printf("errstat:"ANSI_BOLD_BLINK_RED"%d"ANSI_RESET, d->errstat); fflush(stdout);} printf("]\n"); fflush(stdout); unlock_printstat(&d->printstat)

# define __DEBUG__(d) lock_printstat(&d->printstat); printf("["ANSI_BOLD_GREEN"%34s"ANSI_BOLD_CYAN"%3d"ANSI_RESET", "ANSI_BOLD_YELLOW"%-22s"ANSI_RESET" ", __func__, __LINE__, __FILE__); fflush(stdout); if (!errno) {printf("errno:"ANSI_BOLD"%d"ANSI_RESET" ", errno); fflush(stdout);} else {printf("errno:"ANSI_BOLD_BLINK_RED"%d"ANSI_RESET" ", errno); fflush(stdout);} if (!d->errstat) {printf("errstat:"ANSI_BOLD"%d"ANSI_RESET, d->errstat); fflush(stdout);} else {printf("errstat:"ANSI_BOLD_BLINK_RED"%d"ANSI_RESET, d->errstat); fflush(stdout);} printf("]\n"); fflush(stdout); unlock_printstat(&d->printstat)


// # define __DEBUG_PRINT_LOOP_COUNT__(d, loop_count) lock_printstat(d); printf(" %10s  [loop_count:"ANSI_BOLD"%8zu"ANSI_RESET"]\n", __func__, loop_count); fflush(stdout); unlock_printstat(d)

// # define __DEBUG_PRINT_SUCCEEDED__(d) lock_printstat(d); printf("<%s succeeded>%d\n", __func__, __LINE__); fflush(stdout); unlock_printstat(d)
// # define __DEBUG_PRINT_WAITS__(d) lock_printstat(d); printf("<%s is waiting>%d\n", __func__, __LINE__); fflush(stdout); unlock_printstat(d)
// # define __DEBUG_PRINT_FAILED__(d) lock_printstat(d); printf("<%s failed>%d\n", __func__, __LINE__); fflush(stdout); unlock_printstat(d)

// # define __DEBUG_PRINT_SIMUSTART__(t) fflush(stdout); printf("----------Now simulation has started.---------\n"); fflush(stdout)
// # define __DEBUG_PRINT_SIMUEND__() fflush(stdout); printf("----------Now simulation is over.---------\n\n"); fflush(stdout)

// # define __DEBUG_PRINT_TARGET_TIME__(d, target_time) lock_printstat(d); printf("[   target_time :%16ld]\n", target_time); fflush(stdout); unlock_printstat(d)
// # define __DEBUG_PRINT_DIFF_TIME__(d, cur_time, target_time) lock_printstat(d); printf("[(target-cur)/2 :%16ld]%s|%d\n", target_time - cur_time, __func__, __LINE__); fflush(stdout); unlock_printstat(d)

// //# define __DEBUG_PRINT_THREAD_INFO__(d, own_p) lock_printstat(d); if(own_p->threadrole==ONE_OF_PHILOS) {printf("  "ANSI_BOLD_BACK_MAGENTA"PHILO"ANSI_RESET); fflush(stdout);} else {printf(ANSI_BOLD_BACK_MAGENTA"MONITOR"ANSI_RESET); fflush(stdout);} printf("%zu, ", (own_p)->philo_i); fflush(stdout); printf(ANSI_BOLD_CYAN"%d"ANSI_RESET", ", __LINE__); fflush(stdout); if (!(own_p)->philostat) {printf(ANSI_BOLD_BACK_YELLOW"%u"ANSI_RESET"\n", (own_p)->philostat); fflush(stdout);} else {printf(ANSI_BOLD_BLINK_BACK_BLUE"%u"ANSI_RESET"\n", (own_p)->philostat); fflush(stdout);} unlock_printstat(d)
// # define __DEBUG_PRINT_THREAD_INFO__(d, own_p) lock_printstat(d); if(own_p->threadrole==ONE_OF_PHILOS) {printf("["ANSI_BOLD_BACK_MAGENTA"PHI"ANSI_RESET);} else {printf("["ANSI_BOLD_BACK_MAGENTA"MON"ANSI_RESET);} fflush(stdout); printf("%zu, ", (own_p)->philo_i); fflush(stdout); if (!(own_p)->philostat) {printf(ANSI_BOLD_BACK_YELLOW"%u"ANSI_RESET" ", (own_p)->philostat);} else {printf(ANSI_BOLD_BACK_BLUE"%u"ANSI_RESET" ", (own_p)->philostat);} fflush(stdout); printf(ANSI_BOLD_GREEN"%26s"ANSI_BOLD_CYAN" %d"ANSI_RESET", ", __func__, __LINE__); fflush(stdout); if (!errno) {printf("errno:"ANSI_BOLD"%d"ANSI_RESET" ", errno); fflush(stdout);} else {printf("errno:"ANSI_BOLD_BLINK_RED"%d"ANSI_RESET" ", errno); fflush(stdout);} if (!d->errstat) {printf("errstat:"ANSI_BOLD"%d"ANSI_RESET, d->errstat); fflush(stdout);} else {printf("errstat:"ANSI_BOLD_BLINK_RED"%d"ANSI_RESET, d->errstat); fflush(stdout);} printf("]\n"); fflush(stdout); unlock_printstat(d)

// # define __DEBUG__(d) lock_printstat(d); printf("["ANSI_BOLD_GREEN"%34s"ANSI_BOLD_CYAN"%3d"ANSI_RESET", "ANSI_BOLD_YELLOW"%-22s"ANSI_RESET" ", __func__, __LINE__, __FILE__); fflush(stdout); if (!errno) {printf("errno:"ANSI_BOLD"%d"ANSI_RESET" ", errno); fflush(stdout);} else {printf("errno:"ANSI_BOLD_BLINK_RED"%d"ANSI_RESET" ", errno); fflush(stdout);} if (!d->errstat) {printf("errstat:"ANSI_BOLD"%d"ANSI_RESET, d->errstat); fflush(stdout);} else {printf("errstat:"ANSI_BOLD_BLINK_RED"%d"ANSI_RESET, d->errstat); fflush(stdout);} printf("]\n"); fflush(stdout); unlock_printstat(d)

#endif
