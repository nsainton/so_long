/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dwrappers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:08:12 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/02 11:04:21 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	null_display(void **mlx_ptr)
{
	mlx_destroy_display(*mlx_ptr);
	free(*mlx_ptr);
	*mlx_ptr = NULL;
}

void	null_window(void *mlx_ptr, void **win_ptr)
{	
	mlx_destroy_window(mlx_ptr, *win_ptr);
	*win_ptr = NULL;
}

int	image_from_file(void *mlx_ptr, t_image *img, char *filename)
{
	ft_dprintf(DEBUG_OUT, "In function : %s\n", __func__);
	ft_dprintf(DEBUG_OUT, "This is the path to your image : %s\n", filename);
	img->image = mlx_xpm_file_to_image(mlx_ptr, filename, &img->width, \
	&img->height);
	ft_dprintf(DEBUG_OUT, "This is the pointer to your image : %p\n", \
	img->image);
	return (UNKNOWN_ERROR * (img->image == NULL));
}
