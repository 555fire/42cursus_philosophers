/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:55:12 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/01/15 21:31:23 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	ft_strlen(const char *s);
void	putstr_stdout(const char *s);
void	putstr_stderr(const char *s);
size_t	ft_atoi(char *s, t_data *d);
void	*ft_calloc_without_d(size_t count, size_t size);
void	*ft_calloc(size_t count, size_t size, t_data *d);
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

size_t	ft_atoi(char *s, t_data *d)
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
			set_errstat_simustat_and_print_errmsg(d, ARGV_ERROR, ERRMSG_ARGC);
			return (0);
		}
		if (num > SIZE_MAX / 10 || (num == SIZE_MAX / 10
				&& (unsigned long)(*s - '0') >= SIZE_MAX % 10))
		{
			set_errstat_simustat_and_print_errmsg(d, ARGV_ERROR, ERRMSG_ARGV);
			return (0);
		}
		num = num * 10 + (*s - '0');
		s++;
	}
	return (num);
}

void	*ft_calloc_without_d(size_t count, size_t size)
{
	void	*mem;

	errno = 0;
	if (!count || !size || size > SIZE_MAX / count)
	{
		errno = EINVAL;
		printf("%s [in %s]", ERRMSG_CALLOC_ARGS, __func__);
		return (NULL);
	}
	mem = malloc(count * size);
	if (!mem)
	{
		errno = ENOMEM;
		printf("%s [in %s]", ERRMSG_MALLOC, __func__);
		return (NULL);
	}
	memset(mem, 0, count * size);
	return (mem);
}

void	*ft_calloc(size_t count, size_t size, t_data *d)
{
	void	*mem;

	if (!count || !size || size > SIZE_MAX / count)
	{
		set_errstat_simustat_and_print_errmsg(d, CALLOC_ARGS_ERROR, ERRMSG_CALLOC_ARGS);
		return (NULL);
	}
	mem = malloc(count * size);
	if (!mem)
	{
		set_errstat_simustat_and_print_errmsg(d, MALLOC_ERROR, ERRMSG_MALLOC);
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