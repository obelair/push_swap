/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 22:02:52 by obelair           #+#    #+#             */
/*   Updated: 2021/08/30 19:44:34 by obelair          ###   ########.fr       */
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

int	count_element(t_data *td, int inter)
{
	int		i;
	t_nbr	*cur;

	cur = td->a->lst;
	i = 0;
	while (cur)
	{
		if (td->ind_chunk[inter].start <= cur->ind
			&& cur->ind <= td->ind_chunk[inter].end)
			i++;
		cur = cur->next;
	}
	return (i);
}
