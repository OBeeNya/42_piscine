/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:59:40 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/06 19:02:36 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	minus_count;
	int	result;

	i = 0;
	minus_count = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	if (minus_count % 2 == 0)
		return (result);
	else
		return (-result);
}
