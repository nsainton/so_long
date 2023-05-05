/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:00:44 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/28 11:01:20 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_elements(t_elements *e)
{
	init_point(e->exit);
	init_point(e->player);
}

void	set_elements(t_elements *e, t_point *ex, t_point *pl, t_list **col)
{
	e->player = pl;
	e->exit = ex;
	e->collectibles = col;
}
