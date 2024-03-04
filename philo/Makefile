# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 22:55:15 by mamiyaza          #+#    #+#              #
#    Updated: 2024/03/01 19:35:58 by mamiyaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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



# Make rules
#  Make rules for compilation

$(NAME) : $(OBJS) | $(OBJS_DIR) $(DEPS_DIR)
	$(SILENT) echo $(ANSI_BLINK_GREEN)"linking\t$(addsuffix \n\t, $^) \rgenerating\t$@"$(ANSI_RESET)
		$(CC) $(CFLAGS) $^ -o $@
#	$(SILENT) $(eval CURRENT_STEP := $(shell expr $(CURRENT_STEP) + 8))
	$(SILENT) $(eval CURRENT_STEP := 100)
	$(SILENT) $(call PRINT_PROGRESS_GREEN, $(CURRENT_STEP))
	$(SILENT) echo
	$(SILENT) echo $(ANSI_BOLD_BLINK_GREEN)"make has successfully done!"$(ANSI_RESET)

all: $(NAME)

$(OBJS_DIR):
	$(SILENT) echo $(ANSI_BOLD_BLINK_GREEN)"make has started!"$(ANSI_RESET)
	$(SILENT) $(call PRINT_PROGRESS, $(CURRENT_STEP))
	$(SILENT) echo
	$(SILENT) echo $(ANSI_BLINK_GREEN)"making directoris for object files"$(ANSI_RESET)
			$(MKDIR) $@/
			$(MKDIR) $@/$(CORES_DIR)
			$(MKDIR) $@/$(CORES_DIR)$(HANDLE_TIME_DIR)
			$(MKDIR) $@/$(CORES_DIR)$(PRINT_DIR)
			$(MKDIR) $@/$(CORES_DIR)$(SET_DATA_DIR)
			$(MKDIR) $@/$(CORES_DIR)$(THREAD_ROUTINE_DIR)
			$(MKDIR) $@/$(CORES_DIR)$(VALIDATE_INPUT_DIR)
			$(MKDIR) $@/$(UTILS_DIR)
	$(SILENT) $(eval CURRENT_STEP := $(shell expr $(CURRENT_STEP) + 7))
	$(SILENT) $(call PRINT_PROGRESS, $(CURRENT_STEP))
	$(SILENT) echo

$(DEPS_DIR):
	$(SILENT) echo $(ANSI_BLINK_GREEN)"making directoris for dependency files"$(ANSI_RESET)
			$(MKDIR) $@/
			$(MKDIR) $@/$(CORES_DIR)
			$(MKDIR) $@/$(CORES_DIR)$(HANDLE_TIME_DIR)
			$(MKDIR) $@/$(CORES_DIR)$(PRINT_DIR)
			$(MKDIR) $@/$(CORES_DIR)$(SET_DATA_DIR)
			$(MKDIR) $@/$(CORES_DIR)$(THREAD_ROUTINE_DIR)
			$(MKDIR) $@/$(CORES_DIR)$(VALIDATE_INPUT_DIR)
			$(MKDIR) $@/$(UTILS_DIR)
	$(SILENT) $(eval CURRENT_STEP := $(shell expr $(CURRENT_STEP) + 8))
	$(SILENT) $(call PRINT_PROGRESS, $(CURRENT_STEP))
	$(SILENT) echo

# $(OBJS): $(SRCS)
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR) $(DEPS_DIR)
	$(SILENT) echo $(ANSI_BLINK_GREEN)"compiling\t$<"$(ANSI_RESET)
			$(CC) $(CFLAGS) $(INCS_PATH) -c $^ -o $@
	$(SILENT) $(eval CURRENT_STEP := $(shell expr $(CURRENT_STEP) + 6))
	$(SILENT) $(call PRINT_PROGRESS, $(CURRENT_STEP))
	$(SILENT) echo

clean:
	$(SILENT) echo $(ANSI_BOLD_BLINK_RED)"make clean has started!"$(ANSI_RESET)
	$(SILENT) $(RM) $(DEPS)
	$(SILENT) $(RM) $(DEPS_DIR)
	$(SILENT) $(RM) $(OBJS)
	$(SILENT) $(RM) $(OBJS_DIR)
	$(SILENT) echo $(ANSI_BOLD_BLINK_RED)"make clean has done!"$(ANSI_RESET)

fclean: print_start_fclean clean
	$(SILENT) $(RM) $(NAME)
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


.PHONY: all clean fclean print_start_fclean re run

# .silent: all clean fclean print_start_fclean re run

# .IGNORE: all clean fclean print_start_fclean re run
