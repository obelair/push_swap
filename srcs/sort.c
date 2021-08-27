/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:26:25 by obelair           #+#    #+#             */
/*   Updated: 2021/08/27 17:35:34 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ascending_sort(t_stack *list)
{
	if (!list)
		return (0);
	while (list->next)
	{
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

void	rev_sorting_list(t_data *td)
{
	int	i;

	find_last(td);
	i = find_rot(td);
	if (i < 0)
	{
		while (i < 0)
		{
			rrb(td, 0);
			i++;
		}
	}
	else if (i > 0)
	{
		while (i >= 0)
		{
			rb(td, 0);
			i--;
		}
	}
	pa(td);
}
