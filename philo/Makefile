# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 22:55:15 by mamiyaza          #+#    #+#              #
#    Updated: 2024/02/29 01:42:16 by mamiyaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# variable definition
#  variable definition for compilation
include var_compilation.mk
#  variable definition for testcases
include var_testcase.mk
#  include deps_dir, without warning in case of no existing this dir
-include deps

ANSI_BOLD := "\033[1m"
ANSI_BLINK := "\033[5m"
ANSI_BOLD_BLINK := "\033[1,5m"
ANSI_RED := "\033[31m"
ANSI_GREEN := "\033[32m"
ANSI_PURPLE := "\033[34m"
ANSI_RESET := "\033[m"
# ANSI_BOLD_RED := "\033[1,31m"
# ANSI_BOLD_GREEN := "\033[1,32m"
ANSI_BOLD_RED := $(ANSI_BOLD)$(ANSI_RED)
ANSI_BOLD_GREEN := $(ANSI_BOLD)$(ANSI_GREEN)
ANSI_BLINK_RED := $(ANSI_BLINK)$(ANSI_RED)
ANSI_BLINK_GREEN := $(ANSI_BLINK)$(ANSI_GREEN)
ANSI_BOLD_BLINK_RED := $(ANSI_BOLD)$(ANSI_BLINK)$(ANSI_RED)
ANSI_BOLD_BLINK_GREEN := $(ANSI_BOLD)$(ANSI_BLINK)$(ANSI_GREEN)

# OPEN_METER = "|@"
# SPACE = "               "
# CLOSE = "|"



#
# TOTAL_STEPS := 100
# TOTAL_STEPS := 100
# CURRENT_STEP = 0
# TOTAL_STEPS := 100
# CURRENT_STEP = 0
TOTAL_STEP := 100
CURRENT_STEP := 0

# NUMBER_OF_TOTAL_PROCESS := 100
# NUMBER_OF_CURRENT_PROCESS := 0

# NUMBERSIGN_BAR :=

# define PRINT_PROGRESS
# 	@printf "\r[%-50s] %3d%%\n" "$(<) $(NAME)" $$(($1 * 100 / $(TOTAL_STEPS)))
# endef

# define PRINT_PROGRESS
# 	@printf "\r[%-20s] %3d%%\n" "$(<) $(NAME)" $$(($1 * 100 / $(TOTAL_STEPS)))
# endef

# define PRINT_PROGRESS
# 	@printf "\r[%-20s] %3d%%" "$(shell echo '##########' | cut -c1-$(shell expr $1 / $(TOTAL_STEPS) \* 10))" $$(($1 * 100 / $(TOTAL_STEPS)))
# endef

define PRINT_PROGRESS
	@printf "\r\t[%-20s] %3d%%\n" "$(shell printf "%*s" $$(($1 * 20 / $(TOTAL_STEP))) | tr ' ' '#')" $$(($1 * 100 / $(TOTAL_STEPS)))
endef

# define PRINT_COMPILE_PROGRESS_IN_GRAPHICAL_GREEN_BAR
# 	@printf "\r\t[%-20%] %3d%%\n" "$(shell printf $(ANSI_BOLD_BLINK_GREEN)"%*s"$(ANSI_RESET) $$($1 * $(NUMBER_OF_TOTAL_PROCESS)) | tr ' ' '#')" $$($1 / $(NUMBER_OF_TOTAL_PROCESS) * 100)
# endef

# define PRINT_COMPILE_PROGRESS_IN_GRAPHICAL_GREEN_BAR
# 	@printf "\r\t[%-20s] %3d%%\n" "$(shell printf $(ANSI_BOLD_BLINK_GREEN)"%*s"$(ANSI_RESET) $$($1 * $(NUMBER_OF_TOTAL_PROCESS)) | tr ' ' '#')" $$($1 / $(NUMBER_OF_TOTAL_PROCESS) * 100)
# endef

