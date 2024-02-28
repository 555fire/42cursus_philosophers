# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    var_compilation.mk                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 20:23:42 by mamiyaza          #+#    #+#              #
#    Updated: 2024/02/22 22:00:58 by mamiyaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# variable definition
#  variable definition for compilation

NAME := philo


SRCS_DIR := srcs/

CORES_DIR := cores/
UTILS_DIR := utils/

HANDLE_TIME_DIR := handle_time/
PRINT_DIR := print/
SET_DATA_DIR := set_data/
THREAD_ROUTINE_DIR := thread_routine/
VALIDATE_INPUT_DIR := validate_input/

SRCS :=	$(CORES_DIR)$(HANDLE_TIME_DIR)handle_time.c \
		$(CORES_DIR)$(PRINT_DIR)print_stats.c \
		$(CORES_DIR)$(SET_DATA_DIR)set_data.c \
		$(CORES_DIR)$(SET_DATA_DIR)set_input.c \
		$(CORES_DIR)$(THREAD_ROUTINE_DIR)monitor_routine.c \
		$(CORES_DIR)$(THREAD_ROUTINE_DIR)philo_routine.c \
		$(CORES_DIR)$(VALIDATE_INPUT_DIR)validate_input_helper.c \
		$(CORES_DIR)$(VALIDATE_INPUT_DIR)validate_input.c \
		$(CORES_DIR)create_threads.c \
		$(CORES_DIR)clean_resources.c \
		$(CORES_DIR)main.c \
		$(UTILS_DIR)handle_heap.c \
		$(UTILS_DIR)handle_string.c \
		$(UTILS_DIR)print_string.c


OBJS_DIR := objs/
OBJS := $(SRCS:%.c=$(OBJS_DIR)%.o)


DEPS_DIR := deps/
DEPS := $(OBJS:%.o=$(DEPS_DIR)%.d)


INCS_DIR := incs
INCS_PATH := -I./$(INCS_DIR)


CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3 -pthread
# CFLAGS := -Wall -Wextra -Werror -g3 -O0 -pthread -fsanitize=address,undefined -ferror-limit=50

MKDIR := mkdir -p
RM := rm -rf
