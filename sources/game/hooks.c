/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:14:42 by nsainton          #+#    #+#             */
/*   Updated: 2023/05/05 16:28:50 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_members(t_infos *infos, t_cint direction)
{
	t_point	p;

	ft_memcpy(&p, &infos->grid->player, sizeof p);
	move_point(&infos->grid->player, direction);
	update_grid(infos->grid, &p, &infos->grid->player);
	ft_printf("You're now at : %.3u steps\r", infos->grid->steps);
	if (!infos->grid->number_of_collectibles)
		update_window(infos->mgrid, &p, &infos->grid->player, \
		&infos->grid->exit);
	else
		update_window(infos->mgrid, &p, &infos->grid->player, NULL);
}

static int	finished(t_cgrid *grid, void *mlx_ptr)
{
	int	end;

	end = (grid->number_of_collectibles || ft_memcmp(&grid->player, \
	&grid->exit, sizeof (grid->player)));
	if (! end)
	{
		ft_printf("\nWON !!!\n");
		mlx_loop_end(mlx_ptr);
	}
	return (0);
}

int	controls(int keycode, void *params)
{
	t_infos	*infos;
	int		direction;

	infos = (t_infos *)params;
	if (keycode == ESC)
	{
		mlx_loop_end(infos->mgrid->mlx_ptr);
		return (0);
	}
	if (! ft_strchr(KEYS, keycode))
		return (0);
	direction = (int)(ft_strchr(KEYS, keycode) - KEYS);
	if (! valid_move(infos->grid, &infos->grid->player, direction))
		return (0);
	update_members(infos, direction);
	return (finished(infos->grid, infos->mgrid->mlx_ptr));
}

int	end_loop(void *mlx_ptr)
{
	mlx_loop_end(mlx_ptr);
	return (0);
}
