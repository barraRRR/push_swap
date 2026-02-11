/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_selector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsole-a <edsole-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:22:39 by edsole-a          #+#    #+#             */
/*   Updated: 2026/02/11 18:47:57 by edsole-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// A modificar en función de la implementación de los algoritmos en sí

void algo_selector(t_lst **a, t_lst **tail_a)
{
	float	disorder;

	disorder = compute_disorder(a);
	if (disorder < 0.2)
		low(a, tail_a);
	else if (0.2 <= disorder && disorder < 0.5)
		medium(a, tail_a);
	else
		high(a, tail_a);
	return;
}