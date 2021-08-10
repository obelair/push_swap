/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 22:02:52 by obelair           #+#    #+#             */
/*   Updated: 2021/08/10 10:55:52 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_first(t_data *td, int inter)
{
	t_stack	*cur;

	cur = td->a;
	td->first_hold = -1;
	while (td->a && td->first_hold == -1)
	{
		if (td->ind_chunk[inter].start <= td->a->index
			&& td->a->index <= td->ind_chunk[inter].end)
			td->first_hold = td->a->index;
		td->a = td->a->next;
	}
	td->a = cur;
}

void	find_second(t_data *td, int inter)
{
	t_stack	*cur;

	cur = td->a;
	td->second_hold = -1;
	while (cur)
	{
		if (td->ind_chunk[inter].start <= cur->index
			&& cur->index <= td->ind_chunk[inter].end)
			td->second_hold = cur->index;
		cur = cur->next;
	}
}

int	index_element(t_stack *list, t_stack *hold)
{
	int	i;

	i = 0;
	while (list != hold)
	{
		i++;
		list = list->next;
	}
	return (i);
}
