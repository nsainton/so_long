/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:43:25 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/29 17:40:48 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ends(char *beg, char *end, char c, size_t len)
{
	int	error;

	error = same_char(beg, c, len);
	if (error)
		return (error);
	return (same_char(end, c, len));
}

int check_middle(char **grid, t_elements *el, size_t w, size_t h)
{
	size_t	index;
	int		error;

	index = 1;
	while (index < h - 1)
	{
		error = check_line(*(grid + index), el, w, index);
		//ft_dprintf(DEBUG_OUT, "This is line %u : %s\n", index, *(grid + index));
		if (error)
			return (error);
		index ++;
	}
	return (0);
}

int	check_extension(t_cchar *filename, t_cchar *ext)
{
	t_cchar *dot;

	dot = ft_strrchr(filename, '.');
	if (! dot)
		return (1);
	return (ft_strcmp(dot, ext));
}

int	check_elements(t_elements *el)
{
	if (! ft_lstsize(*el->collectibles))
		return (NO_COLLECTIBLES);
	if (el->player->x == -1)
		return (NO_PLAYER);
	if (el->exit->x == -1)
		return (NO_EXIT);
	return (0);
}
