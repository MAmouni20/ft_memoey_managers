/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:25:01 by mmostafa          #+#    #+#             */
/*   Updated: 2020/09/29 02:02:06 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"


static t_mem   *ceate_tiny_list(size_t size)
{
    size = 0;
    return (NULL);
}

static void    *search_in_tiny_list(t_mem *tiny, size_t size)
{
    tiny = NULL;
    size = 0;
    return (NULL);
}

void    *ft_tiny(size_t size)
{
    t_mem   *zone;

    zone = NULL;
    if ((g_second_alloc & SECOND_TINY) == SECOND_TINY)
	{
		return (search_in_tiny_list(zone, size));
		printf("2ND\n");
	}
	else	
    {

		zone = ceate_tiny_list(size);
		g_second_alloc = 2;
		printf("1ST\n");
	}
    return (NULL);
}