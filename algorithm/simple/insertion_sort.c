/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:00:05 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/15 18:41:15 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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

static void move_up(t_stack *a, int target, t_bench *bench)
{
	while (a->head->value != target)
		ra(a, true, bench);
}

static void move_down(t_stack *a, int target, t_bench *bench)
{
	while (a->tail->value != target)
		rra(a, true, bench);
	rra(a, true, bench);
}

void	insertion_sort(t_stack *a, t_stack *b, t_strat *strategy,
	t_bench *bench)
{
	int				low;
	int				i;
	int				size;

	size = strategy->total;
	while (size > 3)
	{
		low = find_lowest(a->head);
		i = find_low_index(a->head, low);
		if (i <= ((size - 1) / 2))
			move_up(a, low, bench);
		else
			move_down(a, low, bench);
		pb(a, b, bench);
		size--;
	}
	tiny_sort(a, bench);
	while (b->head)
		pa(a, b, bench);
}
