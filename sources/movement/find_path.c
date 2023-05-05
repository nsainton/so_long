/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:42:10 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/03 14:01:29 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
static int	get_collectibles(t_cgrid *grid, t_list **collectibles)
{
	int		width;
	int		height;
	t_list	*lst;
	t_point	p;

	lst = NULL;
	height = 1;
	while (height < grid->height)
	{
		width = 1;
		while (width < grid->width)
		{
			if (*(*(grid->grid + height) + width++) != 'C')
				continue ;
			ft_dprintf(DEBUG_OUT, "This is x : %d\n", width - 1);
			ft_dprintf(DEBUG_OUT, "This is y : %d\n", height);
			set_point(&p, width - 1, height);
			lst = ft_lstnew_cpy(&p, sizeof (t_point));
			ft_lstadd_front(collectibles, lst);
			ft_lstiter(*collectibles, print_node);
		}
		height ++;
	}
	return (0);
}
*/

static int	valid_grid_rec(t_cgrid *grid, t_cpoint *p, t_cpoint *d, t_list **visited)
{
	int		index;
	t_point	test;
	int		point;
	int		error;

	point = get_point(grid, d);
	if (! ft_memcmp(d, p, sizeof * p))
		return (0);
	if (add_visited(visited, p))
		return (UNKNOWN_ERROR);
	index = UP;
	while (index <= RIGHT)
	{
		ft_memcpy(&test, p, sizeof test);
		move_point(&test, index);
		index ++;
		if (is_visited(*visited, &test) || ! valid_position(grid, &test))
			continue ;
		error = valid_grid_rec(grid, &test, d, visited);
		if (! error || error == UNKNOWN_ERROR)
			return (error);
	}
	ft_lstdel_front(visited, NULL);
	return ((point == 'C') * CANT_REACH_COLLECTIBLE \
	+ (point == 'E') * CANT_REACH_EXIT);
}

static int	reach_collectibles(t_grid *grid)
{
	t_list	*visited;
	t_list	*collectibles;
	int		error;

	visited = NULL;
	error = 0;
	collectibles = grid->collectibles;
	while (collectibles)
	{
		error = valid_grid_rec(grid, &grid->player, \
		(t_cpoint *)collectibles->content, &visited);
		ft_lstclear(&visited, NULL);
		if (error)
			break ;
		collectibles = collectibles->next;
	}
	return (error);
}

int	valid_grid(t_grid *grid)
{
	t_list			*visited;
	int				error;

	error = reach_collectibles(grid);
	if (error)
		return (error);
	visited = NULL;
	error = valid_grid_rec(grid, &grid->player, &grid->exit, &visited);
	ft_lstclear(&visited, NULL);
	ft_lstclear(&grid->collectibles, free);
	set_point_grid(grid, &grid->exit, '0');
	return (error);
}
