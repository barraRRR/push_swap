/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_selector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:22:39 by edsole-a          #+#    #+#             */
/*   Updated: 2026/02/15 17:19:05 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_selector(t_stack *a, t_stack *b, t_strat *strategy,
	t_bench *bench)
{
	float			disorder;

	disorder = compute_disorder(a->head);
	if (strategy->complex == SIMPLE)
		insertion_sort(a, b, strategy, bench);
	else if (strategy->complex == MEDIUM)
		sandglass_sort(a, b, strategy, bench);
	else if (strategy->complex == COMPLEX)
		radix_sort(a, b, bench);
	else if (strategy->total <= 3)
		tiny_sort(a, bench);
	else if (strategy->total <= 5 || disorder < 0.2)
		insertion_sort(a, b, strategy, bench);
	else if (0.2 <= disorder && disorder < 0.5)
		sandglass_sort(a, b, strategy, bench);
	else
		radix_sort(a, b, bench);
}
