/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:51:03 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/03 13:12:52 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_image(t_mlxgrid *grid, t_cint index)
{
	return ((*(grid->images + index)).image);
}

int	put_image(t_mlxgrid *grid, void *img, int x, int y)
{
	return (mlx_put_image_to_window(grid->mlx_ptr, grid->win_ptr, \
	img, x, y));
}

int	clear_tile(t_mlxgrid *mgrid, int x, int y)
{
	return (mlx_put_image_to_window(mgrid->mlx_ptr, mgrid->win_ptr, \
	get_image(mgrid, SP), x * TILE_SIZE, y * TILE_SIZE));
}

int	init_images(void *mlx_ptr, t_image sprites[5])
{
	int	error;

	error = 0;
	error += image_from_file(mlx_ptr, sprites + PLAYER, \
	Pl);
	error += image_from_file(mlx_ptr, sprites + SP, \
	Ti);
	error += image_from_file(mlx_ptr, sprites + COL, \
	Co);
	error += image_from_file(mlx_ptr, sprites + WALL, \
	Wa);
	error += image_from_file(mlx_ptr, sprites + EXIT, \
	Ex);
	return ((error > 0) * UNKNOWN_ERROR);
}

int	clear_image(t_mlxgrid *mgrid, t_cint index)
{
	return (mlx_destroy_image(mgrid->mlx_ptr, \
	(*(mgrid->images + index)).image));
}
