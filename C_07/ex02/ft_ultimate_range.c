/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:34:57 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/12 17:42:59 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ptr;
	int	i;

	ptr = NULL;
	if (min >= max)
	{
		*range = ptr;
		return (0);
	}
	ptr = malloc(sizeof(int) * (max - min));
	if (ptr == NULL)
		exit(0);
	i = -1;
	while (++i < (max - min))
		ptr[i] = min + i;
	*range = ptr;
	return (i);
}
