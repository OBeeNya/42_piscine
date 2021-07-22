/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:52:29 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/11 17:02:08 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_solution(int tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(tab[i][j++] + 48);
			if (j != 4)
				ft_putchar(' ');
		}
		write(1, "\n", 1);
		i++;
	}
}

int	getter(char *arg, int stocker[4][4])
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (i % 2)
		{
			if (arg[i] != ' ')
				return (0);
		}
		else
		{
			if (arg[i] < '1' || arg[i] > '4')
				return (0);
			else
				stocker[(i / 2) / 4][(i / 2) % 4] = arg[i] - 48;
		}
		i++;
	}
	return (1);
}

int	solve(int stocker[4][4], int solution[4][4], int index)
{
	int	has_sol;
	int	row;
	int	col;

	has_sol = 0;
	row = index / 4;
	col = index % 4;
	solution[row][col] = 1;
	while (solution[row][col] <= 4 && has_sol == 0)
	{
		if (ft_verify(stocker, solution, index))
		{
			if (index == 15)
				return (1);
			else
				has_sol += solve(stocker, solution, index + 1);
		}
		if (has_sol == 0)
			solution[row][col]++;
	}
	return (has_sol);
}

int	main(int argc, char **argv)
{
	int	stocker[4][4];
	int	solution[4][4];
	int	is_valid;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	is_valid = getter(argv[1], stocker);
	if (is_valid)
		is_valid = solve(stocker, solution, 0);
	if (!is_valid)
		write(1, "Error\n", 6);
	else
		print_solution(solution);
	return (0);
}
