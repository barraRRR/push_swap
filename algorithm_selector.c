/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_selector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:22:39 by edsole-a          #+#    #+#             */
/*   Updated: 2026/02/16 18:56:00 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_lst *a)
{
	float		mistakes;
	float		total_pairs;
	t_lst		*ptr;

	if (!a)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	while (a->next)
	{
		ptr = a->next;
		while (ptr)
		{
			total_pairs++;
			if (a->value > ptr->value)
				mistakes++;
			ptr = ptr->next;
		}
		a = a->next;
	}
	return (mistakes / total_pairs);
}

void	algo_selector(t_stack *a, t_stack *b, t_strat *strategy,
	t_bench *bench)
{
	float			disorder;

	disorder = compute_disorder(a->head);
	if (strategy->complex == SIMPLE)
		insertion_sort(a, b, strategy, bench);
	else if (strategy->complex == MEDIUM)
		hourglass_sort(a, b, strategy, bench);
	else if (strategy->complex == COMPLEX)
		radix_sort(a, b, strategy, bench);
	else if (strategy->total <= 5 || disorder < 0.2)
	{
		insertion_sort(a, b, strategy, bench);
		strategy->complex = SIMPLE;
	}
	else if (0.2 <= disorder && disorder < 0.5)
	{
		hourglass_sort(a, b, strategy, bench);
		strategy->complex = MEDIUM;
	}
	else
	{
		radix_sort(a, b, strategy, bench);
		strategy->complex = COMPLEX;
	}
}
