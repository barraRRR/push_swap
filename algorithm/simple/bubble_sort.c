/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:56:22 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/12 16:17:45 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	move_to_top(t_stack *a, int low)
{
	sa(a, true);
	if (a->head->value != low)
		ra(a, true);
}

void	selection_sort(t_stack *a, t_stack *b)
{
	int			low;

	while (a->head)
	{
		low = find_lowest(a->head);
		while (a->head->value != low)
			move_to_top(a, low);
		pb(a, b);
	}
	while (b->head)
		pa(a, b);
}
