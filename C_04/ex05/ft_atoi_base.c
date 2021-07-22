/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:59:39 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/07 19:09:52 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	in_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
			return (i);
	}
	return (-1);
}

int	base_len(char *base)
{
	int	i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == '+'
			|| base [i] == '-'
			|| base[i] == ' '
			|| (base[i] > 8 && base [i] < 14)
			|| in_base(base[i], base + i + 1) >= 0)
			return (0);
	}
	return (i);
}

int	init_string(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	n;
	int				i;
	int				j;
	int				size;
	int				sign;

	sign = 1;
	n = 0;
	size = base_len(base);
	if (size < 2)
		return (0);
	j = init_string(str, &sign);
	i = in_base(str[j], base);
	while (i >= 0)
	{
		n = n * size + i;
		j++;
		i = in_base(str[j], base);
	}
	return (n * sign);
}
