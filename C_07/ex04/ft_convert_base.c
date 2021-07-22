/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:16:03 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/15 14:16:22 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*link(int n, char *base_to);
int		is_base_ok(char *base);

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
			|| base[i] == '-'
			|| base[i] == ' '
			|| (base[i] > 8 && base[i] < 14)
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	*result;

	if (is_base_ok(base_from) == 0 || is_base_ok(base_to) == 0)
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	result = link(n, base_to);
	return (result);
}
