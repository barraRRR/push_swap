/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:18:17 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/13 17:38:17 by jbarreir         ###   ########.fr       */
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

int ft_sqrt(int n)
{
	int sq;

	sq = 0;
	if (n <= 0)
		return (0);
	while (n != (sq * sq))
	{
		if ((sq * sq) > n)
			return (0);
		sq++;
	}
	return (sq);
}
