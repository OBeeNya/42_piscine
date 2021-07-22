/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:08:52 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/21 09:09:42 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	length --;
	while (i < length)
	{
		if (s >= 0 && (*f)(tab[i], tab[i + 1]) >= 0)
		{
			if ((*f)(tab[i], tab[i + 1]) != 0)
				s = 1;
		}
		else if (s <= 0 && (*f)(tab[i], tab[i + 1]) <= 0)
			s -= 1;
		else
			return (0);
		i++;
	}
	return (1);
}
