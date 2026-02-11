/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:56:22 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/11 15:46:19 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	find_highest(t_lst *n)
{
	int			high;

	high = n->value;
	while (n)
	{
		if (n->value > high)
			high = n->value;
		n = n->next;
	}
	return (high);
}

void	tiny_sort(t_lst **a, t_lst **tail_a)
{
	int			high;

	high = find_highest(*a);
	if ((*a)->value == high)
	{
		ra(a, tail_a, true);
		if ((*a)->value > (*a)->next->value)
			sa(a, true);
	}
	else if ((*a)->next->value == high)
	{
		sa(a, true);
		ra(a, tail_a, true);
		if ((*a)->value > (*a)->next->value)
			sa(a, true);
	}
	else
		if ((*a)->value > (*a)->next->value)
			sa(a, true);
}

void	high_five(t_lst **a, t_lst **b, t_strategy *strategy)
{
	if (strategy->total <= 3)
		tiny_sort(a, &strategy->tail_a);
	while (strategy->total > 3)
	{
		pb(b, a, &strategy->tail_b);
		strategy->total--;
	}
	

