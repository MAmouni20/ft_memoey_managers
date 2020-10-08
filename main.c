/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 01:36:30 by mmostafa          #+#    #+#             */
/*   Updated: 2020/10/03 20:24:57 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"
#include <string.h>

int main()
{
	char *ptr = ft_malloc(17);
	ptr = ft_malloc(17);
	ptr = ft_malloc(17);
	ptr = memcpy(ptr, strdup("mostafa's system"), 17);
   
	t_zone  *tinies;
	t_mem   *tiny;
	t_mem   *tiny_head;
	t_zone   *tinies_head;


	tinies = g_zones.tinies;
	tiny = tinies->zone;
	tiny_head = tiny;
	tinies_head = tinies;
	int i=0;
	int j=0;
	while (tinies_head)
	{
		tiny_head = tinies_head->zone;
		printf("list %d\n", j);
		while (tiny_head)
		{
			printf("ptr %c,%zu %s\n", tiny_head->is_empty, tiny_head->size,tiny_head->ptr);
			tiny_head = tiny_head->next;
			i++;
		}
		tinies_head = tinies_head->next;
		j++;
	}
	printf("JJ == %d, II == %d\n", j, i);
	return (0);
}