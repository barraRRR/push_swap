/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:59:09 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/12 16:12:39 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_highest(t_lst *n)
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

int	find_lowest(t_lst *n)
{
	int			low;

	low = n->value;
	while (n)
	{
		if (n->value < low)
			low = n->value;
		n = n->next;
	}
	return (low);
}
