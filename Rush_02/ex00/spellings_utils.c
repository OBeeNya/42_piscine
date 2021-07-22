/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spellings_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 07:58:50 by yfoucade          #+#    #+#             */
/*   Updated: 2021/07/18 18:23:56 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	get_position_of_large(char *number)
{
	if (ft_strlen(number) < 4 || ft_strlen(number) > 37)
		return (-1);
	if ((ft_strlen(number) - 1) % 3)
		return (-1);
	return ((ft_strlen(number) - 4) / 3);
}

int	valid_spellings(t_reprs *spellings)
{
	int	i;

	i = 0;
	while (i < N_SMALLS)
		if (!spellings->smalls[i++])
			return (0);
	i = 0;
	while (i < N_LARGES)
		if (!spellings->smalls[i++])
			return (0);
	return (1);
}
