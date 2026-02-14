/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:18:17 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/14 10:15:56 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t		len;

	if (!s)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_lstsize(t_lst *lst)
{
	int		len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

bool	is_sorted(t_lst *n)
{
	while (n->next)
	{
		if (n->value > n->next->value)
			return (false);
		n = n->next;
	}
	return (true);
}

float	newton_sqrt(float x)
{
	double			target;
	double			last_target;
	int				max_iter;

	target = (double)x;
	max_iter = 0;
	last_target = 0.0;
	while (max_iter < 100)
	{
		last_target = target;
		target = 0.5 * (target + (double)x / target);
		if (target == last_target)
			break ;
		max_iter++;
	}
	return ((float)target);
}
