/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsole-a <edsole-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:08:46 by edsole-a          #+#    #+#             */
/*   Updated: 2026/02/13 17:48:13 by edsole-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void normalize_stack(t_stack *a)
{
    t_lst   *current;
    t_lst   *compare;
    int     	rank;

    current = a->head;
    while (current)
    {
        rank = 0;
        compare = a->head;
        while (compare)
        {
            if (compare->value < current->value)
                rank++;
            compare = compare->next;
        }
        current->value = rank;
        current = current->next;
    }
}

static int get_max_bits(int size)
{
    int	bits;
    int	max_num;

    max_num = size - 1;
    bits = 0;
    while (max_num > 0)
    {
        max_num >>= 1;
        bits++;
    }
    return (bits);
}

void radix_sort(t_stack *a, t_stack *b)
{
    int size;
    int max_bits;
    int i;
    int j;

    normalize_stack(a);
    size = ft_lstsize(a->head);
    max_bits = get_max_bits(size);
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if (((a->head->value >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a, true);
            j++;
        }
        while (b->head)
            pa(a, b);
        
        i++;
    }
}
