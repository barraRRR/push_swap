/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:39 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/11 15:15:54 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free(lst);
}

static int	ps_exit(char **split, t_lst **a, t_lst **b, int error)
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
	if (a)
		ft_lstclear(a);
	if (b)
		ft_lstclear(b);
	return (error);
}

/*
 *		*** INIT_STRATEGY() ***
 *		Initializes the variables inside the struct STRATEGY
 */
t_strategy		init_strategy(void)
{
	t_strategy			strategy;

	strategy.complex = DEFAULT;
	strategy.defined = false;
	strategy.bench = false;
	strategy.disorder = 0.0;
	strategy.total = 0;
	strategy.tail_a = NULL;
	strategy.tail_b = NULL;
	return (strategy);
}

int	main(int argc, char **argv)
{
	t_strategy		strategy;
	t_lst			**a;
	t_lst			**b;

	if (argc == 1)
		return (0);
	a = malloc(sizeof(t_lst *));
	b = malloc(sizeof(t_lst *));
	if (!a || !b)
		return (ps_exit(argv, a, b, 1));
	*a = NULL;
	*b = NULL;
	strategy = init_strategy();
	argv = ps_split(argv + 1);
	if (!argv)
		return (ps_exit(argv, a, b, 1));
	if (!create_stack(argv, a, &strategy))
		return (ps_exit(argv, a, b, 1));
	/*
	 *		Por ahora dejo la inicializacón del disorder aquí, pero ya que hay
	 *		una función de INIT_STRATEGY creo que debería handlearse ahí de alguna manera
	 */
	strategy.disorder = compute_disorder(*a);

	//		*** TESTING ***

	testing(a, b, &strategy);

	//		***************

	return (ps_exit(argv, a, b, 0));	
}
