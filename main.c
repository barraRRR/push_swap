/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:39 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/05 10:47:28 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	ft_printf("Error\n");
	return (1);
}

bool	strat_selector(t_strategy *strategy, char *arg)
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
 * 		- DEAFAULT debería ser un string con solo números, espacios y signos negativos
 */

	if (argc < 2 || (argc == 2 && strat_select(&strategy, argv[1])))
		return (print_error());
	if (argc == 2 && strategy == DEFAULT)
	{
		argv = ps_split(argv[DEFAULT], ' ');
		if (!argv)
			return(print_error());
	}



nº of args

1 - error

> 1

2 - solo si no hay strategy selector
3 - si hay selector
como saber si el selector es valido
}
	
