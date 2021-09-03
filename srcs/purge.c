/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:51:20 by obelair           #+#    #+#             */
/*   Updated: 2021/09/03 14:33:13 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instr	*purge_pa_pb(t_instr *elem, int pa, int pb)
{
	t_instr	*start;
	int		nb_pa;
	int		nb_pb;

	start = elem;
	elem = elem->next;
	nb_pa = pa;
	nb_pb = pb;
	while (elem->next && pa != pb)
	{
		if (!ft_strchr(elem->op, "pa") && pa != pb)
			nb_pa++;
		else if (!ft_strchr(elem->op, "pb") && pa != pb)
			nb_pb++;
		else
			break ;
		elem = elem->next;
	}
	if (pa == pb)
		return (start);
	return (elem);
}

void	purge_instr(t_instr **list)
{
	t_instr	*tmp;
	t_instr	*cur;

	if (!*list)
		return ;
	cur = *list;
	while (cur->next)
	{
		tmp = NULL;
		if (!ft_strcmp(cur->op, "pb"))
			tmp = purge_pa_pb(cur, 0, 1);
		else if (!ft_strcmp(cur->op, "pa"))
			tmp = purge_pa_pb(cur, 0, 1);
		cur = cur->next;
		if (cur->previous == tmp)
			del_one(tmp, &free);
		else if (tmp)
			cur = tmp;
	}
}
