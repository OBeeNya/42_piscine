/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_reprs_updater.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:44:13 by yfoucade          #+#    #+#             */
/*   Updated: 2021/07/18 20:33:15 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_reprs	*initialize_spellings(t_reprs *spellings)
{
	int	i;

	spellings->smalls = (char **)malloc(sizeof(char *) * (N_SMALLS + 1));
	if (!spellings->smalls)
		return (0);
	i = 0;
	while (i <= N_SMALLS)
		(spellings->smalls)[i++] = 0;
	spellings->larges = (char **)malloc(sizeof(char *) * (N_LARGES + 1));
	if (!spellings->larges)
		return (0);
	i = 0;
	while (i <= N_LARGES)
		(spellings->larges)[i++] = 0;
	return (spellings);
}

int	add_in_smalls(t_reprs *spellings, int number, char *repr)
{
	int	position;

	if (0 <= number && number <= 20)
		position = number;
	else if ((30 <= number && number <= 100) && number % 10 == 0)
		position = 20 + (number - 20) / 10;
	else
		return (0);
	if (spellings->smalls[position])
		return (1);
	spellings->smalls[position] = \
		(char *)malloc(sizeof(char) * ft_strlen(repr) + 1);
	if (!spellings->smalls[position])
		return (1);
	spellings->smalls[position] = ft_strcpy(spellings->smalls[position], repr);
	return (0);
}

int	add_in_larges(t_reprs *spellings, char *number, char *repr)
{
	int	position;

	if (!is_valid_large(number))
		return (0);
	position = get_position_of_large(number);
	if (spellings->larges[position])
		return (1);
	spellings->larges[position] = \
		(char *)malloc(sizeof(char) * ft_strlen(repr) + 1);
	if (!spellings->larges[position])
		return (1);
	spellings->larges[position] = ft_strcpy(spellings->larges[position], repr);
	return (0);
}

int	insert_spelling(t_reprs *spellings, char *number, char *repr)
{
	number = get_valid_unsigned_number(number);
	if (!number)
		return (1);
	if (ft_strlen(number) <= 3)
	{
		return (add_in_smalls(spellings, ft_atoi(number), repr));
	}
	return (add_in_larges(spellings, number, repr));
}
