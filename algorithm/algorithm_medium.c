/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:12:12 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/19 11:44:26 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static bool	is_pushable(int target, int moved_items, int r)
{
	if (target <= moved_items)
		return (true);
	else if (target <= (moved_items + r))
		return (true);
	else
		return (false);
}

static int	push(t_stack *a, t_stack *b, int do_r, t_bench *bench)
{
	pb(a, b, bench);
	if (do_r == 1)
		rr(a, b, bench);
	else if (do_r == 2)
		rb(b, true, bench);
	return (1);
}

static void	to_b(t_stack *a, t_stack *b, int r, t_bench *bench)
{
	unsigned int		moved_items;
	bool				next;

	moved_items = 0;
	next = false;
	while (a->head)
	{
		if (a->head->next)
			next = is_pushable(a->head->next->value, moved_items, r);
		if (!next && (a->head->index <= moved_items))
			moved_items += push(a, b, 1, bench);
		else if (a->head->index <= moved_items)
			moved_items += push(a, b, 2, bench);
		else if (a->head->index <= (moved_items + r))
			moved_items += push(a, b, 0, bench);
		else if (is_pushable(a->tail->index, moved_items, r))
			rra(a, true, bench);
		else
			ra(a, true, bench);
	}
}

static void	back_to_a(t_stack *a, t_stack *b, int size, t_bench *bench)
{
	int				high;

	while (b->head)
	{
		high = find_highest(b->head);
		if (b->head->value == high)
		{
			pa(a, b, bench);
			size--;
		}
		else if (is_target_on_top(b->head, high, size))
		{
			while (b->head->value != high)
				rb(b, true, bench);
		}
		else
		{
			while (b->head->value != high)
				rrb(b, true, bench);
		}
	}
}

void	hourglass_sort(t_stack *a, t_stack *b, t_strat *strategy,
	t_bench *bench)
{
	int				r;

	r = (int)(newton_sqrt((float)strategy->total) * 1.2);
	index_list(a, strategy->total);
	to_b(a, b, r, bench);
	back_to_a(a, b, strategy->total, bench);
}
