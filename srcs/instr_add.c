/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:14:34 by obelair           #+#    #+#             */
/*   Updated: 2021/09/03 13:23:56 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instr	*last_instr(t_instr *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

static void	add_back(t_instr **list, t_instr *new)
{
	if (!*list)
		*list = new;
	else
	{
		last_instr(*list)->next = new;
		new->previous = last_instr(*list);
	}
}

static void	add_front(t_instr **list, t_instr *new)
{
	if (!*list)
		*list = new;
	else
	{
		(*list)->previous = new;
		new->next = *list;
		*list = new;
	}
}

int	add_instr(t_instr **list, t_instr *new, int back)
{
	if (!new)
		return (-1);
	if (back)
	{
		add_back(list, new);
		if (!*list)
			return (-1);
	}
	else
	{
		add_front(list, new);
		if (!*list)
			return (-1);
	}
	return (0);
}
