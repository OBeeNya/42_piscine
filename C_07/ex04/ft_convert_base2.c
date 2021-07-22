/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:55:31 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/15 14:11:58 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_base_ok(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base [j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	len_in_base(unsigned int nbr, char *base, int *len, int base_len)
{
	if (nbr < base_len)
		*len += 1;
	else
	{
		len_in_base(nbr / base_len, base, len, base_len);
		len_in_base(nbr % base_len, base, len, base_len);
	}
}

void	print_in_str(int nbr, char *base, char *str, int len)
{
	unsigned int	i;
	unsigned int	n;

	if (nbr < 0)
	{
		n = -nbr;
		str[0] = '-';
	}
	else
		n = nbr;
	i = 0;
	while (base[i])
		i++;
	if (n >= i)
		print_in_str(n / i, base, str, len - 1);
	str[len - 1] = base[n % i];
}

char	*link(int n, char *base_to)
{
	int				len;
	unsigned int	nb;
	char			*str;
	int				base_len;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	base_len = 0;
	while (base_to[base_len])
		base_len++;
	len = 0;
	len_in_base(nb, base_to, &len, base_len);
	if (n < 0)
		len = len + 1;
	str = malloc(sizeof(char) * (len + 1));
	print_in_str(n, base_to, str, len);
	str[len] = '\0';
	return (str);
}
