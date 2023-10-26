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
# SRCS := main.c set_data.c create_threads.c get_usec_time.c philo_routine.c check_simustat_routine.c clean_resources.c print_stats.c utils.c
# # Make OK.
# SRCS := $(SRCDIR)main.c \
# 		$(SRCDIR)set_data.c \
# 		$(SRCDIR)create_threads.c \
# 		$(SRCDIR)get_usec_time.c \
# 		$(SRCDIR)philo_routine.c \
# 		$(SRCDIR)monitor_routine.c \
# 		$(SRCDIR)clean_resources.c \
# 		$(SRCDIR)utils.c
# #Make ?

# SRCS := $(shell cd $(SRCDIR) && echo *.c)

OBJDIR := objs/
OBJS := $(SRCS:%.c=$(OBJDIR)%.o)
# OBJS := $(SRCS:%.c=$(OBJDIR)%.o)

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
# fclean:
# 	@make clean -s
# 	@$(RM) $(NAME)
# #make OK

re: fclean all

test0:
	make re -s
	./$(NAME) $(ARGS_FOR_TEST0)

#	./$(NAME) 4 410 200 200 5
	make fclean
#	make re -s
#	@make re

test1:
	make re -s
#	./$(NAME) 4 410 200 200
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
#	./$(NAME) $(ARGS_FOR_TEST1)
	make fclean

.PHONY: all clean fclean re test0 test1

# 4th Makefile for philo

# NAME := philo
#
# SRCDIR := srcs/
# SRCS := $(shell cd $(SRCDIR) && echo *.c)
#
# OBJDIR := objs/
# OBJS := $(SRCS:%.c=$(OBJDIR)%.o)
#
# CC := gcc
# CFLAGS := -Wall -Wextra -Werror -g -O0 -pthread -fsanitize=address -fsanitize=undefined -ferror-limit=50
#
# MKDIR := mkdir -p
# RM := rm -rf
#
# ARGS_FOR_TEST0 := 4 410 200 200 5
# ARGS_FOR_TEST1 := 4 410 200 200
#
# $(NAME): $(OBJDIR) $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $(OBJS)
#
# all: $(NAME)
#
# $(OBJDIR):
# 	$(MKDIR) objs
#
# $(OBJDIR)%.o: $(SRCDIR)%.c
# 	$(CC) $(CFLAGS) -o $@ -c $<
#
# clean:
# 	$(RM) $(OBJDIR)
#
# fclean: clean
# 	$(RM) $(NAME)
#
# re: fclean all
#
# test0:
# 	make re
# 	./$(NAME) $(ARGS_FOR_TEST0)
# 	make fclean
#
# test1:
# 	make re
# 	./$(NAME) $(ARGS_FOR_TEST1)
# 	make fclean
#
# .PHONY: all clean fclean re test0 test1
#
# # NAME := philo
# #
# # SRCDIR := srcs/
# # SRCS := $(shell cd $(SRCDIR) && echo *.c)
# #
# # OBJDIR := objs/
# # OBJS := $(SRCS:%.c=$(OBJDIR)%.o)
# # #make OK
# # # OBJS := $(SRCS:%.c:=$(OBJDIR)%.o)
# # # #make KO
# #
# # CC := gcc
# # CFLAGS := -Wall -Wextra -Werror -g -O0 -pthread -fsanitize=address -fsanitize=undefined -ferror-limit=50
# #
# # MKDIR := mkdir -p
# # RM := rm -rf
# #
# # ARGS_FOR_TEST0 := 4 410 200 200 5
# # ARGS_FOR_TEST1 := 4 410 200 200
# # # NAME = philo
# # # SRCDIR = srcs/
# # # SRCS = $(shell cd $(SRCDIR) && echo *.c)
# # # OBJDIR = objs/
# # # OBJS = $(SRCS:%.c=$(OBJDIR)%.o)
# # # CC = gcc
# # # CFLAGS = -Wall -Wextra -Werror -g -O0 -pthread -fsanitize=address -fsanitize=undefined -ferror-limit=50
# #
# # $(NAME): $(OBJDIR) $(OBJS)
# # 	$(CC) $(CFLAGS) -o $@ $(OBJS)
# #
# # all: $(NAME)
# # # all: $(NAME)
# # #
# # # $(NAME): $(OBJDIR) $(OBJS)
# # # 	$(CC) $(CFLAGS) -o $@ $(OBJS)
# # # #make OK
# #
# # # $(NAME): $(OBJDIR) $(OBJS)
# # # 	$(CC) $(CFLAGS) -o $@ $(OBJS)
# # #
# # # all: $(NAME)
# # # #make OK
# #
# # $(OBJDIR):
# # 	$(MKDIR) objs
# # #	mkdir -p objs
# #
# # $(OBJDIR)%.o: $(SRCDIR)%.c
# # 	$(CC) $(CFLAGS) -o $@ -c $<
# # # $(OBJDIR)%.o: $(SRCDIR)%.c
# # # 	$(CC) $(CFLAGS) -c $< -o $@
# # # #make OK
# # # $(OBJDIR)%.o: $(SRCDIR)%.c
# # # 	$(CC) $(CFLAGS) -c -o $@ $<
# # # #make OK
# # # $(OBJS): $(SRCDIR)%.c
# # # 	$(CC) $(CFLAGS) -c -o $@ $<
# # # #make KO
# # #	$(CC) $(CFLAGS) -c -o $@ $<
# # # #make OK
# # #	$(CC) $(CFLAGS) -c $< -o $@
# # # #make OK
# #
# # clean:
# # 	$(RM) $(OBJDIR)
# # #	rm -rf $(OBJDIR)
# #
# # fclean: clean
# # 	$(RM) $(NAME)
# # #	rm -f $(NAME)
# # # OK
# # # fclean:
# # # 	make clean
# # # 	$(RM) $(NAME)
# # # #	rm -f $(NAME)
# # # # OK
# #
# # re: fclean all
# #
# # test0:
# # 	make re
# # 	./$(NAME) $(ARGS_FOR_TEST0)
# # 	make fclean
# #
# # test1:
# # 	make re
# # 	./$(NAME) $(ARGS_FOR_TEST1)
# # 	make fclean
# # # make OK
# # # test: re
# # # 	./$(NAME) $(ARGS_FOR_TEST0)
# # # 	make fclean
# # # # make OK
# # #	./$(NAME) 4 410 200 200 5
# # # test:
# # # 	re
# # # 	./$(NAME) $(ARGS_FOR_TEST0)
# # # 	fclean
# # # #	./$(NAME) 4 410 200 200 5
# # # #make KO
# #
# # .PHONY: all clean fclean re test
#
# # NAME = philo
# # SRCDIR = srcs/
# # SRCS = $(shell cd $(SRCDIR) && echo *.c)
# # OBJDIR = objs/
# # OBJS = $(SRCS:%.c=$(OBJDIR)%.o)
# # CC = gcc
# # CFLAGS = -Wall -Wextra -Werror -g -O0 -pthread -fsanitize=address -fsanitize=undefined -ferror-limit=50
# #
# # # all: $(OBJDIR) $(NAME)
# # all: $(NAME)
# #
# # $(OBJDIR):
# # 	mkdir -p objs
# #
# # # # $(NAME): $(OBJS)
# # # $(NAME): $(OBJDIR) $(OBJS)
# # # 	$(CC) $(CFLAGS) -o $@ $(OBJS)
# #
# # # $(NAME): $(OBJS)
# # # $(NAME): $(OBJS) $(OBJDIR)
# # # 	$(CC) $(CFLAGS) -o $@ $<
# # $(NAME): $(OBJDIR) $(OBJS)
# # 	$(CC) $(CFLAGS) -o $@ $(OBJS)
# #
# # # $(OBJDIR)%.o: $(SRCDIR)%.c
# # # $(OBJS): $(SRCDIR)%.c
# # # $(OBJS): $(SRCS)
# # # .o.c:
# # # .c.o:
# # # $(OBJDIR).o$(SRCDIR).c:
# # # $(OBJDIR).o: $(SRCDIR).c
# # $(OBJDIR)%.o: $(SRCDIR)%.c
# # 	$(CC) $(CFLAGS) -c -o $@ $<
# #
# # clean:
# # 	rm -rf $(OBJDIR)
# #
# # fclean: clean
# # 	rm -f $(NAME)
# #
# # re: fclean all
# #
# # test:
# # 	re
# # 	./$(NAME) 4 410 200 200 5
# # 	fclean
# #
# # .PHONY: all clean fclean re test
#
# # 3rd Makefile

