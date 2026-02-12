/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:07:54 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/12 11:09:03 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"		// ojo

static void	push(t_stack *a, t_stack *b)
{
	t_lst			*tmpb;

	tmpb = b->head;
	b->head = b->head->next;
	if (b->head)
		b->head->prev = NULL;
	tmpb->next = a->head;
	if (a->head)
		a->head->prev = tmpb;
	a->head = tmpb;
	a->head->prev = NULL;
	if (!a->head->next)
		a->tail = a->head; 
}

void	pa(t_stack *a, t_stack *b)
{
	if (!b->head)
		return ;
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a->head)
		return ;
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
