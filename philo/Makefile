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

# object-like macros for test cases
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
ARGS_FOR_ERROR_TEST11 := 0
ARGS_FOR_ERROR_TEST12 := 1 0
ARGS_FOR_ERROR_TEST14 := 1 1 0
ARGS_FOR_ERROR_TEST15 := 1 1 1 0
ARGS_FOR_ERROR_TEST16 := 1 1 1 1 0


$(NAME) : $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

all: $(NAME)

$(OBJDIR):
	$(MKDIR) objs

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

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
	make fclean

# test_e:
# 	make re -s
# 	./$(NAME)
# 	./$(NAME) 1
# 	./$(NAME) 1 1
# 	./$(NAME) 1 1 1
# 	./$(NAME) 1 1 1 1
# 	./$(NAME) 1 1 1 1 1
# 	./$(NAME) -1
# 	./$(NAME) 1 -1
# 	./$(NAME) 1 1 -1
# 	./$(NAME) 1 1 1 -1
# 	./$(NAME) 1 1 1 1 -1
# 	./$(NAME) 0
# 	./$(NAME) 1 0
# 	./$(NAME) 1 1 0
# 	./$(NAME) 1 1 1 0
# 	./$(NAME) 1 1 1 1 0
# 	make fclean

.PHONY: all clean fclean re test0 test1
