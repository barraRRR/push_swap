/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:12:12 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/13 18:53:33 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static bool	is_in_chunk(int target, int chunk_size, int rounds)
{
	int				top;
	int				bottom;

	top = chunk_size + (chunk_size * rounds);
	bottom = 0 + (chunk_size * rounds);
	if (target >= bottom && target < top)
		return (true);
	else
		return (false);
}

static void push_chunk(t_stack *a, t_stack *b, int chunk_size)
{
	int				half_chunk;
	int				modulo_index;

	half_chunk = chunk_size / 2;
	modulo_index = a->head->index % chunk_size;
	pb(a, b);
	if (modulo_index <= half_chunk)
		rb(b, true);
}

static void chunk_to_b(t_stack *a, t_stack *b, int size, int chunk_size)
{
	int				moved_items;
	int				rounds;
	int				target_index;

	rounds = 0;
	target_index = 0;
	while (a->head)
	{
		moved_items = 0;
		while (a->head && (moved_items < chunk_size))
		{
			if (is_in_chunk(a->head->index, chunk_size, rounds))
			{
				push_chunk(a, b, chunk_size);
				
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

static void	chunk_back_to_a(t_stack *a, t_stack *b, int size)
{
	int				high;

	while (b->head)
	{
		high = find_highest(b->head);
		if (b->head->value == high)
		{
			pa(a, b);
			size--;
		}
		else if (is_target_on_top(b->head, high, size))
		{
			while (b->head->value != high)
				rb(b, true);
		}
		else
		{
			while (b->head->value != high)
				rrb(b, true);
		}
	}
}

void	chunk_sort(t_stack *a, t_stack *b, t_strategy *strategy)
{
	int				chunk_size;

	if (strategy->total < 10)				 	// me petaba con pocos números
		chunk_size = strategy->total;
	else if (strategy->total < 50)
		chunk_size = strategy->total / 3;
	else
		chunk_size = ft_sqrt(strategy->total) * 3;
	index_list(a, strategy->total);
	chunk_to_b(a, b, strategy->total, chunk_size);
	chunk_back_to_a(a, b, strategy->total);
}
