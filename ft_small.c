/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:36:23 by mmostafa          #+#    #+#             */
/*   Updated: 2020/10/01 23:11:42 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"


static void   create_small_list()
{
}

static void    *search_in_small_list()
{
    return (NULL);
}

void    *ft_small()
{
    if (g_zones.smalls.zone)
		return (search_in_small_list());
	create_small_list();
	//return (g_zones.smalls.zone);
	return (NULL);
}