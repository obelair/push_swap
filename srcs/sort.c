/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:26:25 by obelair           #+#    #+#             */
/*   Updated: 2021/08/10 14:45:27 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ascending_sort(t_stack *list)
{
	printf("-----\n");
	if (!list)
		return (0);
	while (list->next)
	{
		printf("i : %d | j : %d | cmp : %d\n", list->index, (list->next)->index, list->index + 1 != (list->next)->index);
		if (list->index + 1 != (list->next)->index)
			return (1);
		list = list->next;
	}
	return (0);
}

int	descending_sort(t_stack *list)
{
	if (!list)
		return (0);
	while (list->next)
	{
		if (list->index - 1 != (list->next)->index)
			return (1);
		list = list->next;
	}
	return (0);
}

void	sorting_list(t_data *td)
{
	int	i;

	cmp_top_stack(td);
	find_first(td, 0);
	find_second(td, 0);
	i = cmp_hold(td);
	if (i > 0 && ascending_sort(td->a))
	{
		while (i >= 0)
		{
			ra(td, 0);
			i--;
		}
	}
	else if (i < 0 && ascending_sort(td->a))
	{
		while (i < 0)
		{
			rra(td, 0);
			i++;
		}
	}
	if (ascending_sort(td->a))
		pb(td);
}
