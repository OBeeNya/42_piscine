/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:28:45 by yfoucade          #+#    #+#             */
/*   Updated: 2021/07/18 19:50:10 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	error_msg(char *msg, int *nbr)
{
	free(nbr);
	write(2, msg, ft_strlen(msg));
	return (1);
}

int	dict_error_msg(char *msg, int *tab, char **lines)
{
	int	i;

	free(tab);
	i = -1;
	while (lines[++i])
		free(lines[i]);
	free(lines);
	write(2, msg, ft_strlen(msg));
	return (1);
}
