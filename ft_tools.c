/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:46:22 by mmostafa          #+#    #+#             */
/*   Updated: 2020/09/24 15:47:05 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"

void	*mini_mmap(size_t size, void *add)
{
	return (mmap(add, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0));
}