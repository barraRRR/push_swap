/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:54:01 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/16 18:57:41 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	//ojo

static void	swap(t_stack *s)
{
	int			tmp;

	tmp = s->head->value;
	s->head->value = s->head->next->value;
	s->head->next->value = tmp;
}

void	sa(t_stack *a, bool print, t_bench *bench)
{
	if (a->head && a->head->next)
	{
		swap(a);
		if (print && !bench->enabled)
			ft_putstr_fd("sa\n", 1);
		bench->sa++;
	}
}

void	sb(t_stack *b, bool print, t_bench *bench)
{
	if (b->head && b->head->next)
	{
		swap(b);
		if (print && !bench->enabled)
			ft_putstr_fd("sb\n", 1);
		bench->sb++;
	}
}

void	ss(t_stack *a, t_stack *b, t_bench *bench)
{
	sa(a, false, bench);
	sb(b, false, bench);
	if (!bench->enabled)
		ft_putstr_fd("ss\n", 1);
	bench->ss++;
}
