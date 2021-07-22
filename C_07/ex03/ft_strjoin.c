/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:13:32 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/15 14:30:27 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	join(int size, char *str, char **strs, char *sep)
{
	int	i;

	i = -1;
	str[0] = '\0';
	while (++i < size)
	{
		str = ft_strcat(str, strs[i]);
		if (i < size - 1)
			str = ft_strcat(str, sep);
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		tot_len;
	char	*str;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(*str));
		*str = 0;
		return (str);
	}
	i = -1;
	tot_len = 0;
	while (++i < size)
		tot_len += ft_strlen(strs[i]);
	str = malloc(sizeof(char) * (tot_len + ft_strlen(sep) * (size - 1) + 1));
	if (str == NULL)
		return (NULL);
	join(size, str, strs, sep);
	return (str);
}
