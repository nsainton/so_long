/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:30:26 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/09 11:46:29 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H
# define SPRITES "Sprites/"
# define P_NAME "player"
# define C_NAME "collectible"
# define E_NAME "exit"
# define T_NAME "tile"
# define W_NAME "wall"
# define Pl "Sprites/xpm/player.xpm"
# define Co "Sprites/xpm/collectible.xpm"
# define Ex "Sprites/xpm/exit.xpm"
# define Ti "Sprites/xpm/tile.xpm"
# define Wa "Sprites/xpm/wall.xpm"
# define S_EXT ".xpm"
# define TILE_SIZE 80
# define SPRITE_SIZE 80
# define NAME(img) SPRITES #img S_EXT
#endif
