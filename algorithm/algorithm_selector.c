/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_selector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:22:39 by edsole-a          #+#    #+#             */
/*   Updated: 2026/02/15 08:12:13 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_selector(t_stack *a, t_stack *b, t_strategy *strategy)
{
	float			disorder;

	disorder = compute_disorder(a->head);
	if (strategy->complex == SIMPLE)
		selection_sort(a, b, strategy);
	else if (strategy->complex == MEDIUM)
		sandglass_sort(a, b, strategy);
	else if (strategy->complex == COMPLEX)
		radix_sort(a, b);
	else if (strategy->total <= 3)
		tiny_sort(a);
	else if (strategy->total <= 5 || disorder < 0.2)
		selection_sort(a, b, strategy);
	else if (0.2 <= disorder && disorder < 0.5)
		sandglass_sort(a, b, strategy);
	else
		radix_sort(a, b);
}
