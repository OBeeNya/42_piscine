/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:17:26 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/01 21:18:12 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	if (str[0] == '\0')
	{
		return (result);
	}
	else
	{
		while (str[i] != '\0')
		{
			if (str[i] < 48 || str[i] > 57)
			{
				result = 0;
			}
			i++;
		}
		return (result);
	}
}
