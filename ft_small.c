/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:36:23 by mmostafa          #+#    #+#             */
/*   Updated: 2020/09/29 02:01:50 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"


static t_mem   *ceate_small_list(size_t size)
{
    size = 0;
    return (NULL);
}

static void    *search_in_small_list(t_mem *small, size_t size)
{
    small = NULL;
    size = 0;
    return (NULL);
}

void    *ft_small(size_t size)
{
    t_mem   *zone;

    zone = NULL;
    if ((g_second_alloc & SECOND_TINY) == SECOND_TINY)
	{
		return (search_in_small_list(zone, size));
		printf("2ND\n");
	}
	else
	{
		zone = ceate_small_list(size);
		g_second_alloc = 2;
		printf("1ST\n");
	}
    return (NULL);
}