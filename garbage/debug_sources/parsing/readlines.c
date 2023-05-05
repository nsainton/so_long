/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:16:23 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/22 16:12:12 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	readlines_rec(char ***lines, int fd, t_csizet index)
{
	char	*line;

	line = get_next_line(fd);
	if (! line)
	{
		*lines = ft_calloc(index + 1, sizeof **lines);
		if (! *lines)
			return (1);
		*(*lines + index) = line;
		return (0);
	}
	if (readlines_rec(lines, fd, index + 1))
	{
		free(line);
		return (1);
	}
	*(*lines + index) = line;
	return (0);
}

char	**readlines(t_cchar *file)
{
	int		fd;
	char	**lines;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (readlines_rec(&lines, fd, 0))
		return (NULL);
	close(fd);
	return (lines);
}

static int	readlines_rec_s(char ***lines, int fd, t_cint index, int *size)
{
	char	*line;

	line = get_next_line(fd);
	if (! line)
	{
		*lines = ft_calloc(index + 1, sizeof **lines);
		if (! *lines)
			return (1);
		*(*lines + index) = line;
		*size = index;
		return (0);
	}
	if (readlines_rec_s(lines, fd, index + 1, size))
	{
		free(line);
		return (1);
	}
	*(*lines + index) = line;
	return (0);
}

char	**readlines_size(t_cchar *file, int	*size)
{
	int		fd;
	char	**lines;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (readlines_rec_s(&lines, fd, 0, size))
		return (NULL);
	close(fd);
	return (lines);
}
