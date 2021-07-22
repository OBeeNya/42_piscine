/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:56:47 by yfoucade          #+#    #+#             */
/*   Updated: 2021/07/18 21:15:10 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_dict(t_reprs *dict)
{
	int	i;

	i = -1;
	while (++i < N_SMALLS)
		free(dict->smalls[i]);
	i = -1;
	while (++i < N_LARGES)
		free(dict->larges[i]);
}

void	free_lines(char **lines)
{
	int	i;

	i = -1;
	while (lines[++i])
		free(lines[i]);
	free(lines);
}
