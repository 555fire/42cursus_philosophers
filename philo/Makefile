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

ARGS_FOR_TEST0 := 4 410 200 200 5
ARGS_FOR_TEST1 := 4 410 200 200

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
	./$(NAME) 31 500 200 200
	make fclean

test_e:
	make re -s
	./$(NAME)
	./$(NAME) 1
	./$(NAME) 1 1
	./$(NAME) 1 1 1
	./$(NAME) 1 1 1 1
	./$(NAME) 1 1 1 1 1
	./$(NAME) -1
	./$(NAME) 1 -1
	./$(NAME) 1 1 -1
	./$(NAME) 1 1 1 -1
	./$(NAME) 1 1 1 1 -1
	./$(NAME) 0
	./$(NAME) 1 0
	./$(NAME) 1 1 0
	./$(NAME) 1 1 1 0
	./$(NAME) 1 1 1 1 0
	make fclean

.PHONY: all clean fclean re test0 test1
