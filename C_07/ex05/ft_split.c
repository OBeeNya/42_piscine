/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 08:42:12 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/15 10:31:49 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_word_count(char *str, char *charset)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		if ((!is_sep(str[i], charset) && is_sep(str[i - 1], charset))
			|| (!is_sep(str[i], charset) && i == 0))
			word_count++;
		i++;
	}
	return (word_count);
}

int	*get_words_size(char *str, char *charset, int	word_count)
{
	int	*words_size;
	int	i;
	int	j;
	int	k;

	words_size = malloc(sizeof(int) * (word_count + 1));
	i = 0;
	k = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset))
		{
			j = 0;
			while (!is_sep(str[i], charset))
			{
				j++;
				i++;
			}
			words_size[k] = j;
			k++;
		}
		i++;
	}
	words_size[word_count] = 0;
	return (words_size);
}

void	copy_words(char *str, char *charset, int *words_size, char **ret)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	while (words_size[++i])
		ret[i] = malloc(sizeof(char) * (words_size[i] + 1));
	i = 0;
	while (str[++j])
	{
		if (!is_sep(str[j], charset))
		{
			k = 0;
			while (!is_sep(str[j], charset))
			{
				ret[i][k] = str[j];
				k++;
				j++;
			}
			ret[i][k] = '\0';
			i++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		word_count;
	int		*words_size;

	if (str[0] == '\0')
	{
		ret = malloc(sizeof(char) * 1);
		ret[0] = 0;
		return (ret);
	}
	if (charset[0] == '\0')
	{
		ret = malloc(sizeof(char *) * 2);
		ret[0] = str;
		ret[1] = 0;
		return (ret);
	}
	word_count = get_word_count(str, charset);
	ret = malloc(sizeof(char *) * (word_count + 1));
	words_size = get_words_size(str, charset, get_word_count(str, charset));
	copy_words(str, charset, words_size, ret);
	ret[word_count] = 0;
	return (ret);
}
