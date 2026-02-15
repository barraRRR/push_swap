/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:56:22 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/15 16:02:21 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	move_up(t_stack *a, int target)
{
	while (a->head->value != target)
		ra(a, true);
}

static void	move_down(t_stack *a, int target)
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
			move_up(a, low);
		else
			move_down(a, low);
		pb(a, b);
		size--;
	}
	while (b->head)
		pa(a, b);
}
