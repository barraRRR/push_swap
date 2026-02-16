/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:19:53 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/16 14:51:32 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_total(t_bench bench)
{
	int			total;

	total = bench.sa + bench.sb + bench.ss + bench.pa + bench.pb;
	total += bench.ra + bench.rb + bench.rr;
	total += bench.rra + bench.rrb + bench.rrr;
	return (total);
}

static void	print_disorder(t_strat strategy)
{
	int			decimals;
	int			decimals_mod;
	int			integers;

	integers = (int)(strategy.disorder * 100.0);
	decimals = (int)(strategy.disorder * 10000.0);
	decimals_mod = decimals % 100;
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(integers, 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd(decimals_mod, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_op_row(t_bench bench)
{
	ft_putstr_fd("\n[bench] sa:  ", 2);
	ft_putnbr_fd(bench.sa, 2);
	ft_putstr_fd("  sb:  ", 2);
	ft_putnbr_fd(bench.sb, 2);
	ft_putstr_fd("  ss:  ", 2);
	ft_putnbr_fd(bench.ss, 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(bench.pa, 2);
	ft_putstr_fd("  pb:  ", 2);
	ft_putnbr_fd(bench.pb, 2);
	ft_putstr_fd("\n[bench] ra:  ", 2);
	ft_putnbr_fd(bench.ra, 2);
	ft_putstr_fd("  rb:  ", 2);
	ft_putnbr_fd(bench.rb, 2);
	ft_putstr_fd("  rr:  ", 2);
	ft_putnbr_fd(bench.rr, 2);
	ft_putstr_fd("  rra:  ", 2);
	ft_putnbr_fd(bench.rra, 2);
	ft_putstr_fd("  rrr:  ", 2);
	ft_putnbr_fd(bench.rrr, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_strategy(t_strat strategy)
{
	ft_putstr_fd("[bench] strategy:  ", 2);
	if (!strategy.defined)
		ft_putstr_fd("Adaptive / ", 2);
	else if (strategy.defined && strategy.complex == SIMPLE)
		ft_putstr_fd("Simple / ", 2);
	else if (strategy.defined && strategy.complex == MEDIUM)
		ft_putstr_fd("Medium / ", 2);
	else if (strategy.defined && strategy.complex == COMPLEX)
		ft_putstr_fd("Complex / ", 2);
	if (strategy.complex == SIMPLE)
		ft_putstr_fd("O(n^2)\n", 2);
	else if (strategy.complex == MEDIUM)
		ft_putstr_fd("O(n√n)\n", 2);
	else if (strategy.complex == COMPLEX)
		ft_putstr_fd("O(n log n)\n", 2);
}

void print_bench(t_strat strategy, t_bench bench)
{
	print_disorder(strategy);
	print_strategy(strategy);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(add_total(bench), 2);
	print_op_row(bench);
}
