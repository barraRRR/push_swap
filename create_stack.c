/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:44:06 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/05 21:01:06 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lst	*ps_lstnew(int value)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->value = value;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

static bool	ps_lstadd_back(t_lst **lst, int value)
{
	t_lst		*tmp;
	t_lst		*new;

	if (!lst)
		return (false);
	new = ps_lstnew(value);
	if (!new)
		return (false);
	if (!*lst)
	{
		*lst = new;
		return (true);
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return (true);
}

bool	create_stack(t_lst *node, char **argv, t_strategy *strategy)
{
	int			value;

	value = 0;
	while (*argv)
	{
		if (!ps_atoi(*argv, value) || !duplicate_values(node, value)
			|| !ps_lstadd_back(&node, value))				// comprobar que libero todo en caso de error
			return (false);
		else if (!validate_stategy(*argv, strategy))
			return (false);
		*argv++;
	}
	return (true);
}

/*
 *	**** CONVERTIR **ARGV en LST ****
 *	- while (*argv) -> comprobar str
 * 		- if número - añadir nodo 	// función que detecta número válido
 * 		- if flag - comprobar		// función que detecta flag unica
 * 			- valid
 * 			- duplicates
 * 				- saltar nodo
 * 
 * 