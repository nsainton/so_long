/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:24:49 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/02 16:24:04 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H
# include "structures.h"

typedef struct s_point		t_point;

typedef struct s_elements	t_elements;

typedef struct s_dimensions	t_dimensions;

typedef struct s_grid		t_grid;

typedef const t_grid		t_cgrid;

typedef const t_point		t_cpoint;

typedef struct s_mlxgrid	t_mlxgrid;

typedef struct s_image		t_image;

typedef struct s_infos		t_infos;
#endif
