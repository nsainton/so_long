/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:38:52 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/01 14:05:56 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_symbols
{
	SP,
	WALL,
	COL,
	EXIT,
	PLAYER
}			t_symbols;

typedef enum e_errors
{
	WRONG_EXTENSION = 20,
	NO_PLAYER,
	NO_EXIT,
	TOO_MUCH_PLAYERS,
	TOO_MUCH_EXITS,
	NO_COLLECTIBLES,
	WRONG_WALLS,
	CANT_REACH_EXIT,
	CANT_REACH_COLLECTIBLE,
	EMPTY_MAP,
	UNRECOGNIZED_CHARACTER,
	WRONG_MAP_DIMENSIONS,
	NOT_FOUND,
	UNKNOWN_ERROR
}			t_errors;

typedef enum e_directions
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}			t_directions;
#endif
