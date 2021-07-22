/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:17:34 by yfoucade          #+#    #+#             */
/*   Updated: 2021/07/18 23:01:46 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# define DEFAULT_DICT "numbers.dict"
# define BUF_SIZE 1024
# define N_SMALLS 29
# define N_LARGES 12
# define ERROR_MSG "Error\n"
# define DICT_ERROR_MSG "Dict Error\n"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_reprs
{
	char	**smalls;
	char	**larges;
}	t_reprs;

// file_parser.c
int		get_file_size(char *filename);
char	*extract_content(char *filename, int file_size);
char	**read_lines(char *filename);
char	**get_file_content(int ac, char **av);
t_reprs	*parse_content(char **lines);

// ft_split.c
char	**ft_split(char *str, char *charset);

// spellings_utils.c
int		get_position_of_large(char *number);
int		valid_spellings(t_reprs *spellings);

// t_reprs_updater.c
t_reprs	*initialize_spellings(t_reprs *spellings);
int		add_in_smalls(t_reprs *spellings, int number, char *repr);
int		add_in_larges(t_reprs *spellings, char *number, char *repr);
int		insert_spelling(t_reprs *spellings, char *number, char *repr);

// line_parser.c
char	*get_number_from_line(char *line);
char	*get_repr_from_line(char *line);
char	*get_valid_unsigned_number(char *number);
int		add_spelling(char *line, t_reprs *spellings);
int		is_valid_large(char *number);

// str_utils.c
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*trim(char *str);
int		ft_atoi(char *str);
void	ft_putstr(char *str);

//check_format.c
int		is_space(char c);
int		valid_line_format(char *line);

// parse_unsigned_int.c
int		*parse_nbr(int ac, char **av);

// errors.c
int		error_msg(char *msg, int *tab);
int		dict_error_msg(char *msg, int *tab, char **lines);

// printer.c
void	print_number(int *nbr, t_reprs *repr);

//liberator.c
void	free_dict(t_reprs *dict);
void	free_lines(char **lines);

#endif
