/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:00:54 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/10 15:19:32 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"		// ojo

static void	reverse_rotate(t_lst **s, t_lst **tail)
{
	t_lst		*ptr;

	if (!*s || !(*s)->next)
		return ;
	ptr = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	ptr->next = *s;
	(*s)->prev = ptr;
	*s = ptr;
	(*s)->prev = NULL;
}

void	rra(t_lst **a, t_lst **tail_a)
{
	reverse_rotate(a, tail_a);
}

void	rrb(t_lst **b, t_lst **tail_b)
{
	reverse_rotate(b, tail_b);
}

void	rrr(t_lst **a, t_lst **b, t_lst **tail_a, t_lst **tail_b)
{
	ra(a, tail_a);
	rb(b, tail_b);
}
