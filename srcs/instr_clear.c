/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:17:37 by obelair           #+#    #+#             */
/*   Updated: 2021/09/03 13:49:17 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_one(t_instr *elem, void (*del)(void *))
{
	if (!elem)
		return ;
	(elem->next)->previous = elem->previous;
	(elem->previous)->next = elem->next;
	del(elem);
}

void	clear_instr(t_instr **list, void (*del)(void *))
{
	t_instr	*cur;
	t_instr	*tmp;

	cur = *list;
	if (!*list)
		return ;
	while (cur)
	{
		tmp = cur->next;
		del(cur);
		cur = tmp;
	}
	*list = NULL;
}
