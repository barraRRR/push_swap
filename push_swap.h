/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:13 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/10 12:26:16 by jbarreir         ###   ########.fr       */
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

typedef struct s_strategy
{
	t_complexity		complex;
	bool				defined;
	bool				bench;
	int					total;
	t_lst				*tail_a;
	t_lst				*tail_b;
}	t_strategy;

typedef struct s_lst
{
	int					value;
	struct s_lst		*prev;
	struct s_lst		*next;
}	t_lst;

// ****** PROTOTYPES ******
char				**ps_split(char **argv);
void				ft_putstr_fd(char *s, int fd);
bool				ps_atoi(const char *str, int *value);
t_strategy			init_strategy(void);
int					ft_strcmp(char *s1, char *s2);
bool				create_stack(char **argv, t_lst **node, t_strategy *strategy);
int					ft_lstsize(t_lst *lst);

#endif