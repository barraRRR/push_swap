/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:56:22 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/11 17:59:48 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
