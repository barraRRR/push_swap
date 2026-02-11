/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:00:54 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/11 07:50:19 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"		// ojo

static void	reverse_rotate(t_lst **s, t_lst **tail)
{
	t_lst		*ptr;

	if (!*s || !(*s)->next)
		return ;
	ptr = *tail;
	(*s)->prev = ptr;
	ptr->next = *s;
	*s = ptr;
	(*s)->prev = NULL;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
}

void	rra(t_lst **a, t_lst **tail_a)
{
	reverse_rotate(a, tail_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_lst **b, t_lst **tail_b)
{
	reverse_rotate(b, tail_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_lst **a, t_lst **b, t_lst **tail_a, t_lst **tail_b)
{
	ra(a, tail_a);
	rb(b, tail_b);
	ft_putstr_fd("rrr\n", 1);
}
