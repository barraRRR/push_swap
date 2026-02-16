/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:51:44 by jbarreir          #+#    #+#             */
/*   Updated: 2026/02/16 15:46:39 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	split[i] = NULL;
	return (true);
}

char	**ps_split(char **argv)
{
	char	**split;

	split = malloc(sizeof(char *) * (count_blocks(argv) + 1));
	if (!split)
		return (NULL);
	if (!extract_strings(argv, split))
		return (NULL);
	return (split);
}
