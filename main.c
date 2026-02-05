/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:39 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/05 20:50:19 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	free_total(char **split)
{
	int			i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	main(int argc, char **argv)
{
	t_strategy		*strategy;
	t_lst			*a;
	t_lst			*b;

	if (argc == 1)
		return (0);
	strategy = init_strategy();
	argv = ps_split(argv + 1);
	if (!argv || !strategy)
		return(print_error());
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
}
	



/*
./push_swap								//ERROR - Un argumento
./push_swap --simple					//ERROR - Dos argumentos si uno es strategy
./push_swap --palabra 1x 2frg 3 4		//ERROR - Dos argumentos y strings que no son números
./push_swap --simple "0 1 2 3 4"
./push_swap --simple 0 1 2 3 4
./push_swap --simple "0 1 2 3 4" "5 6 7 8" "9 10 11 12"
./push_swap
