/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:34:38 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/20 19:42:12 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s);
size_t	ft_atoi(const char *s);

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
		i++;
	return (i);
}

size_t	ft_atoi(const char *s)
{
	size_t	num;

	if (!s)
		return (0);
	num = 0;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	if (*s == '+')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		if (num > SIZE_MAX / 10 || (num == SIZE_MAX / 10
				&& (unsigned long)(*s - '0') >= SIZE_MAX % 10))
			return (0);
		num = num * 10 + (*s - '0');
		s++;
	}
	return (num);
}
