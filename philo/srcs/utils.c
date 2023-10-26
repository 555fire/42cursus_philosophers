#include "../includes/philo.h"

size_t	ph_atoi(char *s, t_data *d)
{
	size_t	num;

//	__DEBUG_PRINT_STR__(s);
	num = 0;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	if (*s == '+')
		s++;
	while (*s)
	{
//		__DEBUG_PRINT_CHR__(*s);
		if (*s < '0' || *s > '9')
		{
			d->errstat = ARGV_ERROR;
			return (0);
		}
		if (num > SIZE_MAX / 10 || (num == SIZE_MAX / 10 &&
				(unsigned long)(*s - '0') >= SIZE_MAX % 10))
		{
			d->errstat = ARGV_ERROR;
			return (0);
		}
//		__DEBUG_PRINT_CHR__(*s);
		num = num * 10 + (*s - '0');
//		__DEBUG_PRINT_NUM__(num);
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
		print_errstat_without_d(CALLOC_ARGS_ERROR);
		return (NULL);
	}
	mem = malloc(count * size);
	if (!mem)
	{
		errno = ENOMEM;
		print_errstat_without_d(MALLOC_ERROR);
		return (NULL);
	}
	memset(mem, 0, count * size);
	return (mem);
}

void	*ph_calloc(size_t count, size_t size, t_data *d)
{
	void	*mem;

//	__DEBUG_PRINT_CALLOC_ARGS__(count, size);
	if (!count || !size || size > SIZE_MAX / count)
	{
		d->errstat = CALLOC_ARGS_ERROR;
		__DEBUG__(d);
		return (NULL);
	}
	mem = malloc(count * size);
	if (!mem)
	{
		d->errstat = MALLOC_ERROR;
		__DEBUG__(d);
		return (NULL);
	}
//	__DEBUG__(d);
	memset(mem, 0, count * size);
//	__DEBUG__(d);
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