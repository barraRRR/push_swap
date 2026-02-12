/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:32:59 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/12 11:58:41 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	testing(t_stack *a, t_stack *b, t_strategy *strategy)
{
	t_lst		*tmpa;
	t_lst		*tmpb;

	printf("\n*** TESTING ***\n\n");
	printf("%f\n\n", strategy->disorder);
	printf("_Columna A - Original_\n");
	tmpa = a->head;
	while (tmpa)
	{
		printf("%i\n", tmpa->value);
		tmpa = tmpa->next;
	}
	printf("\n*** FUGAZZI ***\n");
	
	
	pb(a, b);
	pb(a, b);
	ra(a, true);
	rrr(a, b);
	sa(a, true);

	
	printf("_Columna A - Modificada_\n");
	tmpa = a->head;
	while (tmpa)
	{
		printf("%i\n", tmpa->value);
		tmpa = tmpa->next;
	}
	printf("_Columna B - Modificada_\n");
	tmpb = b->head;
	while (tmpb)
	{
		printf("%i\n", tmpb->value);
		tmpb = tmpb->next;
	}
}