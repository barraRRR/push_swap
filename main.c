/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:54:39 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/16 17:39:49 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	init_data(t_strat *strategy, t_stack *a, t_stack *b, t_bench *bench)
{
	strategy->complex = DEFAULT;
	strategy->defined = false;
	strategy->total = 0;
	strategy->disorder = 0.0;
	a->head = NULL;
	a->tail = NULL;
	b->head = NULL;
	b->tail = NULL;
	bench->count_only = false;
	bench->enabled = false;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

static int	add_total(t_bench bench)
{
	int			total;

	total = bench.sa + bench.sb + bench.ss + bench.pa + bench.pb;
	total += bench.ra + bench.rb + bench.rr;
	total += bench.rra + bench.rrb + bench.rrr;
	return (total);
}

int	main(int argc, char **argv)
{
	t_strat			strategy;
	t_stack			a;
	t_stack			b;
	t_bench			bench;

	if (argc == 1)
		return (0);
	init_data(&strategy, &a, &b, &bench);
	argv = ps_split(argv + 1);
	if (!argv)
		return (ps_exit(argv, &a, &b, 1));
	if (!create_stack(argv, &a, &strategy, &bench))
		return (ps_exit(argv, &a, &b, 1));
	if (is_sorted(a.head))
		return (ps_exit(argv, &a, &b, 0));
	strategy.disorder = compute_disorder(a.head);
	algo_selector(&a, &b, &strategy, &bench);
	ft_putnbr_fd(add_total(bench), 2);
	ft_putstr_fd("\n", 2);
	return (ps_exit(argv, &a, &b, 0));
}
