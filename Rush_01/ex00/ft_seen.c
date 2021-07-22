/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seen.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:56:43 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/11 17:02:01 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	seen_from_top(int solution[4][4], int col)
{
	int	i;
	int	res;
	int	height;

	res = 1;
	height = solution[0][col];
	i = -1;
	while (++i <= 3)
	{
		if (solution[i][col] > height)
		{
			res++;
			height = solution[i][col];
		}
	}
	return (res);
}

int	seen_from_bottom(int solution[4][4], int col)
{
	int	i;
	int	res;
	int	height;

	res = 1;
	height = solution[3][col];
	i = 4;
	while (--i >= 0)
	{
		if (solution[i][col] > height)
		{
			res++;
			height = solution[i][col];
		}
	}
	return (res);
}

int	seen_from_left(int solution[4][4], int row)
{
	int	i;
	int	res;
	int	height;

	res = 1;
	height = solution[row][0];
	i = -1;
	while (++i <= 3)
	{
		if (solution[row][i] > height)
		{
			res++;
			height = solution[row][i];
		}
	}
	return (res);
}

int	seen_from_right(int solution[4][4], int row)
{
	int	i;
	int	res;
	int	height;

	res = 1;
	height = solution[row][3];
	i = 4;
	while (--i >= 0)
	{
		if (solution[row][i] > height)
		{
			res++;
			height = solution[row][i];
		}
	}
	return (res);
}
