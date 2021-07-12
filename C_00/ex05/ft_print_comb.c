/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:43:11 by baubigna          #+#    #+#             */
/*   Updated: 2021/06/30 19:12:27 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_int(int i, int j, int k)
{
	char	a;
	char	b;
	char	c;
	char	d;
	char	e;

	a = '0' + i;
	b = '0' + j;
	c = '0' + k;
	d = ',';
	e = ' ';
	if (a != '7' || b != '8' || c != '9')
	{	
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
		write(1, &d, 1);
		write(1, &e, 1);
	}
	else
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 2;
	while (i < 8)
	{
		j = i + 1;
		while (j < 9)
		{
			k = j + 1;
			while (k < 10)
			{
				write_int(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
