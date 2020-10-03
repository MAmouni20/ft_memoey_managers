/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:16:15 by mmostafa          #+#    #+#             */
/*   Updated: 2020/10/02 21:01:52 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"

void *ft_malloc(size_t size)
{
	g_zones.requested_size = size;
	g_zones.page_size = getpagesize();
	if (size >= 1 && size <= 128)
		return (ft_tiny());
	else if (size >= 129 && size <= 512)
		return (ft_small());
	else if (size > 513)
		return (ft_large());
	return (NULL);
}