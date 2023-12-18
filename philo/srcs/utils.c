/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:55:12 by mamiyaza          #+#    #+#             */
/*   Updated: 2023/12/18 11:09:45 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	ph_atoi(char *s, t_data *d)
{
	size_t	num;

	num = 0;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	if (*s == '+')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
		{
			d->errstat = ARGV_ERROR;
			perror_atomically(d, ERRMSG_ARGV, __func__, __LINE__);
			return (0);
		}
		if (num > SIZE_MAX / 10 || (num == SIZE_MAX / 10
				&& (unsigned long)(*s - '0') >= SIZE_MAX % 10))
		{
			d->errstat = ARGV_ERROR;
			perror_atomically(d, ERRMSG_ARGV, __func__, __LINE__);
			return (0);
		}
		num = num * 10 + (*s - '0');
		s++;
	}
	return (num);
}

void	*ph_calloc_without_d(size_t count, size_t size)
{
	void	*mem;

	errno = 0;
	if (!count || !size || size > SIZE_MAX / count)
	{
		errno = EINVAL;
		printf("%s [%s, %d]", ERRMSG_CALLOC_ARGS, __func__, __LINE__);
		return (NULL);
	}
	mem = malloc(count * size);
	if (!mem)
	{
		errno = ENOMEM;
		printf("%s [%s, %d]", ERRMSG_MALLOC, __func__, __LINE__);
		return (NULL);
	}
	memset(mem, 0, count * size);
	return (mem);
}

void	*ph_calloc(size_t count, size_t size, t_data *d)
{
	void	*mem;

	if (!count || !size || size > SIZE_MAX / count)
	{
		d->errstat = CALLOC_ARGS_ERROR;
		perror_atomically(d, ERRMSG_CALLOC_ARGS, __func__, __LINE__);
		return (NULL);
	}
	mem = malloc(count * size);
	if (!mem)
	{
		d->errstat = MALLOC_ERROR;
		perror_atomically(d, ERRMSG_MALLOC, __func__, __LINE__);
		return (NULL);
	}
	memset(mem, 0, count * size);
	return (mem);
}

void	free_safely(void *mem)
{
	free(mem);
	mem = NULL;
	return ;
}

/*
	Since system call "free" does not return a value, there is no need to check
	wether the return value of this function indicates success or failure.
*/