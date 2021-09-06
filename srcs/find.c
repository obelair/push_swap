/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 22:02:52 by obelair           #+#    #+#             */
/*   Updated: 2021/09/06 16:47:26 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_hold(t_data *td, int inter, int first)
{
	t_nbr	*cur;

	cur = td->a->lst;
	if (first)
	{
		td->f_hold = -1;
		while (cur && td->f_hold == -1)
		{
			if (td->ind_chunk[inter].start <= cur->ind
				&& cur->ind <= td->ind_chunk[inter].end)
				td->f_hold = cur->ind;
			cur = cur->next;
		}
	}
	else
	{
		td->s_hold = -1;
		while (cur)
		{
			if (td->ind_chunk[inter].start <= cur->ind
				&& cur->ind <= td->ind_chunk[inter].end)
				td->s_hold = cur->ind;
			cur = cur->next;
		}
	}
}

void	find_min_max(t_nbr *stack, int *min, int *max)
{
	t_nbr	*cur;

	cur = stack;
	*min = cur->ind;
	*max = cur->ind;
	while (cur)
	{
		if (*min > cur->ind)
			*min = cur->ind;
		if (*max < cur->ind)
			*max = cur->ind;
		cur = cur->next;
	}
}

int	find_ind(t_nbr *stack, int size, int ind)
{
	t_nbr	*cur;
	int		i;

	cur = stack;
	i = 0;
	while (cur->ind != ind)
	{
		i++;
		cur = cur->next;
	}
	if (i > size * 0.5)
		return (i - size);
	return (i);
}
