/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 10:06:58 by obelair           #+#    #+#             */
/*   Updated: 2021/09/21 10:17:01 by obelair          ###   ########lyon.fr   */
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
		if (td->f_hold < td->s_hold)
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

	cur = td->a->lst;
	first_ind = -1;
	second_ind = -1;
	i = 0;
	while (cur && (first_ind == -1 || second_ind == -1))
	{
		if (cur->ind == td->f_hold)
			first_ind = i;
		if (cur->ind == td->s_hold)
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
		if (td->ind_chunk[i].start <= list->ind
			&& list->ind <= td->ind_chunk[i].end)
			chunk1 = 1;
		if (td->ind_chunk[i].start <= (list->next)->ind
			&& (list->next)->ind <= td->ind_chunk[i].end)
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
		if ((td->a->lst->ind > (td->a->lst->next)->ind
				&& (td->a->lst->ind - 1 == (td->a->lst->next)->ind
					|| cmp_same_chunk(td, td->a->lst)))
			&& (td->b->lst->ind < (td->b->lst->next)->ind
				&& (td->b->lst->ind + 1 == (td->b->lst->next)->ind
					|| cmp_same_chunk(td, td->b->lst))))
			ss(td, 1, 1);
		if (td->a->lst->ind > (td->a->lst->next)->ind
			&& (td->a->lst->ind - 1 == (td->a->lst->next)->ind
				|| cmp_same_chunk(td, td->a->lst)))
			sa(td, 0, 1);
	}
	else if (td->a->len > 1)
	{
		if (td->a->lst->ind > (td->a->lst->next)->ind
			&& (td->a->lst->ind - 1 == (td->a->lst->next)->ind
				|| cmp_same_chunk(td, td->a->lst)))
			sa(td, 0, 1);
	}
}
