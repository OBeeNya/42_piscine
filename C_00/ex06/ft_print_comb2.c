/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:41:59 by baubigna          #+#    #+#             */
/*   Updated: 2021/06/30 20:55:06 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display(int nb)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0';
	b = '0' + nb;
	c = '0' + nb / 10;
	d = '0' + nb % 10;
	if (nb < 9)
	{
		ft_putchar(a);
		ft_putchar(b);
	}
	else
	{
		ft_putchar(c);
		ft_putchar(d);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			display(i);
			ft_putchar(' ');
			display(j);
			if (i != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			j++;
		}
		i++;
	}
}
