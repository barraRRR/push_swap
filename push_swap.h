/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:13 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/11 15:51:23 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// ****** INCLUDES ******
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

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
	struct s_lst		*prev;
	struct s_lst		*next;
}	t_lst;

typedef struct s_strategy
{
	t_complexity		complex;
	bool				defined;
	bool				bench;
	int					total;
	float				disorder;								// branch disorder_metric
	t_lst				*tail_a;
	t_lst				*tail_b;
}	t_strategy;

// ****** PROTOTYPES ******
char				**ps_split(char **argv);
void				ft_putstr_fd(char *s, int fd);
bool				ps_atoi(const char *str, int *value);
t_strategy			init_strategy(void);
int					ft_strcmp(char *s1, char *s2);
bool				create_stack(char **argv, t_lst **node, t_strategy *strategy);
int					ft_lstsize(t_lst *lst);

// ****** ALGORITHM ******
float				compute_disorder(t_lst *a);					// branch disorder_metric
bool				is_sorted(t_lst *n);						// branch is_sorted

// ****** OPERATIONS ******
void				sa(t_lst **a, bool print);					// branch disorder_metric - añade bool
void				sb(t_lst **b, bool print);					// branch disorder_metric - añade bool
void				ss(t_lst **a, t_lst **b);
void				pa(t_lst **a, t_lst **b, t_lst **tail_a);
void				pb(t_lst **b, t_lst **a, t_lst **tail_b);
void				ra(t_lst **a, t_lst **tail_a, bool print);	// branch disorder_metric - añade bool
void				rb(t_lst **b, t_lst **tail_b, bool print);	// branch disorder_metric - añade bool
void				rr(t_lst **a, t_lst **b, t_lst **tail_a, t_lst **tail_b);
void				rra(t_lst **a, t_lst **tail_a, bool print);	// branch disorder_metric - añade bool
void				rrb(t_lst **b, t_lst **tail_b, bool print);	// branch disorder_metric - añade bool
void				rrr(t_lst **a, t_lst **b, t_lst **tail_a, t_lst **tail_b);

//		Eliminar al final
void				testing(t_lst **a, t_lst **b, t_strategy *strategy);

#endif