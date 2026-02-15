/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:56:22 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/15 15:34:06 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	move_to_top(t_stack *a, int target)
{
	while (a->head->value != target)
		ra(a, true);
}

static void	move_from_bottom(t_stack *a, int target)
{
	
	while (a->tail->value != target)
		rra(a, true);
	rra(a, true);
}

void	selection_sort(t_stack *a, t_stack *b, t_strategy *strategy)
{
	int			low;
	int			size;
	int			i;

	size = strategy->total;
	while (a->head->next)
	{
		low = find_lowest(a->head);
		i = find_low_index(a->head, low);
		if (i <= ((size - 1) / 2))				// doble checkear esya operacion matematica, que no he probado con el - 1
			move_to_top(a, low);
		else
			move_from_bottom(a, low);
		pb(a, b);
		size--;
	}
	while (b->head)
		pa(a, b);
}
