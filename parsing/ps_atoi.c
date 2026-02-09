/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:29:35 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/06 17:20:33 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * 	*** ATOI MODIFICADO ***
 *	Parsea el string, procesa y compueba si es un número válido
 */
static bool	char_atoi(char c)
{
	return ((c == ' ' || (c >= 9 && c <= 13)) || c == '-'
		|| c == '+' || (c >= '0' && c <= '9'));
}

bool	ps_atoi(const char *str, int *value)
{
	int				i;
	int				sign;
	long long 		result;			// utilizamos un long long para poder procesar un número extremadamente alto

	i = 0;
	sign = 1;
	result = 0;
	if (!char_atoi(str[i]))
		return (false);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		result = (result * 10) + (str[i++] - '0');
	result *= sign;
	if (str[i] || result < INT_MIN || result > INT_MAX)		// aquí comprobamos que no haya más caracteres y que el resultado quepa en un int
		return (false);
	*value = (int)result;
	return (true);
}
