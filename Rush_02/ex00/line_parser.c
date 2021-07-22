/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:24:54 by yfoucade          #+#    #+#             */
/*   Updated: 2021/07/18 21:45:04 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_number_from_line(char *line)
{
	int		i;
	int		size;
	char	*number;

	size = 0;
	i = 0;
	if (line[0] == '+' || line[0] == '-')
		size++;
	while ('0' <= line[size] && line[size] <= '9')
		size++;
	number = (char *)malloc(sizeof(*number) * (size + 1));
	if (!number)
		return (0);
	i = -1;
	while (++i < size)
		number[i] = line[i];
	number[i] = '\0';
	return (number);
}

char	*get_repr_from_line(char *line)
{
	int		i;
	int		start;
	int		size;
	char	*repr;

	start = 0;
	while (line[start] != ':')
		start++;
	start++;
	while (is_space(line[start]))
		start++;
	size = 0;
	while (line[start + size])
		size++;
	repr = (char *)malloc(sizeof(*repr) * (size + 1));
	if (!repr)
		return (0);
	i = -1;
	while (++i < size)
		repr[i] = line[start + i];
	repr[i] = '\0';
	return (repr);
}

char	*get_valid_unsigned_number(char *number)
{
	int	i;

	if (!*number)
		return ("0");
	if (number[0] == '-')
	{
		i = 0;
		while (number[++i])
			if ('1' <= number[i] && number[i] <= '9')
				return ("-1");
		return ("0");
	}
	if (number[0] == '+' || number[0] == '0')
	{
		i = 0;
		while (number[++i])
			if ('1' <= number[i] && number[i] <= '9')
				break ;
		if (number[i] == '\0')
			return ("0");
	}
	i = 0;
	while (number[i] == '+' || number[i] == '0')
		i++;
	return (&number[i]);
}

int	add_spelling(char *line, t_reprs *spellings)
{
	char	*number;
	char	*repr;

	line = trim(line);
	if (!line)
		return (0);
	if (!valid_line_format(line))
		return (-1);
	number = get_number_from_line(line);
	repr = get_repr_from_line(line);
	if (!number || !repr)
		return (-1);
	if (insert_spelling(spellings, number, repr))
	{
		free(number);
		free(repr);
		return (-1);
	}
	free(number);
	free(repr);
	return (0);
}

int	is_valid_large(char *number)
{
	int	i;

	if (number[0] != '1')
		return (0);
	i = 0;
	while (number[++i])
		if (number[i] != '0')
			return (0);
	return (1);
}
