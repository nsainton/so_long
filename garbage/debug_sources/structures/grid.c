/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:24:15 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/02 17:50:30 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_point_grid(t_grid *grid, t_cpoint *coordinates, int elem)
{
	*(*(grid->grid + coordinates->y) + coordinates->x) = (char)elem;
}

int	init_grid(t_grid *grid, t_cchar *grid_name)
{
	int	error;

	ft_bzero(grid, sizeof * grid);
	if (check_extension(grid_name, MAP_EXTENSION))
		return (WRONG_EXTENSION);
	grid->grid = readlines_size(grid_name, &grid->height);
	if (! grid->grid)
		return (UNKNOWN_ERROR);
	if (grid->height < 1)
		return (EMPTY_MAP);
	error = parse_grid(grid);
	if (error)
		return (error);
	set_point_grid(grid, &grid->exit, '0');
	return (0);
}

int	get_point(t_cgrid *grid, t_cpoint *coordinates)
{
	return (*(*(grid->grid + coordinates->y) + coordinates->x));
}

void	clear_grid(t_grid *grid, t_delfunc del)
{
	if (grid->grid)
		free_tab(grid->grid);
	ft_lstclear(&grid->collectibles, del);
}
