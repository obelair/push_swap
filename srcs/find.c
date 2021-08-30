/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 22:02:52 by obelair           #+#    #+#             */
/*   Updated: 2021/08/30 15:38:07 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_hold(t_data *td, int inter, int first)
{
	t_nbr	*cur;

	cur = td->a->list;
	if (first)
	{
		td->first_hold = -1;
		while (cur && td->first_hold == -1)
		{
			if (td->ind_chunk[inter].start <= cur->index
				&& cur->index <= td->ind_chunk[inter].end)
				td->first_hold = cur->index;
			cur = cur->next;
		}
	}
	else
	{
		td->second_hold = -1;
		while (cur)
		{
			if (td->ind_chunk[inter].start <= cur->index
				&& cur->index <= td->ind_chunk[inter].end)
				td->second_hold = cur->index;
			cur = cur->next;
		}
	}
}

void	find_min_max(t_nbr *stack, int *ind, int min)
{
	t_nbr	*cur;

	cur = stack;
	*ind = cur->index;
	if (!min)
	{
		while (cur)
		{
			if (*ind < cur->index)
				*ind = cur->index;
			cur = cur->next;
		}
	}
	else
	{
		while (cur)
		{
			if (*ind > cur->index)
				*ind = cur->index;
			cur = cur->next;
		}
	}
}

int	find_rot(t_nbr *stack, int size, int ind)
{
	t_nbr	*cur;
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
	t_nbr	*cur;

	cur = td->a->list;
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
