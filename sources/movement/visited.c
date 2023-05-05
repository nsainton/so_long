/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visited.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:08:08 by nsainton          #+#    #+#             */
/*   Updated: 2023/04/03 12:47:02 by nsainton         ###   ########.fr       */
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
	while (lst)
	{
		if (! ft_memcmp((t_cpoint *)lst->content, p, sizeof * p))
			return (1);
		lst = lst->next;
	}
	return (0);
}
