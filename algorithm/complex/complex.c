/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsole-a <edsole-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:08:46 by edsole-a          #+#    #+#             */
/*   Updated: 2026/02/16 19:04:07 by edsole-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	get_max_bits(int size)
{
	int	bits;
	int	max_num;

	max_num = size - 1;
	bits = 0;
	while ((max_num >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b, t_strat *strategy, t_bench *bench)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = strategy->total;
	index_list(a, size);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->head->index >> i) & 1) == 0)
				pb(a, b, bench);
			else
				ra(a, true, bench);
			j++;
		}
		while (b->head)
			pa(a, b, bench);
		i++;
	}
}
