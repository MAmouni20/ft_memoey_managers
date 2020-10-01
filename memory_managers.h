/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_managers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:15:56 by mmostafa          #+#    #+#             */
/*   Updated: 2020/10/01 23:17:55 by mmostafa         ###   ########.fr       */
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

typedef struct s_mem
{
	struct	s_mem *next;
	struct	s_mem *prev;
	size_t	size;
	char	is_empty;
	void	*ptr;
}			t_mem;

typedef struct s_zone
{
	t_mem	*zone;
	struct s_zone *next;
	struct s_zone *prev;
}				t_zone;

typedef struct s_zones
{
	size_t	requested_size;
	t_zone 	tinies;
	t_zone	smalls;
	t_zone	larges;
	int		page_size;
}							t_zones;


void	*ft_malloc(size_t size);


void	*ft_tiny();
void	*ft_small();
void	*ft_large();



void	*mini_malloc(size_t size, void *add);

t_zones	g_zones;
#endif
