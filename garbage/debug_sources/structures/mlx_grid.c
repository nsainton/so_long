/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:58:04 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/03 08:56:10 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_tiles(t_mlxgrid *mgrid, t_cint width, t_cint height)
{
	int	i;
	int	j;
	int	error;
	t_image	*img;

	error = 0;
	img = mgrid->images + SP;
	//print_image(mgrid->mlx_ptr, img);
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
		//	ft_dprintf(DEBUG_OUT, "Line : %d, Column : %d\n", i / TILE_SIZE, j / TILE_SIZE);
			//mlx_put_image_to_window(mgrid->mlx_ptr, win_ptr, img->image, i, j);
			error += put_image(mgrid, img->image, i, j);
			j += TILE_SIZE;
		}
		i += TILE_SIZE;
	}
	return (error > 0);
}

int	init_mgrid(t_mlxgrid *mgrid, t_cgrid *grid, char *win_name)
{
	//t_image	img;

	ft_bzero(mgrid, sizeof * mgrid);
	mgrid->mlx_ptr = mlx_init();
	if (! mgrid->mlx_ptr)
		return (clear_mgrid(mgrid, UNKNOWN_ERROR));
	ft_dprintf(DEBUG_OUT, "The connection is open\n");
	mgrid->win_ptr = mlx_new_window(mgrid->mlx_ptr, grid->width \
	* TILE_SIZE, grid->height * TILE_SIZE, win_name);
	if (! mgrid->win_ptr)
		return (clear_mgrid(mgrid, UNKNOWN_ERROR));
	ft_dprintf(DEBUG_OUT, "The window is open\n");
	/*
	if (image_from_file(mgrid->mlx_ptr, &img, NAME(player)))
		return (clear_mgrid(mgrid, NOT_FOUND));
	mlx_put_image_to_window(mgrid->mlx_ptr, mgrid->win_ptr, img.image, img.width, img.height);
	*/
	ft_dprintf(DEBUG_OUT, "The window is ready\n");
	if (init_images(mgrid->mlx_ptr, mgrid->images))
		return (clear_mgrid(mgrid, NOT_FOUND));
	mgrid->width = grid->width;
	mgrid->height = grid->height;
	return (0);
}

int	clear_mgrid(t_mlxgrid *mgrid, t_cint err_code)
{
	int i;
	
	i = 0;
	ft_dprintf(DEBUG_OUT, "This is the value of mgrid : %p\n", mgrid);
	ft_dprintf(DEBUG_OUT, "This is the value of mlx_ptr : %p\n", mgrid->mlx_ptr);
	ft_dprintf(DEBUG_OUT, "This is the value of win_ptr : %p\n", mgrid->win_ptr);
	while (i < 5)
	{
		ft_dprintf(DEBUG_OUT, "Index is : %d\n", i);
		if ((*(mgrid->images + i)).image)
		{
			clear_image(mgrid, i);
			(*(mgrid->images + i)).image = NULL;
		}
		i ++;
	}
	if (mgrid->win_ptr)
		null_window(mgrid->mlx_ptr, &mgrid->win_ptr);
		//mlx_destroy_window(mgrid->mlx_ptr, mgrid->win_ptr);
	if (mgrid->mlx_ptr)
	{
		null_display(&mgrid->mlx_ptr);
		if (mgrid->mlx_ptr)
		{
			mlx_destroy_display(mgrid->mlx_ptr);
			ft_dprintf(DEBUG_OUT, "This is the value of mlx_ptr : %p\n", mgrid->mlx_ptr);
			free(mgrid->mlx_ptr);
		}
	}
	return (err_code);
}
