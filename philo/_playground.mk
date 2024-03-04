# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    _playground.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 19:21:47 by mamiyaza          #+#    #+#              #
#    Updated: 2024/03/01 19:22:54 by mamiyaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# playground to understand the Makefile specifications

test:
	printf $(ANSI_PURPLE)"[%s]\n"$(ANSI_RESET) "$(SRCS)"
	printf $(ANSI_PURPLE)"[%s]\n"$(ANSI_RESET) "$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))"
	printf $(ANSI_PURPLE)"[%s]\n"$(ANSI_RESET) "$(patsubst $(SRCS_DIR)%.c, $(DEPS_DIR)%.o, $(SRCS))"
