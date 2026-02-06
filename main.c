/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:39 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/06 17:49:46 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*		*** EXIT FUNCTIONS ***
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
	*lst = NULL;
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

/*		*** INIT_STRATEGY() ***
 *		Initializes the variables inside the struct STRATEGY
 */
t_strategy		init_strategy(void)
{
	t_strategy			strategy;

	strategy.complex = DEFAULT;
	strategy.defined = false;
	strategy.bench = false;
	return (strategy);
}

int	main(int argc, char **argv)
{
	t_strategy		strategy;
	t_lst			*a;
	t_lst			*b;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	strategy = init_strategy();
	argv = ps_split(argv + 1);
	if (!argv)
		return (ps_exit(argv, &a, &b, 1));
	if (!create_stack(argv, &a, &strategy))
		return (ps_exit(argv, &a, &b, 1));
	
	// *** TESTING ***

	t_lst *tmp = a;
	while (tmp)
	{
		printf("%i\n", tmp->value);
		tmp = tmp->next;
	}
	printf("\nstrategy and bench\n");
	printf("%i\n", strategy.bench);
	printf("%i\n", strategy.complex);

	// *** *** ***
	
	return (ps_exit(argv, &a, &b, 0));	
}


		
	
/*
 * **** SEGUNDA COMPROBACIÓN ****
 *      - procesar argv en un ** con todos los bloques de información
 * 		- comprobar validez
 * 			- ningún bloque se repite
 * 			- cero o una única estrategia
 * 			- comprobar bench
 * 			- comprobar validez números
 */


/*
	// *** TESTING SPLIT ***
	int				i;
	i = 0;
	while (argv[i])
		printf("%s\n", argv[i++]);
	free_total(argv);
	return (1);
*/
/*
./push_swap								//ERROR - Un argumento
./push_swap --simple					//ERROR - Dos argumentos si uno es strategy
./push_swap --palabra 1x 2frg 3 4		//ERROR - Dos argumentos y strings que no son números
./push_swap --simple "0 1 2 3 4"
./push_swap --simple 0 1 2 3 4
./push_swap --simple "0 1 2 3 4" "5 6 7 8" "9 10 11 12"
./push_swap
*/