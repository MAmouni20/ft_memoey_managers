/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:25:01 by mmostafa          #+#    #+#             */
/*   Updated: 2020/09/29 01:23:56 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"


t_mem   *ceate_tiny_list()
{
    return (NULL);
}

t_mem    *search_in_tiny_list(t_mem *tiny)
{
    return (NULL);
}

void    *ft_tiny(size_t size)
{
    t_mem   *zone;

    if ((g_second_alloc & SECOND_TINY) == SECOND_TINY)
	{
		search_in_tiny_list(zone);
		printf("2ND\n");
	}
	else	
    {

		zone = ceate_tiny_list();
		g_second_alloc = 2;
		printf("1ST\n");
	}
    return (NULL);
}