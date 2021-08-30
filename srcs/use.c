/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:05:44 by obelair           #+#    #+#             */
/*   Updated: 2021/08/30 16:22:48 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	use_r_or_rr(t_data *td, int i, void (*r)(t_data *, int),
	void (*rr)(t_data *, int))
{
	if (i < 0)
	{
		while (i < 0)
		{
			rr(td, 0);
			i++;
		}
	}
	else if (i > 0)
	{
		while (i > 0)
		{
			r(td, 0);
			i--;
		}
	}
}

void	asc_a_r_or_rr(t_data *td, int i, void (*r)(t_data *, int),
	void (*rr)(t_data *, int))
{
	if (i > 0 && ascending_sort(td->a->list))
	{
		while (i > 0 && ascending_sort(td->a->list))
		{
			r(td, 0);
			i--;
		}
	}
	else if (i < 0 && ascending_sort(td->a->list))
	{
		while (i < 0 && ascending_sort(td->a->list))
		{
			rr(td, 0);
			i++;
		}
	}
}