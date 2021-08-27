/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 22:02:52 by obelair           #+#    #+#             */
/*   Updated: 2021/08/27 07:48:29 by obelair          ###   ########lyon.fr   */
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

void	find_last(t_data *td)
{
	t_stack	*cur;

	cur = td->b;
	td->first_hold = cur->index;
	while (cur)
	{
		if (td->first_hold < cur->index)
			td->first_hold = cur->index;
		cur = cur->next;
	}
}

int	find_rot(t_data *td)
{
	t_stack	*cur;
	int		i;

	cur = td->b;
	i = 0;
	while (cur->index != td->first_hold)
	{
		i++;
		cur = cur->next;
	}
	if (i > td->len_b * 0.5)
		return (i - td->len_b);
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
