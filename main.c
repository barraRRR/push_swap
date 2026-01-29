/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:39 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/29 17:10:26 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	ft_printf("Error\n");
	return (1);
}

t_strategy	strategy_selector(char *arg)
{
	if (!ft_strncmp(arg, "--simple"))
		return (SIMPLE);
	else if (!ft_strncmp(arg, "--medium"))
		return (MEDIUM);
	else if (!ft_strncmp(arg, "--complex"))
		return (COMPLEX);
	else if (!ft_strncmp(arg, "--adaptive"))
		return (ADAPTIVE);
	else
		return (DEFAULT);
}



int	main(int argc, char **argv)
{
	t_strategy		strategy;

	strategy = strategy_selector(argv[1]);
	if (argc < 2 && strategy != DEFAULT))
		return (print_error());
	
