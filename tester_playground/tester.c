/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:32:59 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/12 16:18:13 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	testing(t_stack *a, t_stack *b, t_strategy *strategy)
{
	t_lst		*ptr;

	printf("\nNumber of elements: %i\n\n", strategy->total);

	printf("\n*** TESTING ***\n\n");
	printf("%f\n\n", strategy->disorder);
	printf("_Columna A - Original_\n");
	ptr = a->head;
	while (ptr)
	{
		printf("%i\n", ptr->value);
		ptr = ptr->next;
	}
	printf("\n*** FUGAZZI ***\n");
	
	
	selection_sort(a, b);

	
	printf("_Columna A - Modificada_\n");
	ptr = a->head;
	while (ptr)
	{
		printf("%i\n", ptr->value);
		ptr = ptr->next;
	}
	printf("_Columna B - Modificada_\n");
	ptr = b->head;
	while (ptr)
	{
		printf("%i\n", ptr->value);
		ptr = ptr->next;
	}
}