/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:28:38 by obelair           #+#    #+#             */
/*   Updated: 2021/08/04 19:22:13 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_back(t_stack **list, t_stack *new)
{
	if (!*list)
		*list = new;
	else
		last_element(*list)->next = new;
}

static void	add_front(t_stack **list, t_stack *new)
{
	if (!*list)
		*list = new;
	else
	{
		new->next = *list;
		*list = new;
	}
}

int	add_element(t_stack **list, t_stack *new, int back)
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
