/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:57:37 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/15 18:09:00 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = n;
	if (l < 0)
	{
		write(fd, "-", 1);
		l = -l;
	}
	if (l >= 10)
		ft_putnbr_fd((int)(l / 10), fd);
	ft_putchar_fd((l % 10) + '0', fd);
}
