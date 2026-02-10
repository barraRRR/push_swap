/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:07:54 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/10 15:19:38 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"		// ojo

static void	push(t_lst **a, t_lst **b, t_lst **tail)
{
	t_lst			*tmpb;

	if (!b || !*b)
		return ;
	tmpb = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmpb->next = *a;
	if (*a)
		(*a)->prev = tmpb;
	*a = tmpb;
	(*a)->prev = NULL;
	if (!(*a)->next)
		*tail = *a; 
}

void	pa(t_lst **a, t_lst **b, t_lst **tail_a)
{
	push(a, b, tail_a);
}

void	pb(t_lst **b, t_lst **a, t_lst **tail_b)
{
	push(b, a, tail_b);
}
