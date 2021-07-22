/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:56:15 by yfoucade          #+#    #+#             */
/*   Updated: 2021/07/18 21:49:12 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	*ft_atoi_tab(char *str)
{
	int	i;
	int	*res;

	res = (int *)malloc(sizeof(*res) * 13);
	if (!res)
		return (0);
	i = -1;
	while (++i < 13)
		res[i] = str[39 - 3 * i] + 10 * str[38 - 3 * i] \
				 + 100 * str[37 - 3 * i] - 5328;
	return (res);
}

char	*pad_with_zeros(char *str)
{
	int		size;
	int		i;
	int		j;
	char	*res;

	if (ft_strlen(str) > 39)
		return (0);
	size = ft_strlen(str);
	res = (char *)malloc(sizeof(*res) * 40);
	if (!res)
		return (0);
	i = 0;
	while (i < 40 - size)
		res[i++] = '0';
	j = 0;
	while (i < 40)
		res[i++] = str[j++];
	res[i] = '\0';
	return (res);
}

int	seems_legit(char *str)
{
	int	i;

	if (!*str)
		return (0);
	if (str[0] != '+' && (str[0] < '0' || str[0] > '9'))
		return (0);
	i = 0;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	*parse_nbr(int ac, char **av)
{
	char	*copy;
	int		*nbr_tab;

	if (ac < 2 || ac > 3)
		return (0);
	if (!seems_legit(av[ac - 1]))
	{
		return (0);
	}
	copy = get_valid_unsigned_number(av[ac - 1]);
	copy = pad_with_zeros(copy);
	if (!copy)
		return (0);
	nbr_tab = ft_atoi_tab(copy);
	free(copy);
	if (!nbr_tab)
		return (0);
	return (nbr_tab);
}
