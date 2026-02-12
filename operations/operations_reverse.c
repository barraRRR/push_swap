/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:00:54 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/12 18:45:36 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"		// ojo

static void	reverse_rotate(t_stack *s)
{
	t_lst		*ptr;

	if (!s->head || !s->head->next)
		return ;
	ptr = s->tail;
	s->tail = ptr->prev;
	s->tail->next = NULL;
	ptr->next = s->head;
	s->head->prev = ptr;
	s->head = ptr;
	s->head->prev = NULL;
}

void	rra(t_stack *a, bool print)
{
	reverse_rotate(a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b, bool print)
{
	reverse_rotate(b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	ra(a, false);
	rb(b, false);
	ft_putstr_fd("rrr\n", 1);
}
