/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:15:00 by yfoucade          #+#    #+#             */
/*   Updated: 2021/07/18 20:19:47 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*trim(char *str)
{
	int	i;

	while (is_space(*str))
		str++;
	if (*str == '\0')
		return (0);
	i = ft_strlen(str);
	while (i > 0 && is_space(str[i - 1]))
		i--;
	str[i] = '\0';
	return (str);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	res;
	int	i;

	res = 0;
	sign = 1;
	i = -1;
	if (str[0] == '-')
		return (-1);
	while (str[++i])
		res = 10 * res + str[i] - '0';
	return (sign * res);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}
