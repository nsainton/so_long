/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visited.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:08:08 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/28 15:34:11 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	add_visited(t_list **visited, t_cpoint *p)
{
	t_list	*lst;

	lst = ft_lstnew((void *)p);
	if (! lst)
		return (UNKNOWN_ERROR);
	ft_lstadd_front(visited, lst);
	return (0);
}

int	is_visited(t_clist *lst, t_cpoint *p)
{
	//ft_dprintf(DEBUG_OUT, "In function : %s\n", __func__);
	while (lst)
	{
		/*
		ft_dprintf(DEBUG_OUT, "The following point has been retrieved\n");
		print_point(content);
		*/
		if (! ft_memcmp((t_cpoint *)lst->content, p, sizeof * p))
			return (1);
		//ft_dprintf(DEBUG_OUT, "The comparison returned a difference\n");
		lst = lst->next;
		//ft_dprintf(DEBUG_OUT, "Next has been retrived\n");
	}
	//ft_dprintf(DEBUG_OUT, "0 will be returned\n");
	return (0);
}
