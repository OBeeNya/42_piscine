/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:25:53 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/21 11:42:11 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	while (s[i] == 32 || (s[i] > 8 && s[i] < 14))
		i++;
	sign = 1;
	while (s[i] == 43 || s[i] == 45)
	{
		if (s[i] == 45)
			sign *= -1;
		i++;
	}
	n = 0;
	while (s[i] > 47 && s[i] < 58)
	{
		n = n * 10 + (s[i] - 48);
		i++;
	}
	return (n * sign);
}

int	check_operator(char s)
{
	if (s != 37 && s != 42 && s != 43 && s != 45 && s != 47)
		return (0);
	return (1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2", 2);
		write(1, "147483648", 9);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	ft_operation(int n1, char s, int n2)
{
	if (s == 37)
		return (n1 % n2);
	else if (s == 42)
		return (n1 * n2);
	else if (s == 43)
		return (n1 + n2);
	else if (s == 45)
		return (n1 - n2);
	else if (s == 47)
		return (n1 / n2);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		if (check_operator(av[2][0]))
		{
			if (av[2][0] == 37 && ft_atoi(av[3]) == 0)
				write(1, "Stop : modulo by zero\n", 22);
			else if (av[2][0] == 47 && ft_atoi(av[3]) == 0)
				write(1, "Stop : division by zero\n", 24);
			else
			{
				ft_putnbr(ft_operation(ft_atoi(av[1]), av[2][0],
						ft_atoi(av[3])));
				write(1, "\n", 1);
			}
		}
		else
			write(1, "0\n", 2);
	}
	return (0);
}
