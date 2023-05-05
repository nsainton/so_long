/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:18:59 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/03 12:47:53 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_point(t_point *p, t_cint direction)
{
	p->x = p->x + (direction == RIGHT) - (direction == LEFT);
	p->y = p->y + (direction == DOWN) - (direction == UP);
}

int	valid_move(t_cgrid *grid, t_point *p, t_cint direction)
{
	return (get_point(grid, &(t_point){p->x + (direction == RIGHT) \
	- (direction == LEFT), p->y - (direction == UP) \
	+ (direction == DOWN)}) != '1');
}

int	valid_position(t_cgrid *grid, t_point *p)
{
	return (get_point(grid, p) != '1');
}

void	update_grid(t_grid *grid, t_point *old_pos, t_point *new_pos)
{
	if (get_point(grid, new_pos) == 'C')
	{
		grid->number_of_collectibles --;
		if (! grid->number_of_collectibles)
			set_point_grid(grid, &grid->exit, 'E');
	}
	set_point_grid(grid, new_pos, 'P');
	set_point_grid(grid, old_pos, '0');
	grid->steps ++;
}
