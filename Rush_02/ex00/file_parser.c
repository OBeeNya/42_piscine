/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 11:27:20 by yfoucade          #+#    #+#             */
/*   Updated: 2021/07/18 21:43:46 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	get_file_size(char *filename)
{
	int		fd;
	int		size;
	char	buf[BUF_SIZE + 1];
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	size = 0;
	ret = read(fd, buf, BUF_SIZE);
	while (ret)
	{
		if (ret < 0)
			return (-1);
		size += ret;
		ret = read(fd, buf, BUF_SIZE);
	}
	return (size);
}

char	*extract_content(char *filename, int file_size)
{
	int		fd;
	char	buf[1];
	char	*content;
	int		i;
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	content = (char *)malloc(sizeof(*content) * (file_size + 1));
	if (!content)
		return (0);
	i = 0;
	ret = read(fd, buf, 1);
	while (ret)
	{
		if (ret < 0)
			return (0);
		content[i++] = buf[0];
		ret = read(fd, buf, 1);
	}
	content[i] = '\0';
	return (content);
}

char	**read_lines(char *filename)
{
	int		file_size;
	char	*file_content;

	file_size = get_file_size(filename);
	if (file_size < 0)
		return (0);
	file_content = extract_content(filename, file_size);
	if (!file_content)
		return (0);
	return (ft_split(file_content, "\n"));
}

char	**get_file_content(int ac, char **av)
{
	char	**lines;

	if (ac == 1 || ac > 3)
		return (0);
	if (ac == 2)
	{
		lines = read_lines(DEFAULT_DICT);
	}
	else
	{
		lines = read_lines(av[1]);
	}
	if (!lines)
		return (0);
	return (lines);
}

t_reprs	*parse_content(char **lines)
{
	t_reprs	*spellings;
	int		ret;
	int		i;

	spellings = (t_reprs *)malloc(sizeof(*spellings));
	spellings = initialize_spellings(spellings);
	if (!spellings)
		return (0);
	i = 0;
	while (lines[i])
	{
		ret = add_spelling(lines[i], spellings);
		if (ret < 0)
			return (0);
		i++;
	}
	if (!valid_spellings(spellings))
		return (0);
	return (spellings);
}
