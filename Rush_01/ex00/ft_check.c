/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:55:20 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/11 17:01:52 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	check_rows(int solution[4][4], int index)
{
	int	col;
	int	row;

	row = index / 4;
	col = index % 4;
	while (--col >= 0)
		if (solution[row][col] == solution[row][index % 4])
			return (0);
	return (1);
}

int	check_cols(int solution[4][4], int index)
{
	int	col;
	int	row;

	col = index % 4;
	row = index / 4;
	while (--row >= 0)
		if (solution[row][col] == solution[index / 4][col])
			return (0);
	return (1);
}

int	check_constraints_row(int stocker[4][4], int solution[4][4], int row)
{
	if (stocker[2][row] != seen_from_left(solution, row))
		return (0);
	if (stocker[3][row] != seen_from_right(solution, row))
		return (0);
	return (1);
}

int	check_constraints_col(int stocker[4][4], int solution[4][4], int col)
{
	if (stocker[0][col] != seen_from_top(solution, col))
		return (0);
	if (stocker[1][col] != seen_from_bottom(solution, col))
		return (0);
	return (1);
}

int	ft_verify(int stocker[4][4], int solution[4][4], int index)
{
	if (!check_rows(solution, index))
		return (0);
	if (!check_cols(solution, index))
		return (0);
	if (index % 4 == 3)
		if (!check_constraints_row(stocker, solution, index / 4))
			return (0);
	if (index / 4 == 3)
		if (!check_constraints_col(stocker, solution, index % 4))
			return (0);
	return (1);
}
