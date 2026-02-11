/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:56:22 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/11 18:13:16 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	bubble_sort(t_lst **a, t_lst **b, t_strategy *strategy)
{
	int				i;

	i = 0;
	while (*a)
	{
		while (i < (strategy->total - 1))
		{
			if ((*a)->value > (*a)->next->value)
				sa(a, true);
			ra(a, &strategy->tail_a, true);
		}
		pb(b, a, &strategy->tail_b);
	}
	while (*b)
		pa(a, b, &strategy->tail_a);
}
