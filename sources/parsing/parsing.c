/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:16:57 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/03 12:55:39 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_grid(t_grid *grid)
{
	int			error;
	t_elements	elems;

	set_elements(&elems, &grid->exit, &grid->player, &grid->collectibles);
	init_elements(&elems);
	grid->width = ft_strlen(*grid->grid) - 1;
	error = check_ends(*grid->grid, *(grid->grid + grid->height - 1), '1', \
	grid->width);
	if (error)
		return (error);
	error = check_middle(grid->grid, &elems, grid->width, grid->height);
	if (error)
		return (error);
	error = check_elements(&elems);
	if (error)
		return (error);
	grid->number_of_collectibles = ft_lstsize(grid->collectibles);
	return (0);
}
