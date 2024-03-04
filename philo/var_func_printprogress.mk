# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    var_func_printprogress.mk                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 03:40:40 by mamiyaza          #+#    #+#              #
#    Updated: 2024/03/01 16:20:28 by mamiyaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# variable and Makefile function definition
#  variable and Makefile function definition for print compilation progress

TOTAL_STEP := 100
CURRENT_STEP := 0

define PRINT_PROGRESS
	$(SILENT) printf $(ANSI_BOLD)"\t["$(ANSI_BOLD_GREEN)"%-20s"$(ANSI_RESET)$(ANSI_BOLD)"] %3d%%\n"$(ANSI_RESET) "$(shell printf "%*s" $$(($1 * 20 / $(TOTAL_STEP))) | tr ' ' '#')" $$(($1 * 100 / $(TOTAL_STEP)))
endef

define PRINT_PROGRESS_GREEN
	$(SILENT) printf $(ANSI_BOLD)"\t["$(ANSI_BOLD_GREEN)"%-20s"$(ANSI_RESET)$(ANSI_BOLD)"] "$(ANSI_GREEN)"%3d%%\n"$(ANSI_RESET) "$(shell printf "%*s" $$(($1 * 20 / $(TOTAL_STEP))) | tr ' ' '#')" $$(($1 * 100 / $(TOTAL_STEP)))
endef
