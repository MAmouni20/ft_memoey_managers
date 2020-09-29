/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:36:23 by mmostafa          #+#    #+#             */
/*   Updated: 2020/09/29 01:19:52 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"


t_mem   *ceate_small_list()
{
    return (NULL);
}

t_mem    *search_in_small_list(t_mem *small)
{
    return (NULL);
}

void    *ft_small(size_t size)
{
    t_mem   *zone;

    if ((g_second_alloc & SECOND_TINY) == SECOND_TINY)
	{
		search_in_small_list(zone);
		printf("2ND\n");
	}
	else
	{
		zone = ceate_small_list();
		g_second_alloc = 2;
		printf("1ST\n");
	}
    return (NULL);
}