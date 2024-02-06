# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 22:55:15 by mamiyaza          #+#    #+#              #
#    Updated: 2024/02/06 22:14:56 by mamiyaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

SRCDIR := srcs/
SRCS := main.c \
		set_data.c \
		create_threads.c \
		get_usec_time.c \
		philo_routine.c \
		monitor_routine.c \
		clean_resources.c \
		print_stats.c \
		utils.c

OBJDIR := objs/
OBJS := $(SRCS:%.c=$(OBJDIR)%.o)

CC := gcc
CFLAGS := -Wall -Wextra -Werror -pthread
# CFLAGS := -Wall -Wextra -Werror -g -O0 -pthread -fsanitize=address -fsanitize=undefined -ferror-limit=50

MKDIR := mkdir -p
RM := rm -rf

# macros for test cases
ARGS_FOR_TEST0 := 4 410 200 200 5

ARGS_FOR_TEST1 := 4 410 200 200

ARGS_FOR_TEST2 := 31 500 200 200

ARGS_FOR_ERROR_TEST0 :=
ARGS_FOR_ERROR_TEST1 := 1
ARGS_FOR_ERROR_TEST2 := 1 1
ARGS_FOR_ERROR_TEST3 := 1 1 1
ARGS_FOR_ERROR_TEST4 := 1 1 1 1
ARGS_FOR_ERROR_TEST5 := 1 1 1 1 1
ARGS_FOR_ERROR_TEST6 := -1
ARGS_FOR_ERROR_TEST7 := 1 -1
ARGS_FOR_ERROR_TEST8 := 1 1 -1
ARGS_FOR_ERROR_TEST9 := 1 1 1 -1
ARGS_FOR_ERROR_TEST10 := 1 1 1 1 -1
ARGS_FOR_ERROR_TEST11 := 1 0
ARGS_FOR_ERROR_TEST12 := 1 0
ARGS_FOR_ERROR_TEST13 := 1 1 0
ARGS_FOR_ERROR_TEST14 := 1 1 1 0
ARGS_FOR_ERROR_TEST15 := 1 1 1 1 0
ARGS_FOR_ERROR_TEST16 := 0
ARGS_FOR_ERROR_TEST17 := 1 59
ARGS_FOR_ERROR_TEST18 := 1 1 59
ARGS_FOR_ERROR_TEST19 := 1 1 1 59
# ARGS_FOR_ERROR_TEST20 := 1 1 1 1 -100
ARGS_FOR_ERROR_TEST21 := 201
ARGS_FOR_ERROR_TEST22 := 1 2147483648
ARGS_FOR_ERROR_TEST23 := 1 1 2147483648
ARGS_FOR_ERROR_TEST24 := 1 1 1 2147483648
ARGS_FOR_ERROR_TEST25 := 1 1 1 1 2147483648
# ARGS_FOR_ERROR_TEST26 := -2147483649
# ARGS_FOR_ERROR_TEST27 := 1 -2147483649
# ARGS_FOR_ERROR_TEST28 := 1 1 -2147483649
# ARGS_FOR_ERROR_TEST29 := 1 1 1 -2147483649
# ARGS_FOR_ERROR_TEST30 := 1 1 1 1 -2147483649
ARGS_FOR_ERROR_TEST31 := ""
ARGS_FOR_ERROR_TEST32 := " "
ARGS_FOR_ERROR_TEST33 := "  "
ARGS_FOR_ERROR_TEST34 := "" ""
ARGS_FOR_ERROR_TEST45 := " " ""
ARGS_FOR_ERROR_TEST36 := "" " "
ARGS_FOR_ERROR_TEST37 := " " " "
ARGS_FOR_ERROR_TEST38 := "" "" ""
ARGS_FOR_ERROR_TEST39 := "a"
ARGS_FOR_ERROR_TEST40 := 'a'
ARGS_FOR_ERROR_TEST41 := "abc"
ARGS_FOR_ERROR_TEST42 := " abc"
ARGS_FOR_ERROR_TEST43 := "abc "
ARGS_FOR_ERROR_TEST44 := "  abc "
ARGS_FOR_ERROR_TEST45 := "  a  b  c  "
ARGS_FOR_ERROR_TEST46 := "  42  "
ARGS_FOR_ERROR_TEST47 := "  42  70   70  70  "

