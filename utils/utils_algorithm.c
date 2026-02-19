/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:59:09 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/19 11:44:08 by jbarreir         ###   ########.fr       */
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

int	find_next_lowest(t_lst *n, int prev_low)
{
	int			next_low;

	next_low = INT_MAX;
	while (n)
	{
		if (n->value > prev_low && n->value < next_low)
			next_low = n->value;
		n = n->next;
	}
	return (next_low);
}

void	index_list(t_stack *s, int size)
{
	int				low;
	int				i;
	t_lst			*ptr;

	i = 0;
	low = find_lowest(s->head);
	ptr = s->head;
	while (ptr && i < size)
	{
		ptr = s->head;
		while (ptr)
		{
			if (ptr->value == low)
			{
				ptr->index = i;
				break ;
			}
			ptr = ptr->next;
		}
		low = find_next_lowest(s->head, low);
		i++;
	}
}

bool	is_target_on_top(t_lst *n, int target, unsigned int size)
{
	unsigned int		i;
	unsigned int		pos;

	i = 0;
	pos = (size - 1) / 2;
	while (n)
	{
		if (n->value == target && i <= pos)
			return (true);
		else if (n->value == target && i > pos)
			return (false);
		else
		{
			n = n->next;
			i++;
		}
	}
	return (true);
}
