/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:12:12 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/13 17:44:44 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

bool	is_in_chunk(int target, int chunk_size, int rounds)
{
	int				top;
	int				bottom;

	top = chunk_size + (chunk_size * rounds);
	bottom = 0 + (chunk_size * rounds);
	if (target >= bottom && target <= top)
		return (true);
	else
		return (false);
}

// target distance

/*
void	push_chunk(t_stack *a, t_stack *b, int chunk_size)
{
	float			top;

	top = (float)a->head->index % (float)chunk_size;

}
*/

void	chunk_to_b(t_stack *a, t_stack *b, int size, int chunk_size)
{
	int				moved_items;
	int				rounds;
	int				target_index;

	rounds = 0;
	target_index = 0;
	while (a->head)
	{
		moved_items = 0;
		while (moved_items < chunk_size)
		{
			if (is_in_chunk(a->head->index, chunk_size, rounds))
			{
				pb(a, b);
				moved_items++;
				target_index++;
				size--;
			}
			else if (is_target_on_top(a->head, target_index, size))
				ra(a, true);
			else
				rra(a, true);
		}
		rounds++;
	}
}

void	chunk_back_to_a(t_stack *a, t_stack *b, int size)
{
	int				high;
	int 			size;

	while (b->head)
	{
		high = find_highest;
		if (b->head->value == high)
		{
			pa(a, b);
			size--;
		}
		else if (is_target_on_top(b->head, high, size))
			while (b->head->value != high)
				rb(b, true);
		else
			while (b->head->value != high)
				rrb(b, true);
	}
}

void	chunk_sort(t_stack *a, t_stack *b, t_strategy *strategy)
{
	int				chunk_size;

	chunk_size = ft_sqrt(strategy->total) * 2;
	index_list(a, strategy->total);
	chunk_to_b(a, b, strategy->total, chunk_size);
	chunk_back_to_a(a, b, strategy->total);
}
