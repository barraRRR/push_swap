/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:05:50 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/17 10:09:36 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"		// ojo

static void	rotate(t_stack *s)
{
	t_lst		*tmp;

	if (!s->head || !s->head->next)
		return ;
	tmp = s->head;
	s->head = tmp->next;
	s->head->prev = NULL;
	tmp->next = NULL;
	tmp->prev = s->tail;
	s->tail->next = tmp;
	s->tail = tmp;
}

void	ra(t_stack *a, bool print, t_bench *bench)
{
	rotate(a);
	if (print)
		ft_putstr_fd("ra\n", 1);
	bench->ra++;
}

void	rb(t_stack *b, bool print, t_bench *bench)
{
	rotate(b);
	if (print)
		ft_putstr_fd("rb\n", 1);
	bench->rb++;
}

void	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	ra(a, false, bench);
	rb(b, false, bench);
	ft_putstr_fd("rr\n", 1);
	bench->rr++;
}
