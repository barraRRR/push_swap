/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:05:50 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/10 15:19:41 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"		// ojo

static void	rotate(t_lst **s, t_lst **tail)
{
	t_lst		*ptr;
	t_lst		*tmp;

	if (!*s || !(*s)->next)
		return ;
	ptr = *tail;
	tmp = *s;
	*s = (*s)->next;
	(*s)->prev = NULL;
	ptr->next = tmp;
	tmp->prev = ptr;
	tmp->next = NULL;
	*tail = tmp;
}

void	ra(t_lst **a, t_lst **tail_a)
{
	rotate(a, tail_a);
}

void	rb(t_lst **b, t_lst **tail_b)
{
	rotate(b, tail_b);
}

void	rr(t_lst **a, t_lst **b, t_lst **tail_a, t_lst **tail_b)
{
	ra(a, tail_a);
	rb(b, tail_b);
}
