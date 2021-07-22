/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:20:17 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/14 15:00:37 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		l;
	char	*cpy;

	l = ft_strlen(src);
	cpy = malloc(sizeof(char) * (l + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*s_stock;

	s_stock = malloc(sizeof(t_stock_str) * (ac + 1));
	if (s_stock == NULL)
		return (NULL);
	i = 0;
	while (av[i] && i < ac)
	{
		s_stock[i].size = ft_strlen(av[i]);
		s_stock[i].str = av[i];
		s_stock[i].copy = ft_strdup(av[i]);
		i++;
	}
	s_stock[i].size = 0;
	s_stock[i].str = 0;
	s_stock[i].copy = 0;
	return (s_stock);
}
