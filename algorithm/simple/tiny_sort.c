/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:56:22 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/12 14:55:14 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	tiny_sort(t_stack *a)
{
	int			high;

	high = find_highest(a->head);
	if (a->head->value == high)
	{
		ra(a, true);
		if (a->head->value > a->head->next->value)
			sa(a, true);
	}
	else if (a->head->next->value == high)
	{
		sa(a, true);
		ra(a, true);
		if (a->head->value > a->head->next->value)
			sa(a, true);
	}
	else
		if (a->head->value > a->head->next->value)
			sa(a, true);
}
