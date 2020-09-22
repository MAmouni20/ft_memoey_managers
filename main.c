/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mostafamamouni <mostafamamouni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:01:34 by mmostafa          #+#    #+#             */
/*   Updated: 2020/09/17 15:01:12 by mostafamamo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define	SECOND_SMALL	0b1
#define	SECOND_TINY		0b10
#define MAX_MALLOCS 100
#define TINY 1024
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
	t_mem 	tiny;
	t_mem	small;
	t_mem	large;
}							t_zones;

void	*ft_mem_factory(char area)
{
	
}

void	*ft_small()
{
	if ((g_second_alloc & SECOND_SMALL) == SECOND_SMALL)
		printf ("2ND\n");
	else
	{
		g_second_alloc = 1;
		printf("1ST\n");
	}
	return (NULL);
}

void	*ft_large()
{
	return (NULL);
}

void	*ft_tiny()
{
	t_mem	zone;

	if ((g_second_alloc & SECOND_TINY) == SECOND_TINY)
		printf ("2ND\n");
	else
	{
		g_second_alloc = 2;
		printf("1ST\n");
	}
	return(NULL);
	//return(ft_zone_factory('T'));
}

void	*ft_malloc(size_t size)
{
	if (size >= 1 && size <= 1024)
		return(ft_tiny());
	else if (size >= 1025 && size <= 2048)
		return(ft_small());
	else if (size > 4098)
		return(ft_large());
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
	ft_malloc(50);
	ft_malloc(50);
	printf("\n\nSMALL\n\n");
	printf("FIRST CALL\n");
	ft_malloc(2000);
	printf("SECOND CALL\n");
	ft_malloc(2000);
	ft_malloc(2000);
	ft_malloc(2000);
	return (0);
}