#	@printf "\t[%-20s] %3d%%\n" "$(shell printf "%*s" $$($1 / $(NUMBER_OF_TOTAL_PROCESS) * 20) | tr ' ' '#')" $$($1 / $(NUMBER_OF_TOTAL_PROCESS) * 100)
#	@printf "BAR LENGTH is [%d].\n" $$($1 / $(NUMBER_OF_TOTAL_PROCESS) * 20)
#	@printf "BAR LENGTH is [%d].\n" $$($1 * 20 / $(NUMBER_OF_TOTAL_PROCESS))
#	@printf "BAR LENGTH is [%d].\n" $$(($1 / $(NUMBER_OF_TOTAL_PROCESS) * 20))
#	@printf "BAR LENGTH is [%d].\n" $$(($1 * 20 / $(NUMBER_OF_TOTAL_PROCESS)))
#	@printf "PERCENTAGE is [%d].\n" $$($1 * 100 / $(NUMBER_OF_TOTAL_PROCESS))
#	@printf "PERCENTAGE is [%d].\n" $$(($1 * 100 / $(NUMBER_OF_TOTAL_PROCESS)))
#	@printf "\t[%-20s] %3d%%\n" $(shell printf "%*s" $$(($1 / $(NUMBER_OF_TOTAL_PROCESS) * 20) | tr ' ' '#')) $$(($1 / $(NUMBER_OF_TOTAL_PROCESS) * 100))
#	@printf "\t[%-20s] %3d%%\n" $(shell printf "%*s" $$(($1 * 20 / $(NUMBER_OF_TOTAL_PROCESS)) | tr ' ' '#')) $$(($1 * 100 / $(NUMBER_OF_TOTAL_PROCESS)))
#	@printf "\t[%-20s] %3d%%\n" $(shell printf "%*s" $$(($1 / $(NUMBER_OF_TOTAL_PROCESS) * 20)) | tr ' ' '#') $$(($1 / $(NUMBER_OF_TOTAL_PROCESS) * 100))
#	@printf "\r\t[%-20s] %3d%%\n" $(shell printf "%*s" $$(($1 * 20 / $(NUMBER_OF_TOTAL_PROCESS))) | tr ' ' '#') $$(($1 * 100 / $(NUMBER_OF_TOTAL_PROCESS)))
#	@$(eval $(if $(),))
NUMBER_OF_TOTAL_PROCESS := 100
NUMBER_OF_CURRENT_PROCESS := 0

define PRINT_PROGRESS_IN_BAR_0
	printf "\t[%-20s] %3d%%\n" "$(shell printf "%*s" $$(($1 * 20 / $(NUMBER_OF_TOTAL_PROCESS))) | tr ' ' '#')" $$(($1 * 100 / $(NUMBER_OF_TOTAL_PROCESS)))
endef
#	printf "\t[%-20s] %3d%%\n" "$(shell printf "%*s" $$(($1 * 20 / $(NUMBER_OF_TOTAL_PROCESS))) | tr ' ' '#')" $$(($1 * 100 / $(NUMBER_OF_TOTAL_PROCESS)))


TOTAL_STEP := 100
CURRENT_STEP := 0


define SET_CURRENT_STEP
	@$(eval CURRENT_STEP := $(shell echo $1))
endef

#	@$(info This is $(ANSI_GREEN)debug$(ANSI_RESET) message.\n)
#	$(shell printf "[%s]\n" "$(shell echo $($(CURRENT_STEP) + $1)))
#	@$(warning THIS IS WARNING MESSAGE.\n)
#	@$(eval CURRENT_STEP := $(shell echo $($(CURRENT_STEP) + $1)))
#	@printf "CURRENT_STEP is [%s].\n" "$(CURRENT_STEP)"
#	@printf "CURRENT_STEP is [%s].\n" "$(CURRENT_STEP)"
define INCREASE_CURRENT_STEP
	@$(eval CURRENT_STEP := $(shell echo $$(($(CURRENT_STEP) + $1))))
endef

