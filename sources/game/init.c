/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:29:45 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/03 11:34:28 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_game_element(t_mlxgrid *grid, t_cint x, t_cint y, t_cchar elem)
{
	int		index;
	int		x_pos;
	int		y_pos;
	void	*img;

	index = SP;
	if (elem == '1')
		index = WALL;
	else if (elem == 'P')
		index = PLAYER;
	else if (elem == 'C')
		index = COL;
	else if (elem == 'E')
		index = EXIT;
	if (index == SP)
		return (0);
	x_pos = x * TILE_SIZE + (TILE_SIZE - SPRITE_SIZE) / 2;
	y_pos = y * TILE_SIZE + (TILE_SIZE - SPRITE_SIZE) / 2;
	img = get_image(grid, index);
	return (put_image(grid, img, x_pos, y_pos));
}

int	set_game_elements(t_cgrid *grid, t_mlxgrid *mgrid)
{
	int	error;
	int	x;
	int	y;

	error = 0;
	y = 0;
	while (y < grid->height)
	{
		x = 0;
		while (x < grid->width)
		{
			if (*(*(grid->grid + y) + x) != '0')
				error += set_game_element(mgrid, x, y, \
				*(*(grid->grid + y) + x));
			x ++;
		}
		y ++;
	}
	return (error > 0);
}
