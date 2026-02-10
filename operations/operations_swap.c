/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:54:01 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/10 15:19:45 by jbarreir         ###   ########.fr       */
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
