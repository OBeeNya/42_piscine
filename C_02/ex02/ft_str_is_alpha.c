/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:06:15 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/01 21:16:35 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
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
			if (str[i] < 65 || str[i] > 122)
			{
				result = 0;
			}
			else if (str [i] > 90 && str[i] < 97)
			{
				result = 0;
			}
			i++;
		}
		return (result);
	}
}
