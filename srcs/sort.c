/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:26:25 by obelair           #+#    #+#             */
/*   Updated: 2021/09/21 10:17:32 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ascending_sort(t_nbr *list)
{
	if (!list)
		return (0);
	while (list->next)
	{
		if (list->ind > (list->next)->ind)
			return (1);
		list = list->next;
	}
	return (0);
}

int	descending_sort(t_nbr *list)
{
	if (!list)
		return (0);
	while (list->next)
	{
		if (list->ind < (list->next)->ind)
			return (1);
		list = list->next;
	}
	return (0);
}
