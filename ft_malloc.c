/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:16:15 by mmostafa          #+#    #+#             */
/*   Updated: 2020/10/01 23:12:07 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"

void *ft_malloc(size_t size)
{
	g_zones.requested_size = size;
	g_zones.page_size = getpagesize();
	printf ("re_size: %lu\np_size: %d\ntiny: %p\nsmall: %p\n",
	g_zones.requested_size, g_zones.page_size,
	g_zones.tinies.zone, g_zones.smalls.zone);
	if (size >= 1 && size <= 128)
		return (ft_tiny());
	else if (size >= 129 && size <= 512)
		return (ft_small());
	else if (size > 513)
		return (ft_large());
	return (NULL);
}