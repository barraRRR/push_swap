/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:54:01 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/12 10:42:03 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"	//ojo

static void	swap(t_stack *s)
{
	int			tmp;
	
	tmp = s->head->value;
	s->head->value = s->head->next->value;
	s->head->next->value = tmp;
}

void	sa(t_stack *a, bool print)
{
	if (a->head && a->head->next)
		swap(a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b, bool print)
{
	if (b->head && b->head->next)
		swap(b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, false);
	sb(b, false);
	ft_putstr_fd("ss\n", 1);
}
