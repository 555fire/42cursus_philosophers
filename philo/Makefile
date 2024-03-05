# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 22:55:15 by mamiyaza          #+#    #+#              #
#    Updated: 2024/03/05 16:24:01 by mamiyaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# .SUFFIXES:

# variable definition
#  variable definition for compilation
include var_compilation.mk

#  variable definition for testcases
include var_testcase.mk

#  variable definition for ansi escape codes
include var_ansiescapecode.mk

# variable and Makefile function definition
#  variable and Makefile function definition for print compilation progress
include var_func_printprogress.mk



#  include deps_dir, without warning in case of no existing this dir
-include $(DEPS)


OBJS_DIR_FLAG := 0
DEPS_DIR_FLAG := 0



# Make rules
#  Make rules for compilation


$(NAME): $(OBJS_DIR) $(DEPS_DIR) $(OBJS)
#$(NAME): aaa bbb $(OBJS)
	$(SILENT) echo $(ANSI_BLINK_GREEN)"linking\t$(addsuffix \n\t, $(OBJS)) \rgenerating\t$(NAME)"$(ANSI_RESET)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
#	$(SILENT) $(eval CURRENT_STEP := $(shell expr $(CURRENT_STEP) + 8))
	$(SILENT) $(eval CURRENT_STEP := 100)
	$(SILENT) $(call PRINT_PROGRESS_GREEN, $(CURRENT_STEP))
	$(SILENT) echo
	$(SILENT) echo $(ANSI_BOLD_BLINK_GREEN)"make has successfully done!"$(ANSI_RESET)

# $(NAME): $(OBJS_DIR) $(DEPS_DIR) ccc
#
# ccc: $(OBJS)
# 	$(SILENT) echo $(ANSI_BLINK_GREEN)"linking\t$(addsuffix \n\t, $^) \rgenerating\t$(NAME)"$(ANSI_RESET)
# 		$(CC) $(CFLAGS) $^ -o $(NAME)
# #	$(SILENT) $(eval CURRENT_STEP := $(shell expr $(CURRENT_STEP) + 8))
# 	$(SILENT) $(eval CURRENT_STEP := 100)
# 	$(SILENT) $(call PRINT_PROGRESS_GREEN, $(CURRENT_STEP))
# 	$(SILENT) echo
# 	$(SILENT) echo $(ANSI_BOLD_BLINK_GREEN)"make has successfully done!"$(ANSI_RESET)

all: $(NAME)

# $(OBJS): $(SRCS)
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
#	$(if $(AAA_FLAG),0,make aaa)
#	$(if $(BBB_FLAG),0,make bbb)
	$(SILENT) echo $(ANSI_BLINK_GREEN)"compiling\t$<"$(ANSI_RESET)
			$(CC) $(CFLAGS) $(INCS_PATH) -c $^ -o $@
	$(SILENT) $(eval CURRENT_STEP := $(shell expr $(CURRENT_STEP) + 6))
	$(SILENT) $(call PRINT_PROGRESS, $(CURRENT_STEP))
	$(SILENT) echo

$(OBJS_DIR):
# aaa:
	$(SILENT) echo $(ANSI_BOLD_BLINK_GREEN)"make has started!"$(ANSI_RESET)
	$(SILENT) $(call PRINT_PROGRESS, $(CURRENT_STEP))
	$(SILENT) echo
	$(SILENT) echo $(ANSI_BLINK_GREEN)"making directoris for object files"$(ANSI_RESET)
#		$(MKDIR_P) $(OBJS_DIR)
#		$(MKDIR_P) $(OBJS_DIR)$(CORES_DIR)
#		$(MKDIR_P) $(OBJS_DIR)$(CORES_DIR)$(HANDLE_TIME_DIR)
#		$(MKDIR_P) $(OBJS_DIR)$(CORES_DIR)$(PRINT_DIR)
#		$(MKDIR_P) $(OBJS_DIR)$(CORES_DIR)$(SET_DATA_DIR)
#		$(MKDIR_P) $(OBJS_DIR)$(CORES_DIR)$(THREAD_ROUTINE_DIR)
#		$(MKDIR_P) $(OBJS_DIR)$(CORES_DIR)$(VALIDATE_INPUT_DIR)
#		$(MKDIR_P) $(OBJS_DIR)$(UTILS_DIR)
		$(MKDIR_P) $(subst /,,$@)/
		$(MKDIR_P) $(subst /,,$@)/$(CORES_DIR)
		$(MKDIR_P) $(subst /,,$@)/$(CORES_DIR)$(HANDLE_TIME_DIR)
		$(MKDIR_P) $(subst /,,$@)/$(CORES_DIR)$(PRINT_DIR)
		$(MKDIR_P) $(subst /,,$@)/$(CORES_DIR)$(SET_DATA_DIR)
		$(MKDIR_P) $(subst /,,$@)/$(CORES_DIR)$(THREAD_ROUTINE_DIR)
		$(MKDIR_P) $(subst /,,$@)/$(CORES_DIR)$(VALIDATE_INPUT_DIR)
		$(MKDIR_P) $(subst /,,$@)/$(UTILS_DIR)
	$(SILENT) $(eval CURRENT_STEP := $(shell expr $(CURRENT_STEP) + 7))
	$(SILENT) $(call PRINT_PROGRESS, $(CURRENT_STEP))
	$(SILENT) echo
	$(SILENT) $(eval OBJS_DIR_FLAG := 1)

