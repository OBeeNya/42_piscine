/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 11:30:42 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/02 09:39:47 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = -1;
	if (size % 2 == 1)
	{	
		while (i++ < size / 2)
		{
			temp = tab[size - i - 1];
			tab[size - i - 1] = tab[i];
			tab[i] = temp;
		}
	}
	else
	{
		while (i++ < size / 2 - 1)
		{
			temp = tab[size - i - 1];
			tab[size - i - 1] = tab[i];
			tab[i] = temp;
		}
	}
}
