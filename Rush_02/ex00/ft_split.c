/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:19:47 by yfoucade          #+#    #+#             */
/*   Updated: 2021/07/18 21:44:14 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] && charset[i] != c)
		i++;
	return (charset[i] == c);
}

int	count_substrings(char *str, char *charset)
{
	int	i;
	int	in_sep;
	int	res;

	i = -1;
	in_sep = 1;
	res = 0;
	while (str[++i])
	{
		if (is_sep(str[i], charset))
			in_sep = 1;
		else if (in_sep)
		{
			in_sep = 0;
			res += 1;
		}
	}
	return (res);
}

void	limits(int **tab, int n_substrings, char *str, char *charset)
{
	int	i;
	int	j;
	int	in_sep;

	i = -1;
	j = 0;
	in_sep = 1;
	*tab = (int *)malloc(sizeof(**tab) * (2 * n_substrings));
	if (!*tab)
	{
		tab = 0;
		return ;
	}
	while (str[++i])
	{
		if (is_sep(str[i], charset))
		{
			if (!in_sep)
				tab[in_sep++][j++] = i;
		}
		else if (in_sep)
			tab[--in_sep][j++] = i;
	}
	if (j == 2 * n_substrings - 1)
		tab[0][j] = i;
}

char	**split(char *str, int n_substrings, int *indices)
{
	int		i;
	int		sub;
	int		size;
	char	**res;

	res = (char **)malloc(sizeof(*res) * (n_substrings + 1));
	if (!res)
		return (0);
	sub = -1;
	while (++sub < n_substrings)
	{
		size = sizeof(**res) * ((indices[2 * sub + 1] - indices[2 * sub]) + 1);
		res[sub] = (char *)malloc(size);
		if (!res[sub])
			return (0);
		i = indices[2 * sub] - 1;
		while (++i < indices[2 * sub + 1])
			res[sub][i - indices[2 * sub]] = str[i];
		res[sub][i - indices[2 * sub]] = '\0';
	}
	res[sub] = 0;
	free(str);
	free(indices);
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	int	n_substrings;
	int	*indices;

	n_substrings = count_substrings(str, charset);
	limits(&indices, n_substrings, str, charset);
	if (!indices)
		return (0);
	return (split(str, n_substrings, indices));
}
