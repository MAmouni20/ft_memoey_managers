/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_managers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:15:56 by mmostafa          #+#    #+#             */
/*   Updated: 2020/09/29 02:03:04 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_MANAGERS_H
#define MEMORY_MANAGERS_H

#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


#define	SMALL_FACTOR	16
#define	TINY_FACTOR		4
#define	SECOND_SMALL	0b1
#define	SECOND_TINY		0b10
#define MAX_MALLOCS 128
char 	g_second_alloc;

typedef struct s_mem
{
	struct	s_mem *next;
	struct	s_mem *prev;
	size_t	size;
	char	is_empty;
	void	*ptr;
}			t_mem;

typedef struct s_zones
{
	t_mem 	*tiny;
	t_mem	*small;
	t_mem	*large;
}							t_zones;

typedef struct  s_params
{
	t_zones *zones;
	t_mem	*mem;
	int		pointer_size;
	int 	zone_size;
}			t_params;

void	*ft_malloc(size_t size);


void	*ft_tiny(size_t size);
void	*ft_small(size_t size);
void	*ft_large(size_t size);



void	*mini_mmap(size_t size, void *add);

#endif
