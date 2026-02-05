/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:13 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/05 20:52:59 by jbarreir         ###   ########.fr       */
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
bool				duplicate_values(t_lst *lst, int value);
t_strategy			init_strategy(void);
bool				validate_stategy(char *argv, t_strategy *strategy);


#endif