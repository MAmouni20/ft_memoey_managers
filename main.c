/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 01:36:30 by mmostafa          #+#    #+#             */
/*   Updated: 2020/10/16 00:29:21 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"
#include <string.h>

int main()
{
	int	i;
	int j;
	char *tmp;
	char *ptr;

	i = 0;
	while (i < 10)
	{
		if (i == 6)
		{
			tmp = ft_malloc(128);
			tmp = memcpy(tmp, strdup("iubuscwruuoqvvcpbkasurhfqxcgwfjacjkxuqqvzhrufjgmozgammshegxqlpksexbsqgdhkbdnrpmkxlwjteniuubtvlsltfgxbdkdrlpkwzhitwegsnqwynywsfbw"), 128);
		}
		else
		{
			ptr = ft_malloc(128);
			ptr = memcpy(ptr, strdup("iubuscwruuoqvvcpbkasurhfqxcgwfjacjkxuqqvzhrufjgmozgammshegxqlpksexbsqgdhkbdnrpmkxlwjteniuubtvlsltfgxbdkdrlpkwzhitwegsnqwynywsfbw"), 128);	
		}
		i++;
	}
	ft_free(tmp);
	tmp = ft_malloc(128);
	//tmp = memcpy(tmp, strdup("iubuscwruuoqvvcpbkasurhfqxcgwfjacjkxuqqvzhrufjgmozgammshegxqlpksexbsqgdhkbdnrpmkxlwjteniuubtvlsltfgxbdkdrlpkwzhitwegsnqwynywsfbw"), 128);
	t_zone  *zones_list;
	t_mem   *zone;
	t_mem   *zone_head;
	t_zone   *zones_list_head;


	printf("in main %p\n", g_zones.tinies);
	zones_list = g_zones.tinies;
	zone = zones_list->zone;
	zone_head = zone;
	zones_list_head = zones_list;
	i = 0;
	j = 0;
	while (zones_list_head)
	{
		zone_head = zones_list_head->zone;
		printf("list %d\n", j);
		while (zone_head)
		{
			printf("ptr %c ,%zu, ", zone_head->is_empty, zone_head->size);
			if (zone_head->size > 0)
				printf("%s", zone_head->ptr);
			printf("\n");
			zone_head = zone_head->next;
			i++;
		}
		zones_list_head = zones_list_head->next;
		j++;
	}
	printf("JJ == %d, II == %d\n", j, i);
	return (0);
}