/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:59:50 by baubigna          #+#    #+#             */
/*   Updated: 2021/07/11 17:01:27 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

int	check_rows(int solution[4][4], int index);
int	check_cols(int solution[4][4], int index);
int	check_constraints_row(int stocker[4][4], int solution[4][4], int row);
int	check_constraints_col(int stocker[4][4], int solution[4][4], int col);
int	ft_verify(int stocker[4][4], int solution[4][4], int index);
int	seen_from_top(int solution[4][4], int col);
int	seen_from_bottom(int solution[4][4], int col);
int	seen_from_left(int solution[4][4], int row);
int	seen_from_right(int solution[4][4], int row);

#endif
