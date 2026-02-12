/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:32:59 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/12 16:53:12 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_title(const char *title)
{
	printf("\n---- %s ----\n\n", title);
}

static void	print_disorder(float disorder)
{
	printf("   +++++ disorder meric: %f\n", disorder);
}

static void	print_elements(int total)
{
	printf("   +++++ number of elements: %i\n", total);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_lst			*pa;
	t_lst			*pb;

	pa = a->head;
	pb = b->head;
	printf("\n");
	while (pa || pb)
	{
		if (pa)
		{
			printf("%i", pa->value);
			pa = pa->next;
		}
		else
			printf(" ");
		printf(" | ");
		if (pb)
		{
			printf("%i", pb->value);
			pb = pb->next;
		}
		else
			printf(" ");
		printf("\n");
	}
	printf("-----\n");
	printf("A | B\n\n");
}			

void	testing(t_stack *a, t_stack *b, t_strategy *strategy)
{
	print_title("TESTING");
	
	print_elements(strategy->total);
	print_disorder(strategy->disorder);

	print_stacks(a, b);	
	
	selection_sort(a, b);
	
	print_stacks(a, b);
}