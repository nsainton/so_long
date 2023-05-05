/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:22:07 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/03 13:04:31 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	//char	**file;
	//size_t	size;
	t_grid		grid;
	t_mlxgrid	mgrid;
	void		*mlx_ptr;
	void		*win_ptr;
	int			error;
	int			iwidth;
	int			iheight;
	void		*imgptr;

	if (ac < 2)
		return (0);
	/*
	file = readlines(av[1]);
	if (file)
	{
		print_tab(file);
		free_tab(file);
	}
	file = readlines_size(av[1], &size);
	if (file)
	{
		ft_dprintf(DEBUG_OUT, "The file has %u lines\n", size);
		print_tab(file);
		free_tab(file);
	}
	*/
	/*
	if (check_extension(av[1], MAP_EXTENSION))
		ft_dprintf(DEBUG_OUT, "Error\n");
	else
		ft_dprintf(DEBUG_OUT, "Valid\n");
	*/
	error = init_grid(&grid, av[1]);
	if (error)
		return (free_on_error(&grid, free, error, DEBUG_OUT));
	/*
	else
	{
		ft_dprintf(DEBUG_OUT, "The grid has the right format and arguments\n");
		print_grid(&grid);
	}
	*/
	error = valid_grid(&grid);
	if (error)
		return (free_on_error(&grid, free, error, DEBUG_OUT));
	else
		print_color_string("There is a valid path in the grid!!!\n", GRN, DEBUG_OUT);
	
	//ft_printf("SO_LONG\n");
	/*
	mlx_ptr = mlx_init();
	if (! mlx_ptr)
		return (free_on_error(&grid, free, UNKNOWN_ERROR, DEBUG_OUT));
	win_ptr = mlx_new_window(mlx_ptr, grid.width * TILE_SIZE, grid.height * TILE_SIZE, "SO_LONG");
	if (! win_ptr)
	{
		mlx_destroy_display(mlx_ptr);
		return (free_on_error(&grid, free, UNKNOWN_ERROR, DEBUG_OUT));
	}
	imgptr = mlx_xpm_file_to_image(mlx_ptr, PATH(tile), &iwidth, &iheight);
	//imgptr = NULL;
	(void)iwidth;
	(void)iheight;
	if (! imgptr)
	{
		null_window(mlx_ptr, &win_ptr);
		null_display(&mlx_ptr);
		return (free_on_error(&grid, free, NOT_FOUND, DEBUG_OUT));
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, imgptr, 0, 0);
	*/
	(void)mlx_ptr;
	(void)win_ptr;
	(void)imgptr;
	(void)iwidth;
	(void)iheight;
	(void)error;
	if (init_mgrid(&mgrid, &grid, "SO_LONG"))
	{
		return (free_on_error(&grid, free, UNKNOWN_ERROR, DEBUG_OUT));
	}
	init_tiles(&mgrid, mgrid.width * TILE_SIZE, mgrid.height * TILE_SIZE);
	//while ((error = getchar()) != 'c');
	//clear_tile(&mgrid, 2, 3);
	//while ((error = getchar()) != 'c');
	//put_image(&mgrid, get_image(&mgrid, SP), 2 * TILE_SIZE, 3 * TILE_SIZE);
	//put_image(&mgrid, get_image(&mgrid, PLAYER), 2 * TILE_SIZE + 10, 3 * TILE_SIZE + 10);
	set_game_elements(&grid, &mgrid);
	//while ((error = getchar()) != 'c');
	mlx_key_hook(mgrid.win_ptr, controls, &(t_infos){&grid, &mgrid});
	mlx_hook(mgrid.win_ptr, DESTROY_NOTIFY, 0, end_loop, mgrid.mlx_ptr);
	mlx_loop(mgrid.mlx_ptr);
	/*
	mlx_destroy_image(mlx_ptr, imgptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	*/
	clear_mgrid(&mgrid, 0);
	clear_grid(&grid, free);
	return (0);
}
