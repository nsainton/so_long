/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:08:14 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/03 10:56:52 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "summary.h"

//Functions from file : debug/debug.c

void	print_tab(char **tab);

void	free_tab(char **tab);

void	print_grid(t_grid *grid);

void	print_node(void *point);

int		print_image(void *mlx_ptr, t_image *img);

//Functions from file : debug/errors.c

void	error_message(t_cint err_code, t_cint fd);

int		free_on_error(t_grid *grid, t_delfunc del, t_cint err_code, \
t_cint fd);

//Functions from file : debug/dwrappers.c

void	null_display(void **mlx_ptr);

void	null_window(void *mlx_ptr, void **win_ptr);

int		image_from_file(void *mlx_ptr, t_image *img, char *filename);

//Functions from file : game/hooks.c

int		controls(int keycode, void *params);

int		end_loop(void *mlx_ptr);

//Functions from file : game/init.c

int		set_game_element(t_mlxgrid *grid, t_cint x, t_cint y, \
t_cchar elem);

int		set_game_elements(t_cgrid *grid, t_mlxgrid *mgrid);

//Functions from file : parsing/readlines.c

char	**readlines(t_cchar *file);

char	**readlines_size(t_cchar *file, int	*size);

//Functions from file : parsing/line_checking.c

int		same_char(char *line, t_cint c, t_csizet width);

int		check_line(char *line, t_elements *elems, t_csizet width, \
t_csizet height);

//Functions from file : parsing/checking.c

int		check_ends(char *beg, char *end, char c, size_t len);

int		check_middle(char **grid, t_elements *el, size_t w, size_t h);

int		check_extension(t_cchar *filename, t_cchar *ext);

int		check_elements(t_elements *el);

//Functions from file : parsing/parsing.c

int		parse_grid(t_grid *grid);

//Functions from file : structures/point.c

void	init_point(t_point *p);

void	set_point(t_point *p, int x, int y);

void	print_point(t_cpoint *p);

t_point	*point_copy(t_cpoint *p);

//Functions from file : structures/dimensions.c

void	set_height(t_dimensions *dim, t_csizet height);

void	set_width(t_dimensions *dim, t_csizet width);

size_t	get_width(t_dimensions *dim);

size_t	get_height(t_dimensions *dim);

//Functions from file : structures/elements.c

void	init_elements(t_elements *e);

void	set_elements(t_elements *e, t_point *ex, t_point *pl, \
t_list **col);

//Functions from file : structures/infos.c

int		clean_clear_params(t_infos *params, t_cint err_code);

//Functions from file : structures/images.c

void	*get_image(t_mlxgrid *grid, t_cint index);

int		put_image(t_mlxgrid *grid, void *img, int x, int y);

int		clear_tile(t_mlxgrid *mgrid, int x, int y);

int		init_images(void *mlx_ptr, t_image sprites[5]);

int		clear_image(t_mlxgrid *mgrid, t_cint index);

//Functions from file : structures/grid.c

void	set_point_grid(t_grid *grid, t_cpoint *coordinates, int elem);

int		init_grid(t_grid *grid, t_cchar *grid_name);

int		get_point(t_cgrid *grid, t_cpoint *coordinates);

void	clear_grid(t_grid *grid, t_delfunc del);

//Functions from file : structures/mlx_grid.c

int		init_tiles(t_mlxgrid *mgrid, t_cint width, t_cint height);

int		init_mgrid(t_mlxgrid *mgrid, t_cgrid *grid, char *win_name);

int		clear_mgrid(t_mlxgrid *mgrid, t_cint err_code);

//Functions from file : printing/update_window.c

int		update_window(t_mlxgrid *grid, t_point *old_pos, \
t_point *new_pos, t_point *exit);

//Functions from file : movement/visited.c

int		add_visited(t_list **visited, t_cpoint *p);

int		is_visited(t_clist *lst, t_cpoint *p);

//Functions from file : movement/move_point.c

void	move_point(t_point *p, t_cint direction);

int		valid_move(t_cgrid *grid, t_point *p, t_cint direction);

int		valid_position(t_cgrid *grid, t_point *p);

void	update_grid(t_grid *grid, t_point *old_pos, t_point *new_pos);

//Functions from file : movement/find_path.c

int		valid_grid(t_grid *grid);

#endif
