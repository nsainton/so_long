/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:17:36 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/28 10:35:51 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_char(t_cchar *symbols, t_cint c)
{
	while (*symbols)
	{
		if (*symbols == c)
			return (0);
		symbols ++;
	}
	return (UNRECOGNIZED_CHARACTER);
}

static int	update_elements(t_elements *el, t_cint c, int x, int y)
{
	t_list	*lst;
	lst = NULL;
	if (c == 'C')
		lst = ft_lstnew_cpy(&(t_cpoint){x, y}, sizeof (t_cpoint));
	if (c == 'C' && ! lst)
		return (UNKNOWN_ERROR);
	else if (c == 'C')
		ft_lstadd_front(el->collectibles, lst);
	if (c == 'E')
	{
		if (el->exit->x != -1)
			return (TOO_MUCH_EXITS);
		set_point(el->exit, x, y);
	}
	if (c == 'P')
	{
		if (el->player->x != -1)
			return (TOO_MUCH_PLAYERS);
		set_point(el->player, x, y);
	}
	return (0);
}

int	same_char(char *line, t_cint c, t_csizet width)
{
	size_t	length;

	length = ft_strlen(line) - 1;
	if (length != width)
		return (WRONG_MAP_DIMENSIONS);
	*(line + length) = 0;
	while (*line)
	{
		if (*line != c)
			return (WRONG_WALLS);
		line ++;
	}
	return (0);
}

int	check_line(char *line, t_elements *elems, t_csizet width, t_csizet height)
{
	size_t	index;
	int		error;

	index = ft_strlen(line) - 1;
	if (index != width)
		return (WRONG_MAP_DIMENSIONS);
	*(line + index) = 0;
	if (*(line + index - 1) != '1' || *line != '1')
		return (WRONG_WALLS);
	index = 0;
	while (*(line + index))
	{
		if (valid_char(SYMBOLS, *(line + index)))
			return (UNRECOGNIZED_CHARACTER);
		error = update_elements(elems, *(line + index), (int) \
		index, (int) height);
		if (error)
			return (error);
		index ++;
	}
	return (0);
}
