/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:22:07 by nsainton          #+#    #+#             */
/*   Updated: 2023/05/05 16:27:27 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_grid		grid;
	t_mlxgrid	mgrid;
	int			error;

	if (ac < 2)
	{
		ft_printf("Usage: ./so_long [map]\n");
		return (0);
	}
	error = init_grid(&grid, av[1]);
	if (error)
		return (free_on_error(&grid, free, error, DEBUG_OUT));
	error = valid_grid(&grid);
	if (error)
		return (free_on_error(&grid, free, error, DEBUG_OUT));
	if (init_mgrid(&mgrid, &grid, "SO_LONG"))
		return (free_on_error(&grid, free, UNKNOWN_ERROR, DEBUG_OUT));
	init_tiles(&mgrid, mgrid.width * TILE_SIZE, mgrid.height * TILE_SIZE);
	set_game_elements(&grid, &mgrid);
	mlx_key_hook(mgrid.win_ptr, controls, &(t_infos){&grid, &mgrid});
	mlx_hook(mgrid.win_ptr, DESTROY_NOTIFY, 0, end_loop, mgrid.mlx_ptr);
	mlx_loop(mgrid.mlx_ptr);
	clear_mgrid(&mgrid, 0);
	clear_grid(&grid, free);
	return (0);
}
