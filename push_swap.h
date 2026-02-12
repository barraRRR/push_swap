/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:13 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/12 16:17:35 by jbarreir         ###   ########.fr       */
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
	bool				bench;
	int					total;
	float				disorder;
}	t_strategy;

// ****** PROTOTYPES ******
char				**ps_split(char **argv);
void				ft_putstr_fd(char *s, int fd);
bool				ps_atoi(const char *str, int *value);
void				init_data(t_strategy *strategy, t_stack *a, t_stack *b);
int					ft_strcmp(char *s1, char *s2);
bool				create_stack(char **argv, t_stack *a, t_strategy *strategy);
int					ft_lstsize(t_lst *lst);

// ****** ALGORITHM ******
int					find_highest(t_lst *n);
int					find_lowest(t_lst *n);
float				compute_disorder(t_lst *a);
void				tiny_sort(t_stack *a);
void				selection_sort(t_stack *a, t_stack *b);

// ****** OPERATIONS ******											// actualizada data struct
void				sa(t_stack *a, bool print);					
void				sb(t_stack *b, bool print);					
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);	
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a, bool print);
void				rb(t_stack *b, bool print);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a, bool print);	
void				rrb(t_stack *b, bool print);
void				rrr(t_stack *a, t_stack *b);

//		Eliminar al final
void				testing(t_stack *a, t_stack *b, t_strategy *strategy);

#endif