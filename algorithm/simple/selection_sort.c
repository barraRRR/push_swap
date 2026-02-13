/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:56:22 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/13 15:17:47 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	move_to_top(t_stack *a, int low)
{
	while (a->head->value != low)
		ra(a, true);
}

static void	move_from_bottom(t_stack *a, int low)
{
	
	while (a->tail->value != low)
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
