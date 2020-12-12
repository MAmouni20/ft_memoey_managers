/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:02:14 by mmostafa          #+#    #+#             */
/*   Updated: 2020/10/15 17:11:57 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"

void	ft_free_mem(t_zone *zones_list)
{
	t_mem	*zone;

	zone = zones_list->zone;
	while (zones_list)
	{
		while (zone)
		{
			if (zone->ptr == g_zones.to_free)
			{
				zone->is_empty = 'E';
				zone->size = 0;
				munmap(zone->ptr, TINY_SIZE);
				return ;
			}
			zone = zone->next;
		}
		zones_list = zones_list->next;
		zone = zones_list->zone;
	}
}

void	ft_free(void *ptr)
{
	g_zones.to_free = ptr;
	if (g_zones.tinies)
		ft_free_mem(g_zones.tinies);
	if (g_zones.smalls)
		ft_free_mem(g_zones.smalls);
}