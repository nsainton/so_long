/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:58:46 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/23 12:32:16 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_point(t_point *p)
{
	p->x = -1;
	p->y = -1;
}

void	set_point(t_point *p, int x, int y)
{
	p->x = x;
	p->y = y;
}

void	print_point(t_cpoint *p)
{
	ft_dprintf(DEBUG_OUT, "x : %d\n", p->x);
	ft_dprintf(DEBUG_OUT, "y : %d\n", p->y);
}

t_point	*point_copy(t_cpoint *p)
{
	t_point	*new_point;

	new_point = ft_calloc (1, sizeof * new_point);
	if (! new_point)
		return (new_point);
	return (ft_memcpy(new_point, p, sizeof * p));
}
