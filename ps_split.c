/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:51:44 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/05 20:39:09 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *		./push_swap "  20 32 --simple 0 1 2 3 4 "   "5 6 7 8" "9 --bench 10 11 12" 13 14 15
 *		**** BLUEPRINT ****
 *		- Recibe **
 *		- Cuenta bloques
 * 			- * sin espacios en el medio = 1 bloque — Opción: ft_trim
 *			- * con espacios = contar bloques
 */

static bool	free_partial(char **split, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		free(split[j]);
		j++;
	}
	free(split);
	return (false);
}

static int	count_blocks(char **argv)
{
	int			blocks;
	char		*ptr;

	blocks = 0;
	while (*argv)
	{
		ptr = *argv;
		while (*ptr)
		{
			while (*ptr == ' ')
				ptr++;
			if (*ptr)
			{
				blocks++;
				while (*ptr && *ptr != ' ')
					ptr++;
			}
		}
		argv++;
	}
	return (blocks);
}

static char	*ps_strdup(char *s)
{
	char	*p;
	int		i;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	p = malloc(i + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != ' ')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static bool	extract_strings(char **argv, char **split)
{
	char		*ptr;
	int			i;

	i = 0;
	while (*argv)
	{
		ptr = *argv;
		while (*ptr)
		{
			while (*ptr == ' ')
				ptr++;
			if (*ptr)
			{
				split[i] = ps_strdup(ptr);
				if (!split[i])
					return (free_partial(split, i));
				i++;
				while (*ptr && *ptr != ' ')
					ptr++;
			}
		}
		argv++;
	}
	return (true);
}

char	**ps_split(char **argv)
{
	char	**split;

	split = malloc(sizeof(char *) * count_blocks(argv) + 1);
	if (!split)
		return (NULL);
	if (!extract_strings(argv, split))
		return (NULL);
	return (split);
}
