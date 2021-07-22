/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 11:02:41 by yfoucade          #+#    #+#             */
/*   Updated: 2021/07/18 23:01:08 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int ac, char **av)
{
	int		*nbr;
	t_reprs	*repr;
	char	**lines;

	nbr = parse_nbr(ac, av);
	if (!nbr)
		return (error_msg(ERROR_MSG, nbr));
	lines = get_file_content(ac, av);
	if (!lines)
		return (dict_error_msg(DICT_ERROR_MSG, nbr, lines));
	repr = parse_content(lines);
	if (!repr)
		return (dict_error_msg(DICT_ERROR_MSG, nbr, lines));
	print_number(nbr, repr);
	free_lines(lines);
	free(nbr);
	free_dict(repr);
	write(1, "\n", 1);
	return (0);
}
