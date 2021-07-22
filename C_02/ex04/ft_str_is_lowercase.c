/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:59:52 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/03 13:04:43 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	if (str[0] == '\0')
	{
		return (result);
	}
	while (str[i] != '\0')
	{
		if (str[i] < 97 || str[i] > 122)
		{
			result = 0;
			return (result);
		}
		i++;
	}
	return (result);
}
