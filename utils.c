/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:18:17 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/05 20:59:37 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*
 * 	*** ATOI MODIFICADO ***
 *	Parsea el string, procesa y compueba si es un número válido
 */
static bool	char_atoi(char c)
{
	return((c == ' ' || (c >= 9 && c <= 13)) || c == '-'
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
	if (str[i] || result < INT_MIN || result > INT_MAX)		// aquí comprobamos que no haya más caracteres y que el resultado quepa en un int
		return (false);
	*value = (int)result;
	return (true);
}

/*
 *	*** DUPLICATES ***
 *	Compueba que no haya datos duplicados en la lista
 */
bool	duplicate_values(t_lst *lst, int value)
{
	while (lst)
	{
		if (lst->value == value)
			return (false);
		lst = lst->next;
	}
	return (true);
}


/*
 *	*** STRATEGY VALIDATOR ***
 *	Parsea el string y comprueba si es una flag válida (sin duplicar)
 */
t_strategy		init_strategy(void)
{
	t_strategy			*strategy;

	strategy = malloc(sizeof(t_strategy));
	if (!strategy)
		return (NULL);
	strategy->complex = DEFAULT;
	strategy->defined = false;
	strategy->bench = false;
	return (strategy);
}

bool	validate_stategy(char *argv, t_strategy *strategy)
{
	if (strategy->defined && strategy->bench)
		return (false);
	else if (!strategy->defined && !ft_strncmp(argv, "--simple"))
		strategy->complex = SIMPLE;
	else if (!strategy->defined && !ft_strncmp(argv, "--medium"))
		strategy->complex = MEDIUM;
	else if (!strategy->defined && !ft_strncmp(argv, "--complex"))
		strategy->complex = COMPLEX;
	else if (!strategy->defined && !ft_strncmp(argv, "--adaptive"))
		strategy->complex = ADAPTIVE;
	else if (!strategy->bench && !ft_strncmp(argv, "--bench"))
	{
		strategy->bench = true;
		return (true);
	}
	else
		return (false);
	strategy->defined = true;
	return (true);
}
