/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:36:23 by mmostafa          #+#    #+#             */
/*   Updated: 2020/10/03 00:58:03 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"


static void   create_small_list()
{
	t_zone  *smalls;
    t_mem   *small;
    int     i;
    t_mem   *head;

    g_zones.smalls = (t_zone *)mini_malloc(sizeof(t_zone), 0);
    smalls = g_zones.smalls;
    smalls->zone = (t_mem *)mini_malloc(sizeof(t_mem), 0);
    small = smalls->zone;
    small->ptr = mini_malloc(small->size, 0);
    small->is_empty = 'F';
    small->size = g_zones.requested_size;
    small->prev = NULL;
    head = small;
    small->next = (t_mem *)mini_malloc(sizeof(t_mem), 0);
    small->next->prev = small;
    i = 1;
    while (i < MAX_MALLOCS)
    {
        small = small->next;
        small->ptr = mini_malloc(small->size, 0);
        small->is_empty = 'E';
        small->size = g_zones.requested_size;
        small->next = (t_mem *)mini_malloc(sizeof(t_mem), 0);
        small->next->prev = small;
        i++;
    }
    small->next = NULL;
    small = head;
}

static void    *search_in_small_list()
{
	t_zone  *smalls;
    t_mem   *small;
    t_mem   *small_head;
    t_zone   *smalls_head;


    smalls = g_zones.smalls;
    small = smalls->zone;
    small_head = small;
    smalls_head = smalls;
    while (smalls_head)
    {
        while (small_head)
        {  
            if (small_head->is_empty == 'E')
            {
                small_head->is_empty = 'F';
                return (small_head->ptr);
            }
            small_head = small_head->next;
        }
        if (!smalls_head->next)
        {
            create_small_list();
            smalls_head->next = g_zones.smalls;
            g_zones.smalls->prev = smalls_head;
            g_zones.smalls = smalls;
            break ;
        }
        smalls_head = smalls_head->next;
    }
    return (g_zones.smalls->zone->ptr);
}

void    *ft_small()
{
    if (g_zones.smalls)
		return (search_in_small_list());
	create_small_list();
	return (g_zones.smalls->zone->ptr);
}