/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:39 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/05 12:51:51 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

bool	which_strategy(t_strategy *strategy, char *arg)
{
	if (!ft_strncmp(arg, "--simple"))
		*strategy = SIMPLE;
	else if (!ft_strncmp(arg, "--medium"))
		*strategy = MEDIUM;
	else if (!ft_strncmp(arg, "--complex"))
		*strategy = COMPLEX;
	else if (!ft_strncmp(arg, "--adaptive"))
		*strategy = ADAPTIVE;
	else if (!ft_strncmp(arg, "--bench"))
		*strategy = BENCH;
	else
	{
		*strategy = DEFAULT;
		return (false);
	}
	return (true);
}



int	main(int argc, char **argv)
{
	t_strategy		strategy;
	t_node			*a;
	t_node			*b;
	
/*
 * **** PRIMERA COMPROBACIÓN ****
 *      - nº de argumentos
 *      - strategy validation
 */

	if (argc < 2 || (argc == 2 && which_strategy(&strategy, argv[1])))
		return (print_error());

/*
 * **** SEGUNDA COMPROBACIÓN ****
 *      - procesar argv
 * 			- comprobar 
 * 		- comprobar que son números válidos
 */


	if (argc == 2 && strategy == DEFAULT)
	{
		argv = ps_split(argv[DEFAULT], ' ');
		if (!argv)
			return(print_error());
	}


./push_swap								//ERROR - Un argumento
./push_swap --simple					//ERROR - Dos argumentos si uno es strategy
./push_swap --palabra 1x 2frg 3 4		//ERROR - Dos argumentos y strings que no son números
./push_swap --simple "0 1 2 3 4"
./push_swap --simple 0 1 2 3 4
./push_swap --simple "0 1 2 3 4" "5 6 7 8" "9 10 11 12"
./push_swap


/*
 * **** PS_SPLIT ****
 *		- 
 */

nº of args

1 - error

> 1

2 - solo si no hay strategy selector
3 - si hay selector
como saber si el selector es valido
}
	