# rules for Make
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

$(OBJDIR):
	$(MKDIR) objs

$(OBJDIR)%.o: $(SRCDIR)%.c $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:
	make clean
	$(RM) $(NAME)

re: fclean all

test0:
	make re -s
	./$(NAME) $(ARGS_FOR_TEST0)
	make fclean

test1:
	make re -s
	./$(NAME) $(ARGS_FOR_TEST1)
	make fclean

test2:
	make re -s
	./$(NAME) $(ARGS_FOR_TEST2)
	make fclean

test_e:
	make re -s
	./$(NAME) $(ARGS_FOR_ERROR_TEST0)
	./$(NAME) $(ARGS_FOR_ERROR_TEST1)
	./$(NAME) $(ARGS_FOR_ERROR_TEST2)
	./$(NAME) $(ARGS_FOR_ERROR_TEST3)
	./$(NAME) $(ARGS_FOR_ERROR_TEST4)
	./$(NAME) $(ARGS_FOR_ERROR_TEST5)
	./$(NAME) $(ARGS_FOR_ERROR_TEST6)
	./$(NAME) $(ARGS_FOR_ERROR_TEST7)
	./$(NAME) $(ARGS_FOR_ERROR_TEST8)
	./$(NAME) $(ARGS_FOR_ERROR_TEST9)
	./$(NAME) $(ARGS_FOR_ERROR_TEST10)
	./$(NAME) $(ARGS_FOR_ERROR_TEST11)
	./$(NAME) $(ARGS_FOR_ERROR_TEST12)
	./$(NAME) $(ARGS_FOR_ERROR_TEST13)
	./$(NAME) $(ARGS_FOR_ERROR_TEST14)
	./$(NAME) $(ARGS_FOR_ERROR_TEST15)
	./$(NAME) $(ARGS_FOR_ERROR_TEST16)
	./$(NAME) $(ARGS_FOR_ERROR_TEST17)
	./$(NAME) $(ARGS_FOR_ERROR_TEST18)
	./$(NAME) $(ARGS_FOR_ERROR_TEST19)
#	./$(NAME) $(ARGS_FOR_ERROR_TEST20)
	./$(NAME) $(ARGS_FOR_ERROR_TEST21)
	./$(NAME) $(ARGS_FOR_ERROR_TEST22)
	./$(NAME) $(ARGS_FOR_ERROR_TEST23)
	./$(NAME) $(ARGS_FOR_ERROR_TEST24)
	./$(NAME) $(ARGS_FOR_ERROR_TEST25)
#	./$(NAME) $(ARGS_FOR_ERROR_TEST26)
#	./$(NAME) $(ARGS_FOR_ERROR_TEST27)
#	./$(NAME) $(ARGS_FOR_ERROR_TEST28)
#	./$(NAME) $(ARGS_FOR_ERROR_TEST29)
#	./$(NAME) $(ARGS_FOR_ERROR_TEST30)
	./$(NAME) $(ARGS_FOR_ERROR_TEST31)
	./$(NAME) $(ARGS_FOR_ERROR_TEST32)
	./$(NAME) $(ARGS_FOR_ERROR_TEST33)
	./$(NAME) $(ARGS_FOR_ERROR_TEST34)
	./$(NAME) $(ARGS_FOR_ERROR_TEST35)
	./$(NAME) $(ARGS_FOR_ERROR_TEST36)
	./$(NAME) $(ARGS_FOR_ERROR_TEST37)
	./$(NAME) $(ARGS_FOR_ERROR_TEST38)
	./$(NAME) $(ARGS_FOR_ERROR_TEST39)
	./$(NAME) $(ARGS_FOR_ERROR_TEST40)
	./$(NAME) $(ARGS_FOR_ERROR_TEST41)
	./$(NAME) $(ARGS_FOR_ERROR_TEST42)
	./$(NAME) $(ARGS_FOR_ERROR_TEST43)
	./$(NAME) $(ARGS_FOR_ERROR_TEST44)
	./$(NAME) $(ARGS_FOR_ERROR_TEST45)
	./$(NAME) $(ARGS_FOR_ERROR_TEST46)
	./$(NAME) $(ARGS_FOR_ERROR_TEST47)
	make fclean

.PHONY: all clean fclean re test0 test1
