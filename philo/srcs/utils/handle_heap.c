/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiyaza <mamiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:55:12 by mamiyaza          #+#    #+#             */
/*   Updated: 2024/02/20 21:52:17 by mamiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size);
// void	*ft_calloc_with_d(size_t count, size_t size, t_data *const d);
void	free_safely(void *mem);

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	errno = 0;
	if (!count || !size || size > SIZE_MAX / count)
		return (NULL);
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	memset(mem, 0, count * size);
	return (mem);
}

// void	*ft_calloc_with_d(size_t count, size_t size, t_data *const d)
// {
// 	void	*mem;

// 	if (!count || !size || size > SIZE_MAX / count)
// 	{
// 		set_and_print_err(d, CALLOC_ARGS_ERROR, ERRMSG_CALLOC_ARGS);
// 		return (NULL);
// 	}
// 	mem = malloc(count * size);
// 	if (!mem)
// 	{
// 		set_and_print_err(d, MALLOC_ERROR, ERRMSG_MALLOC);
// 		return (NULL);
// 	}
// 	memset(mem, 0, count * size);
// 	return (mem);
// }

void	free_safely(void *mem)
{
	free(mem);
	mem = NULL;
}
