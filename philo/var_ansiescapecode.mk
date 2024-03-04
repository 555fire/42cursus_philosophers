# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    var_ansiescapecode.mk                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 03:38:34 by mamiyaza          #+#    #+#              #
#    Updated: 2024/03/01 16:20:55 by mamiyaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# variable definition
#  variable definition for ansi escape codes

ANSI_BOLD := "\033[1m"
ANSI_BLINK := "\033[5m"
ANSI_BOLD_BLINK := "\033[1,5m"
ANSI_RED := "\033[31m"
ANSI_GREEN := "\033[32m"
ANSI_PURPLE := "\033[34m"
ANSI_RESET := "\033[m"
ANSI_BOLD_RED := $(ANSI_BOLD)$(ANSI_RED)
ANSI_BOLD_GREEN := $(ANSI_BOLD)$(ANSI_GREEN)
ANSI_BLINK_RED := $(ANSI_BLINK)$(ANSI_RED)
ANSI_BLINK_GREEN := $(ANSI_BLINK)$(ANSI_GREEN)
ANSI_BOLD_BLINK_RED := $(ANSI_BOLD)$(ANSI_BLINK)$(ANSI_RED)
ANSI_BOLD_BLINK_GREEN := $(ANSI_BOLD)$(ANSI_BLINK)$(ANSI_GREEN)
