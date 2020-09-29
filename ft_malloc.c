/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostafamamouni <mostafamamouni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:01:34 by mmostafa          #+#    #+#             */
/*   Updated: 2020/09/23 17:47:03 by mostafamamo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
char 	g_second_alloc = 0;

typedef struct s_mem
{
	void	*ptr;
	size_t	size;
	struct	s_mem *next;
	struct	s_mem *prev;

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


void	*mini_mmap(size_t size, void *add)
{
	return (mmap(add, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0));
}

void	*ft_search_inlist(t_zones *zone)
{
	(void)zone;
	return (NULL);
}

void	*ft_prepare_head(t_params params, char area_size, int size)
{
	params.zones = (t_zones *)mini_mmap(sizeof(t_zones), 0);
	if (area_size == 'S')
	{
	params.	mem = params.zones->small;
		params.zone_size = getpagesize() * SMALL_FACTOR;
		params.pointer_size = params.zone_size / MAX_MALLOCS;
		params.mem = (t_mem *)mini_mmap(sizeof(t_mem), 0);
		params.mem->ptr = mini_mmap(params.pointer_size, 0);
		params.mem->size = params.pointer_size;
		params.mem->prev = NULL;
	}
	if (area_size == 'T')
	{
		params.mem = params.zones->tiny;
		params.zone_size = getpagesize() * TINY_FACTOR;
		params.pointer_size = params.zone_size / MAX_MALLOCS;
		params.mem = (t_mem *)mini_mmap(sizeof(t_mem), 0);
		params.mem->ptr = mini_mmap(params.pointer_size, 0);
		params.mem->size = params.pointer_size;
		params.mem->prev = NULL;
	}
	if (area_size == 'L')
	{
		return (mini_mmap(size, 0));
	}
	return (NULL);
}

void	*ft_mem_factory(char area_size, size_t size)
{
	t_params *params;
	int		i;

	params = (t_params *)mini_mmap(sizeof(t_params), 0);
	printf("IS HERE\n");
	ft_prepare_head(*params, area_size, size);
	printf("IS HERE\n");
	i = 1;
	while (i <= MAX_MALLOCS)
	{
		
	}
	return (NULL);
}
void *ft_tiny(size_t size)
{
	t_zones		*zone = NULL;

	if ((g_second_alloc & SECOND_TINY) == SECOND_TINY)
	{
		ft_search_inlist(zone);
		printf("2ND\n");
	}
	else
	{
		zone = ft_mem_factory('T', size);
		g_second_alloc = 2;
		printf("1ST\n");
	}
	return (NULL);
}

void *ft_small(size_t size)
{
	t_zones		*zone = NULL;

	if ((g_second_alloc & SECOND_SMALL) == SECOND_SMALL)
	{
		ft_search_inlist(zone);
		printf("2ND\n");
	}
	else
	{
		zone = ft_mem_factory('S', size);
		g_second_alloc = 1;
		printf("1ST\n");
	}
	return (NULL);
}

void *ft_large(size_t size)
{
	ft_mem_factory('L', size);
	return (NULL);
}

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

int main(int ac, char **av)
{
	(void)av;
	(void)ac;
	printf("FIRST CALL\n");
	ft_malloc(50);
	printf("SECOND CALL\n");
	ft_malloc(50);
	printf("\n\nSMALL\n\n");
	printf("FIRST CALL\n");
	ft_malloc(200);
	printf("SECOND CALL\n");
	ft_malloc(200);
	printf("END CALL\n");
	ft_malloc(1000);
	return (0);
}
