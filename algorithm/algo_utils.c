/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:59:09 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/13 12:49:45 by jbarreir         ###   ########.fr       */
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

/*
 *		Encuentra el número mínimo en el stack y su posición (low_index)
 */
int	find_lowest(t_lst *n, int *low_index)
{
	int			low;
	int			i;

	low = n->value;
	i = 1;
	*low_index = i;
	while (n)
	{
		if (n->value < low)
		{
			low = n->value;
			*low_index = i;
		}
		n = n->next;
		i++;
	}
	return (low);
}

int	find_next_lowest(t_lst *n, int prev_low, int *prev_low_index)
{
	int			next_low;

	while (n)
	{
		if (n->value < next_low && n->value)
		{
			low = n->value;
			*prev_low_index = i;
		}
		n = n->next;
		i++;
	}
	return (low);


void	index_list(t_stack *s, int size)
{
	int				low;

	low = find_lowest;
