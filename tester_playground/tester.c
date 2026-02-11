/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:32:59 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/11 10:34:25 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	testing(t_lst **a, t_lst **b, t_strategy *strategy)
{
	t_lst		*tmpa;
	t_lst		*tmpb;

	printf("\n*** TESTING ***\n\n");
	printf("%f\n\n", strategy->disorder);
	printf("_Columna A - Original_\n");
	tmpa = *a;
	while (tmpa)
	{
		printf("%i\n", tmpa->value);
		tmpa = tmpa->next;
	}
	printf("\n*** FUGAZZI ***\n");
	
	
	pb(a, b, &strategy->tail_b);
	pb(a, b, &strategy->tail_b);
	ra(a, &strategy->tail_a, true);
	rrr(a, b, &strategy->tail_a, &strategy->tail_b);
	sa(a, true);

	
	printf("_Columna A - Modificada_\n");
	tmpa = *a;
	while (tmpa)
	{
		printf("%i\n", tmpa->value);
		tmpa = tmpa->next;
	}
	printf("_Columna B - Modificada_\n");
	tmpb = *b;
	while (tmpb)
	{
		printf("%i\n", tmpb->value);
		tmpb = tmpb->next;
	}
}