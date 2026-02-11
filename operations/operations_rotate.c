/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:05:50 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/11 09:44:29 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"		// ojo

static void	rotate(t_lst **s, t_lst **tail)
{
	t_lst		*tmp;

	if (!*s || !(*s)->next)
		return ;
	tmp = *s;
	*s = (*s)->next;
	(*s)->prev = NULL;
	(*tail)->next = tmp;
	tmp->prev = *tail;
	tmp->next = NULL;
	*tail = tmp;
}

void	ra(t_lst **a, t_lst **tail_a, bool print)
{
	rotate(a, tail_a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_lst **b, t_lst **tail_b, bool print)
{
	rotate(b, tail_b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_lst **a, t_lst **b, t_lst **tail_a, t_lst **tail_b)
{
	ra(a, tail_a, false);
	rb(b, tail_b, false);
	ft_putstr_fd("rr\n", 1);
}
