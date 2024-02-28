/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:33:20 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/20 19:42:17 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	putstr(const char *const s);
void	putstr_stderr(const char *const s);

void	putstr(const char *s)
{
	if (!s)
		return ;
	write(STDOUT_FILENO, s, ft_strlen(s));
}

void	putstr_stderr(const char *s)
{
	if (!s)
		return ;
	write(STDERR_FILENO, s, ft_strlen(s));
}
