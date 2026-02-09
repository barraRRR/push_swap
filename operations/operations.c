/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:54:01 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/09 18:58:33 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_node(t_lst **n1, t_lst **n2)
{
	t_lst		*tmp1_prev;
	t_lst		*tmp1_next;
	t_lst		*tmp2_prev;
	t_lst		*tmp2_next;
	t_lst		*tmp;

	tmp1_prev = (*n1)->prev;
	tmp1_next = (*n1)->next;
	tmp2_prev = (*n2)->prev;
	tmp2_next = (*n2)->next;
	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
	(*n1)->prev = tmp1_prev; 
	(*n1)->next = tmp1_next; 
	(*n2)->prev = tmp2_prev; 
	(*n2)->next = tmp2_next; 
}

void	sa(t_lst *a)
{
	if (a && a->next)
		swap_node(a, a->next);
}

void	sb(t_lst *b)
{
	if (b && b->next)
		swap_node(b, b->next);
}

void	ss(t_lst *a, t_lst *b)
{
	sa(a);
	sb(b);
}

void	pa(t_lst *a, t_lst *b)
{
	if (!b)
		return ;
