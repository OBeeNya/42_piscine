/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 09:39:58 by yfoucade          #+#    #+#             */
/*   Updated: 2021/07/18 11:38:15 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

int	is_printable(char c)
{
	return (c >= 32);
}

int	is_space(char c)
{
	return ((8 <= c && c <= 13) || c == ' ');
}

int	naive_valid_line_format(char *line)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while ((!i && line[i] == '+') || ('0' <= line[i] && line[i] <= '9'))
		has_digit += is_digit(line[i++]);
	while (is_space(line[i]))
		i++;
	if (!has_digit || line[i++] != ':')
		return (0);
	while (is_space(line[i]))
		i++;
	while (line[i])
		if (!is_printable(line[i++]))
			return (0);
	return (1);
}

int	valid_line_format(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (!line[i++])
		return (0);
	while (is_space(line[i]))
		i++;
	if (!line[i])
		return (0);
	while (line[i])
		if (!is_printable(line[i++]))
			return (0);
	return (1);
}
