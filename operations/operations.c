/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:54:01 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/10 13:22:12 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **s)
{
	int			tmp;
	
	tmp = (*s)->value;
	(*s)->value = (*s)->next->value;
	(*s)->next->value = tmp;
}

void	sa(t_lst **a)
{
	if (*a && (*a)->next)
		swap(a);
}

void	sb(t_lst **b)
{
	if (*b && (*b)->next)
		swap(b);
}

void	ss(t_lst **a, t_lst **b)
{
	sa(a);
	sb(b);
}

void	push(t_lst **a, t_lst **b, t_lst **tail)
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

void	rotate(t_lst **s, t_lst **tail)
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

void	reverse_rotate(t_lst **s, t_lst **tail)
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
