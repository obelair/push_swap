/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 10:06:58 by obelair           #+#    #+#             */
/*   Updated: 2021/08/30 15:55:59 by obelair          ###   ########.fr       */
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
	t_nbr	*cur;

	cur = td->a->list;
	first_ind = -1;
	second_ind = -1;
	i = 0;
	while (cur && (first_ind == -1 || second_ind == -1))
	{
		if (cur->index == td->first_hold)
			first_ind = i;
		if (cur->index == td->second_hold)
			second_ind = i;
		i++;
		cur = cur->next;
	}
	return (cmp_r_or_rr(td, first_ind, td->a->len - second_ind));
}

int	cmp_same_chunk(t_data *td, t_nbr *list)
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
		return (1);
	return (0);
}

void	cmp_top_stack(t_data *td)
{
	if (td->a->len > 1 && td->b->len > 1)
	{
		if ((td->a->list->index > (td->a->list->next)->index
				&& (td->a->list->index - 1 == (td->a->list->next)->index
					|| cmp_same_chunk(td, td->a->list)))
			&& (td->b->list->index < (td->b->list->next)->index
				&& (td->b->list->index + 1 == (td->b->list->next)->index
					|| cmp_same_chunk(td, td->b->list))))
			ss(td);
		if (td->a->list->index > (td->a->list->next)->index
			&& (td->a->list->index - 1 == (td->a->list->next)->index
				|| cmp_same_chunk(td, td->a->list)))
			sa(td, 0);
		if (td->b->list->index < (td->b->list->next)->index
			&& (td->b->list->index + 1 == (td->b->list->next)->index
				|| cmp_same_chunk(td, td->b->list)))
			sb(td, 0);
	}
	else if (td->a->len > 1)
	{
		if (td->a->list->index > (td->a->list->next)->index
			&& (td->a->list->index - 1 == (td->a->list->next)->index
				|| cmp_same_chunk(td, td->a->list)))
			sa(td, 0);
	}
}