define PRINT_PROGRESS_IN_BAR
	@printf $(ANSI_BOLD)"\t["$(ANSI_BOLD_GREEN)"%-20s"$(ANSI_RESET)$(ANSI_BOLD)"] %3d%%\n"$(ANSI_RESET) "$(shell printf "%*s" $$(($1 * 20 / $(TOTAL_STEP))) | tr ' ' '#')" $$(($1 * 100 / $(TOTAL_STEP)))
endef

define PRINT_PROGRESS_IN_BAR_GREEN
	@printf $(ANSI_BOLD)"\t["$(ANSI_BOLD_GREEN)"%-20s"$(ANSI_RESET)$(ANSI_BOLD)"] "$(ANSI_GREEN)"%3d%%\n"$(ANSI_RESET) "$(shell printf "%*s" $$(($1 * 20 / $(TOTAL_STEP))) | tr ' ' '#')" $$(($1 * 100 / $(TOTAL_STEP)))
endef
#	@printf "\t\033[34m[%-20s] %3d%%\n\033[m" "$(shell printf "%*s" $$(($1 * 20 / $(TOTAL_STEP))) | tr ' ' '#')" $$(($1 * 100 / $(TOTAL_STEP)))
#	@printf "\t[%-20s] %3d%%\n" "$(shell printf "%*s" $$(($1 * 20 / $(TOTAL_STEP))) | tr ' ' '#')" $$(($1 * 100 / $(TOTAL_STEP)))

#	@printf "%*s" $$(($1 * 20 / $(TOTAL_STEP))) | tr ' ' '#'"
#	@printf "%*s" "$$(($1 * 20 / $(TOTAL_STEP))) | tr ' ' '#'"
#	@printf "NUMBERSIGN_BAR 0 is [$(NUMBERSIGN_BAR)].\n"
#	@printf "NUMBERSIGN_BAR 0 is [$(NUMBERSIGN_BAR)].\n"
# define PRINT_NUMBERSIGN_BAR
# 	@printf "%*s" "$($$(($1 * 20 / $(TOTAL_STEP))) | tr ' ' '#')"
# endef
#
# define PRINT_PROGRESS_IN_BAR
# 	@printf "NUMBERSIGN_BAR is [$(NUMBERSIGN_BAR)].\n"
# 	@$(eval NUMBERSIGN_BAR := $(call PRINT_NUMBERSIGN_BAR,$(CURRENT_STEP)))
# 	@printf "NUMBERSIGN_BAR is [$(NUMBERSIGN_BAR)].\n"
# 	@printf "\t[%s] %d%%\n" "$(NUMBERSIGN_BAR)" $(CURRENT_STEP)
# endef

#	@$(eval CURRENT_STEP := $(shell printf "$$(($(CURRENT_STEP) + 7))"))

# $(TARGET_NAME): $(SOURCE_FILES)
# 	@echo "Compiling $<..."
# 	$(call PRINT_PROGRESS,0)
# 	gcc -Wall -Wextra -Werror -g3 -pthread -I./incs -c $< -o $@
# 	@echo ""



# Make rules
#  Make rules for compilation
$(NAME) : $(OBJS)
#	@echo $(ANSI_BOLD_BLINK_GREEN)"Compiling $<..."$(ANSI_RESET)
#	@$(call PRINT_PROGRESS_IN_BAR,50)
#	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $^ -o $@
#	@$(call PRINT_PROGRESS_IN_BAR,100)
	@$(eval CURRENT_STEP := $(shell expr $(CURRENT_STEP) + 2))
	@$(call PRINT_PROGRESS_IN_BAR_GREEN, $(CURRENT_STEP))
	@echo $(ANSI_BOLD_BLINK_GREEN)"make has successfully done!"$(ANSI_RESET)

#	$(call PRINT_PROGRESS,0)
#	$(call PRINT_PROGRESS,$(CURRENT_STEP))
#	@echo $(ANSI_BOLD)$(ANSI_BLINK)$(ANSI_GREEN)"---make has done!---"$(ANSI_RESET)
#	@echo "\033[1m""\033[32m---make has done!---\033[m"

