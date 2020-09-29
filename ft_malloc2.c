/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:16:15 by mmostafa          #+#    #+#             */
/*   Updated: 2020/09/24 15:23:17 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"

void *ft_malloc(size_t size)
{
	if (size >= 1 && size <= 128)
		return (ft_tiny(size));
	else if (size >= 129 && size <= 512)
		return (ft_small(size));
	else if (size > 513)
		return (ft_large(size));
	return (NULL);
}


