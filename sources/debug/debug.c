/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:22:55 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/03 12:58:59 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_tab(char **tab)
{
	while (*tab)
	{
		ft_dprintf(PRINT_OUT, "%s\n", *tab);
		tab ++;
	}
}

void	free_tab(char **tab)
{
	char	**cpy;

	cpy = tab;
	while (*tab)
	{
		free(*tab);
		tab ++;
	}
	free(cpy);
}

void	print_grid(t_grid *grid)
{
	ft_dprintf(PRINT_OUT, "This is the grid\n");
	print_tab(grid->grid);
	ft_dprintf(PRINT_OUT, "This is the player position\n");
	print_point(&grid->player);
	ft_dprintf(PRINT_OUT, "This is the exit position\n");
	print_point(&grid->exit);
	ft_dprintf(PRINT_OUT, "This is the number of collectibles : %d\n"\
	, grid->number_of_collectibles);
}

void	print_node(void *point)
{
	t_point	*p;

	p = (t_point *)point;
	ft_dprintf(DEBUG_OUT, "(%d, %d) -> ", p->x, p->y);
}

int	print_image(void *mlx_ptr, t_image *img)
{
	void	*win;

	win = mlx_new_window(mlx_ptr, img->width + 10, \
	img->height + 10, "TEST");
	if (! win)
		return (1);
	mlx_put_image_to_window(mlx_ptr, win, img->image, 0, 0);
	sleep(4);
	mlx_destroy_window(mlx_ptr, win);
	return (0);
}
