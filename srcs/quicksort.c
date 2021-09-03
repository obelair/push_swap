/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:32:27 by obelair           #+#    #+#             */
/*   Updated: 2021/09/03 10:53:05 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort(t_data *td, int bit)
{
	int	i;

	if (!td->b->len && td->nb_element >> bit > 16)
	{
		find_min_max(td->a->lst, &td->f_hold, &td->s_hold);
		i = td->a->len;
		while (i > 0)
		{
			if (td->a->lst->ind <= (td->s_hold + td->f_hold) * 0.5)
				pb(td);
			else
				ra(td, 0);
			i--;
		}
	}
	else if (td->nb_element >> bit > 16)
	{
		find_min_max(td->b->lst, &td->f_hold, &td->s_hold);
		i = td->b->len;
		while (i > 0)
		{
			if (td->b->lst->ind > (td->s_hold + td->f_hold) * 0.5)
				pa(td);
			else
				rb(td, 0);
			i--;
		}
		quicksort(td, bit + 1);
		while (td->b->len)
			pa(td);
	}
	if (td->nb_element >> bit <= 16)
		return ;
	if (td->b->len)
		quicksort(td, bit + 1);
}
