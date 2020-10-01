/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:25:01 by mmostafa          #+#    #+#             */
/*   Updated: 2020/10/01 23:11:11 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"


static void     create_tiny_list()
{
    t_mem   *tiny;

    tiny = g_zones.tinies.zone;
}

static void    *search_in_tiny_list()
{
    return (NULL);
}

void    *ft_tiny()
{
    if (g_zones.tinies.zone)
		return (search_in_tiny_list());
	create_tiny_list();
    //return (g_zones.tinies.zone);
    return (NULL);
}