$(DEPS_DIR):
# bbb:
	$(SILENT) echo $(ANSI_BLINK_GREEN)"making directoris for dependency files"$(ANSI_RESET)
#		$(MKDIR_P) $(DEPS_DIR)
#		$(MKDIR_P) $(DEPS_DIR)$(CORES_DIR)
#		$(MKDIR_P) $(DEPS_DIR)$(CORES_DIR)$(HANDLE_TIME_DIR)
#		$(MKDIR_P) $(DEPS_DIR)$(CORES_DIR)$(PRINT_DIR)
#		$(MKDIR_P) $(DEPS_DIR)$(CORES_DIR)$(SET_DATA_DIR)
#		$(MKDIR_P) $(DEPS_DIR)$(CORES_DIR)$(THREAD_ROUTINE_DIR)
#		$(MKDIR_P) $(DEPS_DIR)$(CORES_DIR)$(VALIDATE_INPUT_DIR)
#		$(MKDIR_P) $(DEPS_DIR)$(UTILS_DIR)
		$(MKDIR_P) $(subst /,,$@)/
		$(MKDIR_P) $(subst /,,$@)/$(CORES_DIR)
		$(MKDIR_P) $(subst /,,$@)/$(CORES_DIR)$(HANDLE_TIME_DIR)
		$(MKDIR_P) $(subst /,,$@)/$(CORES_DIR)$(PRINT_DIR)
		$(MKDIR_P) $(subst /,,$@)/$(CORES_DIR)$(SET_DATA_DIR)
		$(MKDIR_P) $(subst /,,$@)/$(CORES_DIR)$(THREAD_ROUTINE_DIR)
		$(MKDIR_P) $(subst /,,$@)/$(CORES_DIR)$(VALIDATE_INPUT_DIR)
		$(MKDIR_P) $(subst /,,$@)/$(UTILS_DIR)
	$(SILENT) $(eval CURRENT_STEP := $(shell expr $(CURRENT_STEP) + 8))
	$(SILENT) $(call PRINT_PROGRESS, $(CURRENT_STEP))
	$(SILENT) echo
	$(SILENT) $(eval DEPS_DIR_FLAG := 1)

clean:
	$(SILENT) echo $(ANSI_BOLD_BLINK_RED)"make clean has started!"$(ANSI_RESET)
	$(SILENT) $(RM_RF) $(DEPS)
	$(SILENT) $(RM_RF) $(DEPS_DIR)
	$(SILENT) $(RM_RF) $(subst /,,$(DEPS_DIR))$(CORES_DIR)
	$(SILENT) $(RM_RF) $(subst /,,$(DEPS_DIR))$(UTILS_DIR)
	$(SILENT) $(RM_RF) $(OBJS)
	$(SILENT) $(RM_RF) $(OBJS_DIR)
	$(SILENT) $(RM_RF) $(subst /,,$(OBJS_DIR))$(CORES_DIR)
	$(SILENT) $(RM_RF) $(subst /,,$(OBJS_DIR))$(UTILS_DIR)
	$(SILENT) echo $(ANSI_BOLD_BLINK_RED)"make clean has done!"$(ANSI_RESET)
	$(SILENT) $(eval OBJS_DIR_FLAG := 0)
	$(SILENT) $(eval DEPS_DIR_FLAG := 0)

fclean: print_start_fclean clean
	$(SILENT) $(RM_RF) $(NAME)
	$(SILENT) echo $(ANSI_BOLD_BLINK_RED)"make fclean has done!"$(ANSI_RESET)

print_start_fclean:
	$(SILENT) echo $(ANSI_BOLD_BLINK_RED)"make fclean has started!"$(ANSI_RESET)

re: fclean all

run: re
	./$(NAME)


#  Make rules for testcases
include rule_testcase.mk


# playground to understand the Makefile specifications
include _playground.mk


# .PHONY: all clean fclean print_start_fclean re run aaa bbb
.PHONY: all clean fclean print_start_fclean re run

# .silent: all clean fclean print_start_fclean re run

# .IGNORE: all clean fclean print_start_fclean re run

# .PRECIOUS: *.c *.h Makefile *.mk ../philo/ srcs/ .gitignore
