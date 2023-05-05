/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:16:08 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/02 17:18:45 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_clear_params(t_infos *params, t_cint err_code)
{
	clear_grid(params->grid, free);
	return (clear_mgrid(params->mgrid, err_code));
}
