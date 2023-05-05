/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:58:04 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/03 13:03:29 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_tiles(t_mlxgrid *mgrid, t_cint width, t_cint height)
{
	int		i;
	int		j;
	int		error;
	t_image	*img;

	error = 0;
	img = mgrid->images + SP;
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			error += put_image(mgrid, img->image, i, j);
			j += TILE_SIZE;
		}
		i += TILE_SIZE;
	}
	return (error > 0);
}

int	init_mgrid(t_mlxgrid *mgrid, t_cgrid *grid, char *win_name)
{
	ft_bzero(mgrid, sizeof * mgrid);
	mgrid->mlx_ptr = mlx_init();
	if (! mgrid->mlx_ptr)
		return (clear_mgrid(mgrid, UNKNOWN_ERROR));
	mgrid->win_ptr = mlx_new_window(mgrid->mlx_ptr, grid->width \
	* TILE_SIZE, grid->height * TILE_SIZE, win_name);
	if (! mgrid->win_ptr)
		return (clear_mgrid(mgrid, UNKNOWN_ERROR));
	if (init_images(mgrid->mlx_ptr, mgrid->images))
		return (clear_mgrid(mgrid, NOT_FOUND));
	mgrid->width = grid->width;
	mgrid->height = grid->height;
	return (0);
}

int	clear_mgrid(t_mlxgrid *mgrid, t_cint err_code)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if ((*(mgrid->images + i)).image)
		{
			clear_image(mgrid, i);
			(*(mgrid->images + i)).image = NULL;
		}
		i ++;
	}
	if (mgrid->win_ptr)
		null_window(mgrid->mlx_ptr, &mgrid->win_ptr);
	if (mgrid->mlx_ptr)
	{
		null_display(&mgrid->mlx_ptr);
	}
	return (err_code);
}
