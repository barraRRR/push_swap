/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:44:06 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/13 13:06:46 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 *	*** DUPLICATES ***
 *	Compueba que no haya datos duplicados en la lista
 */
static bool	duplicate_values(t_lst *lst, int value)
{
	if (!lst)
		return (true);
	while (lst)
	{
		if (lst->value == value)
			return (false);
		lst = lst->next;
	}
	return (true);
}

/*
 *	*** STRATEGY VALIDATOR ***
 *	Parsea el string y comprueba si es una flag válida (sin duplicar)
 */

static bool	validate_stategy(char *argv, t_strategy *strategy)
{
	if (strategy->defined && strategy->bench)
		return (false);
	else if (!strategy->defined && !ft_strcmp(argv, "--simple"))
		strategy->complex = SIMPLE;
	else if (!strategy->defined && !ft_strcmp(argv, "--medium"))
		strategy->complex = MEDIUM;
	else if (!strategy->defined && !ft_strcmp(argv, "--complex"))
		strategy->complex = COMPLEX;
	else if (!strategy->defined && !ft_strcmp(argv, "--adaptive"))
		strategy->complex = ADAPTIVE;
	else if (!strategy->bench && !ft_strcmp(argv, "--bench"))
	{
		strategy->bench = true;
		return (true);
	}
	else
		return (false);
	strategy->defined = true;
	return (true);
}

/*
 *	*** LISTS MGMT ***
 *	Crea y valida la lista enlazada
 */
static t_lst	*ps_lstnew(int value)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

static bool	ps_lstadd_back(t_stack *a, int value)
{
	t_lst		*tmp;
	t_lst		*new;

	new = ps_lstnew(value);
	if (!new)
		return (false);
	if (!(a->head))
	{
		a->head = new;
		return (true);
	}
	tmp = a->head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	a->tail = new;
	return (true);
}

bool	create_stack(char **argv, t_stack *a, t_strategy *strategy)
{
	int			value;
	int			i;

	value = 0;
	i = 0;
	while (argv && argv[i])
	{
		if (ps_atoi(argv[i], &value))
		{
			if (!duplicate_values(a->head, value))
				return (false);
			if (!ps_lstadd_back(a, value))
				return (false);
		}
		else if (!validate_stategy(argv[i], strategy))
			return (false);
		i++;
	}
	strategy->total = ft_lstsize(a->head);
	return (true);
}
