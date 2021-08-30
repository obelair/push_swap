/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:28:38 by obelair           #+#    #+#             */
/*   Updated: 2021/08/30 03:40:22 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_back(t_nbr **list, t_nbr *new)
{
	if (!*list)
		*list = new;
	else
		last_element(*list)->next = new;
}

static void	add_front(t_nbr **list, t_nbr *new)
{
	if (!*list)
		*list = new;
	else
	{
		new->next = *list;
		*list = new;
	}
}

int	add_element(t_nbr **list, t_nbr *new, int back)
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
