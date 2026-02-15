/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:00:05 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/15 15:38:42 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static bool hanging(t_lst *ptr, t_lst *next, t_lst *tail, unsigned int size)
{
	if (ptr->index == 0 && tail->index == (size - 1))
		return (false);
	else if (ptr->index == (size - 1) && ptr->next->index == 0)
		return (false);
	else if (ptr->index > next->index && ptr->index < tail->index)
		return (true);
	else
		return (false);
}

static bool	find_quickest_route(t_lst *ptr, t_lst *tail, int size)
{
	int				up;
	int				down;

	up = 0;
	down = 0;
	while (ptr && !hanging(ptr, ptr->next, tail, size))
	{
		ptr = ptr->next;
		down++;
	}
	ptr = tail;
	while (ptr && !hanging(ptr, ptr->next, tail, size))
	{
		ptr = ptr->prev;
		up++;
	}
	if (up <= down)
		return (true);
	else
		return (false);
}

static bool	wrong_pair(t_lst *a, t_lst *b, int size)
{
	int				result;

	result = (b->index - a->index) % size;
	if (result == -1 || result == -(size - 1))
		return (true);
	else
		return (false);
}

static void	find_insertion(t_stack *a, t_stack *b, int size)
{
	int				b_inx;
	int				h_inx;
	int				t_inx;

	pb(a, b);
	while (1)
	{
		b_inx = b->head->index;
		h_inx = a->head->index;
		t_inx = a->tail->index;
		if (wrong_pair(a->head, a->head->next, size))
			sa(a, true);
		if (b_inx < h_inx && b_inx > t_inx)
		{
			pa(a, b);
			break ;
		}
		else if (b_inx < h_inx && b_inx < h_inx)
			rra(a, true);
		else
			ra(a, true);
	}
}

void	insertion_sort(t_stack *a, t_stack *b, t_strategy *strategy)
{
	bool			sorted;

	sorted = false;
	index_list(a, strategy->total);
	while (!sorted)
	{
		if (wrong_pair(a->head, a->head->next, strategy->total))
			sa(a, true);
		if (hanging(a->head, a->head->next, a->tail, strategy->total))
			find_insertion(a, b, strategy->total);
		else if (find_quickest_route(a->head, a->tail, strategy->total))
			rra(a, true);
		else
			ra(a, true);
		if (!b->head)
			sorted = is_sorted(a->head);
	}
}
