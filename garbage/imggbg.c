/*
static void	clear_img_tab(t_mlxgrid *mgrid)
{
	int	width;
	int	height;
	int	w_index;
	int	h_index;

	width = *mgrid->width;
	height = *mgrid->height;
	h_index = 0;
	while (h_index < height)
	{
		w_index = 0;
		while (w_index++ < width)
		{
			if (*(*(mgrid->images + h_index) + w_index - 1))
				mlx_destroy_image(mgrid->mlx_ptr, \
				*(*(mgrid->images + h_index) + w_index - 1));
		}
		free(*(mgrid->images + h_index));
		h_index ++;
	}
	free(mgrid->images);
	mgrid->images = NULL;
}
*/

/*
static int free_img_tab(void ***tab, t_cint u_bound)
{
	int	index;

	index = 0;
	while (index < u_bound)
	{
		free(*(tab + index));
		*(tab + index) = NULL;
	}
	return (UNKNOWN_ERROR);
}

int	build_img_tab(void ***images, t_cint width, t_cint height)
{
	int	h_index;

	h_index = 0;

	images = ft_calloc(height, sizeof * images);
	if (! images)
		return (UNKNOWN_ERROR);
	while (h_index < height)
	{
		*(images + h_index) = ft_calloc(width, sizeof **images); 
		if (! *(images + h_index))
		{
			free_img_tab(images, height);
			free(images);
			return (UNKNOWN_ERROR);
		}
		h_index ++;
	}
	return (0);
}
*/