# NAME = philo
# SRCDIR = ./srcs/
# SRCS = $(shell cd $(SRCDIR) && echo *.c)
# #All source files you needs to compile your project must be explicitly named in your Makefile.(from the Norm version 4)
# OBJDIR = ./objs/
# OBJS = $(SRCS:%.c=$(OBJDIR)%.o)
# #This construct (e.g. '$(var:.a=.b)', '$(var:%.a=%.b)' is called "substitution reference" in official GNU make document.
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g -O0 -pthread -fsanitize=address -fsanitize=undefined -ferror-limit=50
# #CFLAGS = -Wall -Wextra -Werror -ferror-limit=50
#
# all: $(OBJDIR) $(NAME)
#
# $(OBJDIR):
# 	mkdir -p objs
#
# $(OBJDIR)%.o: $(SRCDIR)%.c
# 	$(CC) $(CFLAGS) -c -o $@ $<
#
# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $<
#
# clean:
# 	rm -rf $(OBJDIR)
#
# fclean: clean
# 	rm -f $(NAME)
#
# re: fclean all
#
# test:
# 	make re
# 	./$(NAME) 4 410 200 200 5
# 	make fclean
#
# .PHONY: all clean fclean re test
#
# # 2nd Makefile

# NAME = philo
# SRCDIR = ./srcs/
#
# SRCS = $(shell cd $(SRCDIR) && echo *.c)
#
# #All source files you need to compile your project must be explicitly named in your Makefile.
#
# OBJDIR = ./objs/
# OBJS = $(SRCS:%.c=$(OBJDIR)%.o)
# CC = gcc -g -O0 -pthread
#
# #hyphen large o zero option
#
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined -ferror-limit=50
#
# all: $(OBJDIR) $(NAME)
#
# $(OBJDIR):
# 	mkdir -p objs
#
# #hyphen p option[--parents]
#
# $(OBJDIR)%.o: $(SRCDIR)%.c
# 	$(CC) $(CFLAGS) -c -o $@ $<
#
# #$(CC) $(CFLAGS) -c -o $@ $^ is also OK?
# #"$@" represents the "target". "$<" represents "the first target".
# #"-c" is a compiler option that tells the compiler to generate object files instead of producing a final executable.
#
# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
#
# #$(CC) $(CFLAGS) -o $@ $< is also OK?
# #$(CC) $(CFLAGS) -o $@ $^ is also OK?
#
# clean:
# 	rm -rf $(OBJDIR)
#
# fclean: clean
# 	rm -f $(NAME)
#
# re: fclean all
#
# .PHONY: all clean fclean re
#
# # 1st Makefile
