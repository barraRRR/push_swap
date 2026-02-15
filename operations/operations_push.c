/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:07:54 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/15 16:49:48 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"		// ojo

static void	push(t_stack *a, t_stack *b)
{
	t_lst			*ptr;

	ptr = b->head;
	b->head = b->head->next;
	if (b->head)
		b->head->prev = NULL;
	else
		b->tail = NULL;
	ptr->next = a->head;
	if (a->head)
		a->head->prev = ptr;
	a->head = ptr;
	a->head->prev = NULL;
	if (!a->head->next)
		a->tail = a->head; 
}

void	pa(t_stack *a, t_stack *b, t_bench *bench)
{
	if (!b->head)
		return ;
	push(a, b);
	if (!bench->enabled)
		ft_putstr_fd("pa\n", 1);
	bench->pa++;
}

void	pb(t_stack *a, t_stack *b, t_bench *bench)
{
	if (!a->head)
		return ;
	push(b, a);
	if (!bench->enabled)
		ft_putstr_fd("pb\n", 1);
	bench->pb++;
}
