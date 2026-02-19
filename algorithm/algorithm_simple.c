/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:00:05 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/19 11:44:32 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	tiny_sort(t_stack *a, t_bench *bench)
{
	int			high;

	high = find_highest(a->head);
	if (a->head->value == high)
	{
		ra(a, true, bench);
		if (a->head->value > a->head->next->value)
			sa(a, true, bench);
	}
	else if (a->head->next->value == high)
	{
		sa(a, true, bench);
		ra(a, true, bench);
		if (a->head->value > a->head->next->value)
			sa(a, true, bench);
	}
	else if (a->head->value > a->head->next->value)
		sa(a, true, bench);
}

void	selection_sort(t_stack *a, t_stack *b, t_strat *strategy,
	t_bench *bench)
{
	int				target;
	int				size;

	size = strategy->total;
	while (size > 3)
	{
		target = find_lowest(a->head);
		if (is_target_on_top(a->head, target, size))
		{
			while (a->head->value != target)
				ra(a, true, bench);
		}
		else
		{
			while (a->head->value != target)
				rra(a, true, bench);
		}
		pb(a, b, bench);
		size--;
	}
	tiny_sort(a, bench);
	while (b->head)
		pa(a, b, bench);
}
