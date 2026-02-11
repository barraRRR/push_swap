/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:54:01 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/11 09:48:28 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"	//ojo

void	swap(t_lst **s)
{
	int			tmp;
	
	tmp = (*s)->value;
	(*s)->value = (*s)->next->value;
	(*s)->next->value = tmp;
}

void	sa(t_lst **a, bool print)
{
	if (*a && (*a)->next)
		swap(a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_lst **b, bool print)
{
	if (*b && (*b)->next)
		swap(b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_lst **a, t_lst **b)
{
	sa(a, false);
	sb(b, false);
	ft_putstr_fd("ss\n", 1);
}