all: $(NAME)

$(OBJS_DIR):
	@echo $(ANSI_BOLD_BLINK_GREEN)"make has started!"$(ANSI_RESET)
#	@$(call PRINT_PROGRESS,0)
#	@$(call PRINT_PROGRESS_IN_BAR,0)
	@$(MKDIR) $@/
	@$(MKDIR) $@/$(CORES_DIR)
	@$(MKDIR) $@/$(CORES_DIR)$(HANDLE_TIME_DIR)
	@$(MKDIR) $@/$(CORES_DIR)$(PRINT_DIR)
#	@$(call PRINT_PROGRESS,1)
#	@$(call PRINT_PROGRESS_IN_BAR,1)
#	$(call PRINT_PROGRESS_IN_BAR,3)
#	$(call PRINT_PROGRESS_IN_BAR,5)
#	$(call PRINT_PROGRESS_IN_BAR,10)
#	$(call PRINT_PROGRESS_IN_BAR,20)
	@$(MKDIR) $@/$(CORES_DIR)$(SET_DATA_DIR)
	@$(MKDIR) $@/$(CORES_DIR)$(THREAD_ROUTINE_DIR)
	@$(MKDIR) $@/$(CORES_DIR)$(VALIDATE_INPUT_DIR)
	@$(MKDIR) $@/$(UTILS_DIR)
#	$(call PRINT_PROGRESS_IN_BAR,40)

#	$(CURRENT_STEP) := 5
#	$(call PRINT_PROGRESS,5)
#	$(CURRENT_STEP) := 10
#	$(call PRINT_PROGRESS,10)
#	$(call PRINT_PROGRESS,50)
#	$(call PRINT_PROGRESS,90)
#	$(call PRINT_PROGRESS,100)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	@echo $(ANSI_BLINK_GREEN)"compiling $<"$(ANSI_RESET)
#	@echo $(ANSI_BLINK_GREEN)"...compiling "$(ANSI_RESET)$(ANSI_GREEN)"$<"$(ANSI_RESET)
#	@echo $(ANSI_BLINK_GREEN)"\rcompiling "$(ANSI_RESET)$(ANSI_GREEN)"$<"$(ANSI_RESET)$(ANSI_BLINK_GREEN)" ..."$(ANSI_RESET)
#	@echo $(ANSI_BOLD_BLINK_GREEN)"... compiling $<"
	@$(CC) $(CFLAGS) $(INCS_PATH) -c $^ -o $@
	@printf "CURRENT_STEP is [%s].\n" "$(CURRENT_STEP)"
#	@$(eval CURRENT_STEP := $(shell expr $$(CURRENT_STEP) + 1))
#	@$(eval CURRENT_STEP := $(shell expr $($(CURRENT_STEP)) + 1))
#	@$(eval CURRENT_STEP := $(shell expr $(CURRENT_STEP) + 1))
	@$(eval CURRENT_STEP := $(shell expr $(CURRENT_STEP) + 7))
#	@printf "CURRENT_STEP is [%s].\n" "$(CURRENT_STEP)"
#	@$(eval CURRENT_STEP := $(shell expr "$(CURRENT_STEP)" + 1))
#	@printf "CURRENT_STEP is [%s].\n" "$(CURRENT_STEP)"
#	@$(eval CURRENT_STEP := $(shell expr "$(CURRENT_STEP)" "+" "1"))
#	@printf "CURRENT_STEP is [%s].\n" "$(CURRENT_STEP)"
#	@$(eval CURRENT_STEP := $(shell expr "$(CURRENT_STEP) + 1"))
#	@printf "CURRENT_STEP is [%s].\n" "$(CURRENT_STEP)"
#	@$(eval CURRENT_STEP := $(shell expr $(CURRENT_STEP)))
#	@$(eval CURRENT_STEP := $(shell expr $$((CURRENT_STEP)) + 1))
#	@$(eval CURRENT_STEP := $(shell echo $($(CURRENT_STEP) + 1)))
#	@printf "CURRENT_STEP is [%s].\n" "$(CURRENT_STEP)"
#	$(call SET_CURRENT_STEP, 42)
#	@printf "CURRENT_STEP is [%s].\n" "$(CURRENT_STEP)"
#	$(call INCREASE_CURRENT_STEP, 7)
	@printf "CURRENT_STEP is [%s].\n" "$(CURRENT_STEP)"
