/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:39 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/12 11:20:12 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
 *		*** EXIT FUNCTIONS ***
 *		FT_LSTCLEAR() and PS_EXIT() free all data structures previously
 *		allocated and return the exit number given -- OJO INVESTIGAR COMO DEFINIR EXIT NUMBER
 */
static void	ft_lstclear(t_lst **lst)
{
	t_lst		*ptr;

	if (!lst)
		return ;
	while (*lst)
	{
		ptr = *lst;
		*lst = (*lst)->next;
		free(ptr);
	}
}

static int	ps_exit(char **split, t_stack *a, t_stack *b, int error)
{
	int			i;

	i = 0;
	if (error)
		ft_putstr_fd("Error\n", 2);
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
	if (a->head)
		ft_lstclear(&(a->head));
	if (b->head)
		ft_lstclear(&(b->head));
	return (error);
}

/*
 *		*** INIT_STRATEGY() ***
 *		Initializes the variables inside the struct STRATEGY
 */
void		init_data(t_strategy *strategy, t_stack *a, t_stack *b)
{
	strategy->complex = DEFAULT;
	strategy->defined = false;
	strategy->bench = false;
	strategy->total = 0;
	strategy->disorder = 0.0;
	a->head = NULL;
	a->tail = NULL;
	b->head = NULL;
	b->tail = NULL;
}

int	main(int argc, char **argv)
{
	t_strategy			strategy;
	t_stack				a;
	t_stack				b;

	if (argc == 1)
		return (0);
	init_data(&strategy, &a, &b);
	argv = ps_split(argv + 1);
	if (!argv)
		return (ps_exit(argv, &a, &b, 1));
	if (!create_stack(argv, &a, &strategy))
		return (ps_exit(argv, &a, &b, 1));
	/*
	 *		Por ahora dejo la inicializacón del disorder aquí, pero ya que hay
	 *		una función de INIT_STRATEGY creo que debería handlearse ahí de alguna manera
	 */
	strategy.disorder = compute_disorder(a.head);

	//		*** TESTING ***

	testing(&a, &b, &strategy);

	//		***************

	return (ps_exit(argv, &a, &b, 0));	
}
