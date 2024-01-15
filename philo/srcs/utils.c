/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:55:12 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/01/15 18:44:27 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	ft_strlen(const char *s);
void	putstr_stdout(const char *s);
void	putstr_stderr(const char *s);
size_t	ph_atoi(char *s, t_data *d);
void	*ph_calloc_without_d(size_t count, size_t size);
void	*ph_calloc(size_t count, size_t size, t_data *d);
void	free_safely(void *mem0, void *mem1, void *mem2, void *mem3);

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

void	putstr_stdout(const char *s)
{
	write(STDOUT_FILENO, s, ft_strlen(s));
}

void	putstr_stderr(const char *s)
{
	write(STDERR_FILENO, s, ft_strlen(s));
}

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
			set_errstat_and_print_errmsg(d, ARGV_ERROR, ERRMSG_ARGC);
			return (0);
		}
		if (num > SIZE_MAX / 10 || (num == SIZE_MAX / 10
				&& (unsigned long)(*s - '0') >= SIZE_MAX % 10))
		{
			set_errstat_and_print_errmsg(d, ARGV_ERROR, ERRMSG_ARGV);
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
		set_errstat_and_print_errmsg(d, CALLOC_ARGS_ERROR, ERRMSG_CALLOC_ARGS);
		return (NULL);
	}
	mem = malloc(count * size);
	if (!mem)
	{
		set_errstat_and_print_errmsg(d, MALLOC_ERROR, ERRMSG_MALLOC);
		return (NULL);
	}
	memset(mem, 0, count * size);
	return (mem);
}

void	free_safely(void *mem0, void *mem1, void *mem2, void *mem3)
{
	free(mem0);
	free(mem1);
	free(mem2);
	free(mem3);
	mem0 = NULL;
	mem1 = NULL;
	mem2 = NULL;
	mem3 = NULL;
}

/*
	Since system call "free" does not return a value, there is no need to check
	wether the return value of this function indicates success or failure.
*/