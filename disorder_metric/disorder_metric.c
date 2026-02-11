/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 08:36:38 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/11 09:52:21 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
function compute_disorder(stack a):
	mistakes = 0
	total_pairs = 0
	for i from 0 to size(a)-1:
		for j from i+1 to size(a)-1:
			total_pairs += 1
			if a[i] > a[j]:
				mistakes += 1
	return mistakes / total_pairs
*/
float	compute_disorder(t_lst *a)
{
	float			mistakes;
	float			total_pairs;
	t_lst			*ptr;

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