#	@$(call PRINT_PROGRESS_IN_BAR,$(CURRENT_STEP))
	@$(call PRINT_PROGRESS_IN_BAR, $(CURRENT_STEP))
	@$(call PRINT_PROGRESS_IN_BAR_0, $(CURRENT_STEP))
	@echo

#$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
##	@echo "\t"$(ANSI_BLINK_GREEN)"now compiling ..."$(ANSI_RESET)
#	@echo $(ANSI_BOLD_BLINK_GREEN)"\rcompiling "$(ANSI_RESET)$(ANSI_BOLD_GREEN)"$<"$(ANSI_RESET)$(ANSI_BOLD_BLINK_GREEN)" ..."$(ANSI_RESET)
#	@$(call PRINT_PROGRESS,$(CURRENT_STEP))
#	@$(call PRINT_PROGRESS_IN_BAR,$(NUMBER_OF_CURRENT_PROCESS))
#	@$(eval CURRENT_STEP := $(shell echo $$(($(CURRENT_STEP) + 10))))
#	@printf "CURRENT_STEP is [%s].\n" $(CURRENT_STEP)
##	@$(eval NUMBER_OF_CURRENT_PROCESS := $(shell echo $$(($(NUMBER_OF_CURRENT_PROCESS) + 10))))
#	@$(eval NUMBER_OF_CURRENT_PROCESS := $(NUMBER_OF_CURRENT_PROCESS) + 10)
#	@printf "NUMBER_OF_CURRENT_PROCESS is [%s].\n" $(NUMBER_OF_CURRENT_PROCESS)
##	@$(eval CURRENT_STEP += 1)
##	@$(eval NUMBER_OF_CURRENT_PROCESS += 1)
#	@$(CC) $(CFLAGS) $(INCS_PATH) -c $^ -o $@
##	@echo "\t"$(ANSI_BLINK_GREEN)"now compiling ..."$(OPEN_METER)$(SPACE)$(CLOSE)$(ANSI_RESET)

#	$(OPEN_METER) += $(OPEN_METER)
#	$(SPACE) -= " "
#	$(MKDIR) $(dir $@)

clean:
	@echo $(ANSI_BOLD_BLINK_RED)"make clean has started!"$(ANSI_RESET)
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_DIR)
	@echo $(ANSI_BOLD_BLINK_RED)"make clean has done!"$(ANSI_RESET)

fclean: print_fclean_start clean
	@$(RM) $(NAME)
	@echo $(ANSI_BOLD_BLINK_RED)"make fclean has done!"$(ANSI_RESET)

print_fclean_start:
	@echo $(ANSI_BOLD_BLINK_RED)"make fclean has started!"$(ANSI_RESET)

re: fclean all

#  Make rules for testcases
include rule_testcase.mk

.PHONY: all clean fclean re test0 test1





# TOTAL_STEPS := 100
# CURRENT_STEP := 0

# define PRINT_PROGRESS
# 	@printf "\r[%-50s] %3d%%" "$(<) $(TARGET_NAME)" $$(($1 * 100 / $(TOTAL_STEPS)))
# endef

# $(TARGET_NAME): $(SOURCE_FILES)
# 	@echo "Compiling $<..."
# 	$(call PRINT_PROGRESS,0)
# 	gcc -Wall -Wextra -Werror -g3 -pthread -I./incs -c $< -o $@
# 	@echo ""
