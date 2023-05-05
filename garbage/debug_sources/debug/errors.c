/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:05:09 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/01 13:54:07 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_messages(char *messages[20])
{
	messages[WRONG_EXTENSION % WRONG_EXTENSION] = W_EXT;
	messages[NO_PLAYER % WRONG_EXTENSION] = NEP;
	messages[NO_EXIT % WRONG_EXTENSION] = NEE;
	messages[TOO_MUCH_PLAYERS % WRONG_EXTENSION] = TMP;
	messages[TOO_MUCH_EXITS % WRONG_EXTENSION] = TME;
	messages[NO_COLLECTIBLES % WRONG_EXTENSION] = NC;
	messages[WRONG_WALLS % WRONG_EXTENSION] = WALL_MESSAGE;
	messages[CANT_REACH_EXIT % WRONG_EXTENSION] = CRE;
	messages[CANT_REACH_COLLECTIBLE % WRONG_EXTENSION] = CRC;
	messages[EMPTY_MAP % WRONG_EXTENSION] = EM;
	messages[UNRECOGNIZED_CHARACTER % WRONG_EXTENSION] = UC;
	messages[WRONG_MAP_DIMENSIONS % WRONG_EXTENSION] = WD;
	messages[NOT_FOUND % WRONG_EXTENSION] = NF;
	messages[UNKNOWN_ERROR % WRONG_EXTENSION] = UK;
}

static char	*chose_message(t_cint err_code)
{
	static char *messages[20];

	if (! messages[0])
		init_messages(messages);
	return (messages[err_code % WRONG_EXTENSION]);
}

static void	print_error_message(t_cchar *message, t_cint fd)
{
	print_color_string(message, RED, fd);
	ft_putchar_fd('\n', fd);
}

void	error_message(t_cint err_code, t_cint fd)
{
	print_error_message(chose_message(err_code), fd);
}

int		free_on_error(t_grid *grid, t_delfunc del, t_cint err_code, t_cint fd)
{
	error_message(err_code, fd);
	if (grid->grid)
		free_tab(grid->grid);
	ft_lstclear(&grid->collectibles, del);
	return (EXIT_FAILURE);
}
