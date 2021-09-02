/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:10:43 by obelair           #+#    #+#             */
/*   Updated: 2021/09/01 12:36:26 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_data *td)
{
	int	i;

	i = td->a->len;
	while (i > 0 && ascending_sort(td->a->lst))
	{
		// cmp_top_stack(td);
		if ((td->a->lst->ind >> td->bit) & 1)
			ra(td, 0);
		else
			pb(td);
		i--;
	}
	while (td->b->len)
		pa(td);
	td->bit++;
}
