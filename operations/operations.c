/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:54:01 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/10 12:26:16 by jbarreir         ###   ########.fr       */
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

void	push(t_lst **a, t_lst **b)
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
}

void	pa(t_lst **a, t_lst **b)
{
	push(a, b);
}

void	pb(t_lst **b, t_lst **a)
{
	push(b, a);
}

void	rotate(t_lst **s)
{
	t_lst		*ptr;
	t_lst		*tmp;

	if (!*s || !(*s)->next)
		return ;
	ptr = *s;
	tmp = *s;
	while (ptr->next)
		ptr = ptr->next;		// cambiar si implementamos variable total (size) en strategy
	*s = (*s)->next;
	(*s)->prev = NULL;
	ptr->next = tmp;
	tmp->prev = ptr;
	tmp->next = NULL;
}
