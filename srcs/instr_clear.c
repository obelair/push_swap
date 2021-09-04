/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:17:37 by obelair           #+#    #+#             */
/*   Updated: 2021/09/04 23:00:21 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_one(t_instr *elem, void (*del)(void *))
{
	t_instr	*tmp;

	if (!elem)
		return ;
	tmp = elem;
	elem = elem->next;
	(tmp->next)->previous = tmp->previous;
	(tmp->previous)->next = tmp->next;
	del(tmp);
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
