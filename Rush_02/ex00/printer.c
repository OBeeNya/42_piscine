/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:52:23 by yfoucade          #+#    #+#             */
/*   Updated: 2021/07/18 23:02:01 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	not_last(int *tab, int index)
{
	while (--index >= 0)
		if (tab[index])
			return (1);
	return (0);
}

void	print_magnitude(int m, char **repr)
{
	ft_putstr(repr[m - 1]);
}

int	put_hundreds(int n, char **repr)
{
	if (n / 100)
	{
		ft_putstr(repr[n / 100]);
		write(1, " ", 1);
		ft_putstr(repr[28]);
		n %= 100;
		write(1, " ", (n != 0));
	}
	return (n);
}

void	print_small(int n, char **repr)
{
	if (n == 0)
	{
		ft_putstr(repr[0]);
		return ;
	}
	if (11 <= n && n <= 19)
	{
		ft_putstr(repr[n]);
		return ;
	}
	n = put_hundreds(n, repr);
	if (11 <= n && n <= 19)
	{
		ft_putstr(repr[n]);
		return ;
	}
	if (n / 10)
	{
		ft_putstr(repr[10 * (n < 11) + (18 + n / 10) * (n > 19)]);
		n %= 10;
		write(1, " ", (n != 0));
	}
	if (n)
		ft_putstr(repr[n]);
}

void	print_number(int *nbr, t_reprs *repr)
{
	int	i;
	int	zero;

	zero = 1;
	i = 13;
	while (--i > 0)
	{
		if (nbr[i])
		{
			zero = 0;
			print_small(nbr[i], repr->smalls);
			write(1, " ", 1);
			print_magnitude(i, repr->larges);
			if (not_last(nbr, i))
				write(1, " ", 1);
		}
	}
	if (nbr[i] || zero)
		print_small(nbr[i], repr->smalls);
}
