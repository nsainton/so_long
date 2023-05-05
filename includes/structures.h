/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:11:16 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/03 09:13:57 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "libft.h"

struct s_point
{
	int	x;
	int	y;
};

struct s_elements
{
	struct s_point	*exit;
	struct s_point	*player;
	t_list			**collectibles;
};

struct s_dimensions
{
	int	*width;
	int	*height;
};

struct s_grid
{
	char			**grid;
	int				width;
	int				height;
	struct s_point	player;
	struct s_point	exit;
	t_list			*collectibles;
	int				number_of_collectibles;
	size_t			steps;
};

struct	s_image
{
	void	*image;
	int		width;
	int		height;
};

struct s_mlxgrid
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_image	images[5];
	int				width;
	int				height;
};

struct s_infos
{
	struct s_grid		*grid;
	struct s_mlxgrid	*mgrid;
};
#endif
