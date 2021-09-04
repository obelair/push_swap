/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:10:43 by obelair           #+#    #+#             */
/*   Updated: 2021/09/04 16:55:49 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_data *td)
{
	int	i;

	i = td->a->len;
	while (i > 0 && ascending_sort(td->a->lst))
	{
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
