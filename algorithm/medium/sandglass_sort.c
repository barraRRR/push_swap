/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandglass_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:12:12 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/14 11:43:01 by jbarreir         ###   ########.fr       */
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
	if (modulo_index < half_chunk)
		rb(b, true);
}

static bool	is_pushable(int target, int moved_items, int r)
{
	if (target <= moved_items)
		return (true);
	else if (target <= (moved_items + r))
		return (true);
	else
		return (false);
}		

static int	push(t_stack *a, t_stack *b, bool rr, bool rb)
{
	pb
	if rr
		rr
	else if rb
		rb
	return (1);
}

static void to_b(t_stack *a, t_stack *b, int size, int r)
{
	int				moved_items;
	bool			next;

	moved_items = 0;
	while (a->head)
	{
		if (a->head->next)
			next = is_pushable(a->head->next->value, moved_items, r);
		if (!next && (a->head->index <= moved_items))
			pb
			rr
			moved_items++;
		else if (a->head->index <= moved_items)
			pb
			rb
			moved_items++
		else if (a->head->index <= (moved_items + r))
			pb
			moved_items++;
		else
			ra
	}
}

static void	back_to_a(t_stack *a, t_stack *b, int size)
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

void	sandgalss_sort(t_stack *a, t_stack *b, t_strategy *strategy)
{
	int				r;
	int				moved_items;

	r = (int)(newton_sqrt((float)strategy->total) * 2.0);
	index_list(a, strategy->total);
	to_b(a, b, strategy->total, r);
	back_to_a(a, b, strategy->total);
}
