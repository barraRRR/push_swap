/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:13 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/16 14:45:47 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// ****** INCLUDES ******
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>						// acordarse de quitar

// ****** DEFINES ******


// ****** DATA STRUCTURES ******
typedef enum e_complexity
{
	DEFAULT,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_complexity;

typedef struct s_lst
{
	int					value;
	unsigned int		index;
	struct s_lst		*prev;
	struct s_lst		*next;
}	t_lst;

typedef struct	s_stack
{
	t_lst				*head;
	t_lst				*tail;
}	t_stack;

typedef struct s_strategy
{
	t_complexity		complex;
	bool				defined;
	int					total;
	float				disorder;
}	t_strat;

typedef struct s_bench
{
	bool				enabled;
	int					sa;
	int					sb;					
	int					ss;
	int					pa;	
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;	
	int					rrb;
	int					rrr;
}	t_bench;

// ****** GENERIC PROTOTYPES ******
char				**ps_split(char **argv);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
bool				ps_atoi(const char *str, int *value);
void				init_data(t_strat *strategy, t_stack *a, t_stack *b,
	t_bench *bench);
int					ft_strcmp(char *s1, char *s2);
float				newton_sqrt(float x);
bool				create_stack(char **argv, t_stack *a,
					t_strat *strategy, t_bench *bench);
int					ft_lstsize(t_lst *lst);
bool				is_sorted(t_lst *n);
void				index_list(t_stack *s, int size);
void				print_bench(t_strat strategy, t_bench bench);

// ****** ALGORITHM UTILS ******
int					find_highest(t_lst *n);
int					find_lowest(t_lst *n);
int 				find_low_index(t_lst *n, int low);
bool				is_target_on_top(t_lst *n, int target, unsigned int size);
float				compute_disorder(t_lst *a);
void				algo_selector(t_stack *a, t_stack *b, t_strat *strategy,
	t_bench *bench);

// ****** ALGORITHM STRATEGIES ******
void				insertion_sort(t_stack *a, t_stack *b,
					t_strat *strategy, t_bench *bench);
void				hourglass_sort(t_stack *a, t_stack *b,
					t_strat *strategy, t_bench *bench);
void				radix_sort(t_stack *a, t_stack *b, t_bench *bench);

// ****** OPERATIONS ******
void				sa(t_stack *a, bool print, t_bench *bench);
void				sb(t_stack *b, bool print, t_bench *bench);
void				ss(t_stack *a, t_stack *b, t_bench *bench);
void				pa(t_stack *a, t_stack *b, t_bench *bench);	
void				pb(t_stack *a, t_stack *b, t_bench *bench);
void				ra(t_stack *a, bool print, t_bench *bench);
void				rb(t_stack *b, bool print, t_bench *bench);
void				rr(t_stack *a, t_stack *b, t_bench *bench);
void				rra(t_stack *a, bool print, t_bench *bench);	
void				rrb(t_stack *b, bool print, t_bench *bench);
void				rrr(t_stack *a, t_stack *b, t_bench *bench);

#endif