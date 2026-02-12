/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:56:22 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/12 18:50:27 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"


static bool	is_top(int i, int total)
{
	float		result;

	result = (float)i / (float)total;
	if (result <= 0.5)
		return (true);
	else
		return (false);
}

static int	selection_find_lowest(t_lst *n, bool *top)
{
	int			low;
	int			i;
	int			total;
	t_lst		*ptr;

	low = n->value;
	i = 0;
	total = 0;
	ptr = n;
	while (ptr)
	{
		if (ptr->value < low)
			low = ptr->value;
		ptr = ptr->next;
		total++;
	}
	while (n)
	{
		if (n->value == low)
			break ;
		i++;
		n = n->next;
	}
	*top = is_top(i, total);
	return (low);
}

static void	move_to_top(t_stack *a, int low)
{
	while (a->head->value != low)
		ra(a, true);
}

static void	move_from_bottom(t_stack *a, int low)
{
	
	while (a->tail->value != low)
		rra(a, true);
	rra(a, true);
}

void	selection_sort(t_stack *a, t_stack *b)
{
	int			low;
	bool		top;

	top = true;
	while (a->head->next)
	{
		low = selection_find_lowest(a->head, &top);
		if (top)
			move_to_top(a, low);
		else
			move_from_bottom(a, low);
		pb(a, b);
	}
	while (b->head)
		pa(a, b);
}
