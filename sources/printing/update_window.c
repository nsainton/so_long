/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:54:51 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/02 17:46:42 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_window(t_mlxgrid *grid, t_point *old_pos, t_point *new_pos, t_point *exit)
{
	int	error;

	error = clear_tile(grid, old_pos->x, old_pos->y);
	error += clear_tile(grid, new_pos->x, new_pos->y);
	if (exit)
		error += set_game_element(grid, exit->x, exit->y, 'E');
	error += set_game_element(grid, new_pos->x, new_pos->y, 'P');
	return (error > 0);
}
