/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:54:01 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/09 16:51:32 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_lst *a)
{
	t_lst		*ptr;
	t_lst		*tmp;

	if (a && a->next)
	{
		tmp = a->next->next;
		a->next->next = a;
		a->next = tmp;
		a->next->next->prev = a->prev;

		
	}
}

void	sb(t_lst *b)
{
	t_lst		*ptr;
	t_lst		*tmp;

	if (b && b->next)
	{
		ptr = b;
		ptr = ptr->next;
		tmp = b;
		b = ptr;
		ptr = tmp;
	}
}

void	ss(t_lst *a, t_lst *b)
{
	sa(a);
	sb(b);
}

void	pb(t_lst *a, t_lst *b)
{
	t_lst		*ptr;
	t_lst		*tmp;

	if (!b)
		return ;
	