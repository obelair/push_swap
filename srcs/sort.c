/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:26:25 by obelair           #+#    #+#             */
/*   Updated: 2021/08/11 17:16:53 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ascending_sort(t_stack *list)
{
	// printf("-----\n");
	if (!list)
		return (0);
	while (list->next)
	{
		// printf("i : %d | j : %d | cmp : %d\n", list->index, (list->next)->index, list->index + 1 != (list->next)->index);
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
	int	inter;

	inter = 0;
	while (!count_element(td, inter))
		inter++;
	find_first(td, inter);
	find_second(td, inter);
	printf("inter : %d / start : %d / end : %d | f_hold : %d / s_hold : %d\n", inter, td->ind_chunk[inter].start, td->ind_chunk[inter].end, td->first_hold, td->second_hold);
	i = cmp_hold(td);
	cmp_top_stack(td);
	if (i > 0 && ascending_sort(td->a))
	{
		while (i >= 0 && ascending_sort(td->a))
		{
			ra(td, 0);
			if (td->first_hold != td->a->index && td->second_hold != td->a->index)
				cmp_top_stack(td);
			i--;
		}
	}
	else if (i < 0 && ascending_sort(td->a))
	{
		while (i < 0 && ascending_sort(td->a))
		{
			rra(td, 0);
			if (td->first_hold != td->a->index && td->second_hold != td->a->index)
				cmp_top_stack(td);
			i++;
		}
	}
	if (ascending_sort(td->a))
		pb(td);
}
