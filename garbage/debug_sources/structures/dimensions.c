/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:23:26 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/21 11:26:49 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_height(t_dimensions *dim, t_csizet height)
{
	*dim->height = height;
}

void	set_width(t_dimensions *dim, t_csizet width)
{
	*dim->width = width;
}

size_t	get_width(t_dimensions *dim)
{
	return (*dim->width);
}

size_t	get_height(t_dimensions *dim)
{
	return (*dim->height);
}
