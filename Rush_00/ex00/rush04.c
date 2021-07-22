/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:41:34 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/04 09:37:18 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_display_line(char a, char b, char c, int x)
{
	int	i;

	i = 1;
	ft_putchar(a);
	while (i < x - 1)
	{
		ft_putchar(b);
		i++;
	}
	if (x > 1)
		ft_putchar(c);
	ft_putchar('\n');
}

void	abc_first_line(char *a, char *b, char *c)
{
	*a = 'A';
	*b = 'B';
	*c = 'C';
}

void	abc_middle_line(char *a, char *b, char *c)
{	
	*a = 'B';
	*b = ' ';
	*c = 'B';
}

void	abc_last_line(char *a, char *b, char *c)
{	
	*a = 'C';
	*b = 'B';
	*c = 'A';
}

void	rush(int x, int y)
{
	char	a;
	char	b;
	char	c;
	int		i;

	if (x != 0 && y != 0)
	{
		i = 1;
		if (y >= 1)
		{
			abc_first_line(&a, &b, &c);
			ft_display_line(a, b, c, x);
			while (i >= 1 && i < y - 1)
			{
				abc_middle_line(&a, &b, &c);
				ft_display_line(a, b, c, x);
				i++;
			}
		}
		if (y > 1)
		{
			abc_last_line(&a, &b, &c);
			ft_display_line(a, b, c, x);
		}
	}
}
