/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:36:46 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/07 14:26:32 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_base_ok(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	display_in_base(unsigned int nbr, char *base)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	b;

	i = 0;
	while (base[i])
		i++;
	if (nbr < i)
	{
		a = nbr / i;
		b = nbr % i;
		if (base[a] != base[0])
			ft_putchar(base[a]);
		ft_putchar(base[b]);
	}
	else
	{
		display_in_base(nbr / i, base);
		display_in_base(nbr % i, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (is_base_ok(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			display_in_base(-nbr, base);
		}
		else
			display_in_base(nbr, base);
	}
}
