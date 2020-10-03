/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 01:36:30 by mmostafa          #+#    #+#             */
/*   Updated: 2020/10/03 00:54:09 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_managers.h"

int main()
{
    ft_malloc(33);
    ft_malloc(33);
    ft_malloc(33);
    ft_malloc(33);
    ft_malloc(33);
    ft_malloc(33);
    ft_malloc(33);
    ft_malloc(33);
    ft_malloc(33);
    ft_malloc(33);
    ft_malloc(33);
    ft_malloc(33);
    ft_malloc(33);
    ft_malloc(33);
   
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
        while (tiny_head)
        {
            printf("ptr %c\n", tiny_head->is_empty);
            tiny_head = tiny_head->next;
            i++;
        }
        printf("list = %p\n", g_zones.tinies);
        tinies_head = tinies_head->next;
        j++;
    }
    printf("JJ == %d, II == %d\n", j, i);
    return (0);
}