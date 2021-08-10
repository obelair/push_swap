/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 10:06:58 by obelair           #+#    #+#             */
/*   Updated: 2021/08/10 13:35:53 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cmp_r_or_rr(t_data *td, int f_ind, int s_ind)
{
	if (f_ind < s_ind)
		return (f_ind);
	else if (f_ind > s_ind)
		return (-s_ind);
	else
	{
		if (td->first_hold < td->second_hold)
			return (f_ind);
		else
			return (-s_ind);
	}
}

int	cmp_hold(t_data *td)
{
	int		first_ind;
	int		second_ind;
	int		i;
	t_stack	*cur;

	cur = td->a;
	first_ind = -1;
	second_ind = -1;
	i = 0;
	while (cur && (first_ind == -1 || second_ind == -1))
	{
		if (cur->index == td->first_hold)
			first_ind = i;
		else if (cur->index == td->second_hold)
			second_ind = i;
		i++;
		cur = cur->next;
	}
	return (cmp_r_or_rr(td, first_ind, td->len_a - second_ind));
}

int	cmp_same_chunk(t_data *td, t_stack *list)
{
	int	chunk1;
	int	chunk2;
	int	i;

	chunk1 = 0;
	chunk2 = 0;
	i = 0;
	while (i < td->chunk && !chunk1 && !chunk2)
	{
		if (td->ind_chunk[i].start <= list->index
			&& list->index <= td->ind_chunk[i].end)
			chunk1 = 1;
		if (td->ind_chunk[i].start <= (list->next)->index
			&& (list->next)->index <= td->ind_chunk[i].end)
			chunk2 = 1;
		i++;
	}
	if (chunk1 && chunk2)
		return (0);
	return (1);
}

void	cmp_top_stack(t_data *td)
{
	if (td->len_a > 1 && td->len_b > 1)
	{
		if ((td->a->index > (td->a->next)->index
				&& (td->a->index - 1 == (td->a->next)->index
					|| cmp_same_chunk(td, td->a)))
			&& (td->b->index < (td->b->next)->index
				&& (td->b->index + 1 == (td->b->next)->index
					|| cmp_same_chunk(td, td->b))))
			ss(td);
	}
	else if (td->len_a > 1)
	{
		if (td->a->index > (td->a->next)->index
			&& (td->a->index - 1 == (td->a->next)->index
				|| cmp_same_chunk(td, td->a)))
			sa(td, 0);
	}
	else if (td->len_b > 1)
	{
		if (td->b->index < (td->b->next)->index
			&& (td->b->index + 1 == (td->b->next)->index
				|| cmp_same_chunk(td, td->b)))
			sb(td, 0);
	}
}
