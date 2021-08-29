/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 22:02:52 by obelair           #+#    #+#             */
/*   Updated: 2021/08/28 18:21:22 by obelair          ###   ########.fr       */
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

void	find_max(t_stack *stack, int *ind)
{
	t_stack	*cur;

	cur = stack;
	*ind = cur->index;
	while (cur)
	{
		if (*ind < cur->index)
			*ind = cur->index;
		cur = cur->next;
	}
}

void	find_min(t_stack *stack, int *ind)
{
	t_stack	*cur;

	cur = stack;
	*ind = cur->index;
	while (cur)
	{
		if (*ind > cur->index)
			*ind = cur->index;
		cur = cur->next;
	}
}

int	find_rot(t_stack *stack, int size, int ind)
{
	t_stack	*cur;
	int		i;

	cur = stack;
	i = 0;
	while (cur->index != ind)
	{
		i++;
		cur = cur->next;
	}
	if (i > size * 0.5)
		return (i - size);
	return (i);
}

int	count_element(t_data *td, int inter)
{
	int		i;
	t_stack	*cur;

	cur = td->a;
	i = 0;
	while (cur)
	{
		if (td->ind_chunk[inter].start <= cur->index
			&& cur->index <= td->ind_chunk[inter].end)
			i++;
		cur = cur->next;
	}
	return (i);
}
