/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:14:42 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/03 09:00:08 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	controls(int keycode, void *params)
{
	t_infos	*infos;
	int		end;
	int		direction;
	t_point	p;

	infos = (t_infos *)params;
	//ft_dprintf(DEBUG_OUT, "In function : %s\n", __func__);
	if (keycode == ESC)
	{
		mlx_loop_end(infos->mgrid->mlx_ptr);
		return (0);
	}
	if (! (ft_strchr(KEYS, keycode) || keycode == ESC))
	{
		ft_dprintf(DEBUG_OUT, "Wrong key pressed : %c\n", keycode);
		return (0);
	}
	direction = (int)(ft_strchr(KEYS, keycode) - KEYS);
	if (! valid_move(infos->grid, &infos->grid->player, direction))
	{
		ft_dprintf(DEBUG_OUT, "Invalid move\n");
		return (0);
	}
	ft_memcpy(&p, &infos->grid->player, sizeof p);
	ft_dprintf(DEBUG_OUT, "This is the original player position\n");
	print_point(&p);
	move_point(&infos->grid->player, direction);
	ft_dprintf(DEBUG_OUT, "This is the new player position\n");
	print_point(&infos->grid->player);
	ft_dprintf(DEBUG_OUT, "This is the original grid\n");
	print_grid(infos->grid);
	update_grid(infos->grid, &p, &infos->grid->player);
	ft_dprintf(DEBUG_OUT, "This is the new grid\n");
	print_grid(infos->grid);
	if (!infos->grid->number_of_collectibles)
		update_window(infos->mgrid, &p, &infos->grid->player, \
		&infos->grid->exit);
	else
		update_window(infos->mgrid, &p, &infos->grid->player, NULL);
	end = (infos->grid->number_of_collectibles || ft_memcmp(&infos\
	->grid->player, &infos->grid->exit, sizeof (t_point)));
	if (! end)
	{
		ft_printf("WON!!!\n");
		mlx_loop_end(infos->mgrid->mlx_ptr);
		return (0);
	}
	return (0);
}
