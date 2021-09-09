/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:05:44 by obelair           #+#    #+#             */
/*   Updated: 2021/09/09 11:39:47 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	use_r_or_rr(t_data *td, int i, void (*r)(t_data *, int, int),
	void (*rr)(t_data *, int, int))
{
	if (i < 0)
	{
		while (i < 0)
		{
			rr(td, 0, 1);
			i++;
		}
	}
	else if (i > 0)
	{
		while (i > 0)
		{
			r(td, 0, 1);
			i--;
		}
	}
}

void	asc_a_r_or_rr(t_data *td, int i, void (*r)(t_data *, int, int),
	void (*rr)(t_data *, int, int))
{
	if (i > 0 && ascending_sort(td->a->lst))
	{
		while (i > 0 && ascending_sort(td->a->lst))
		{
			r(td, 0, 1);
			i--;
		}
	}
	else if (i < 0 && ascending_sort(td->a->lst))
	{
		while (i < 0 && ascending_sort(td->a->lst))
		{
			rr(td, 0, 1);
			i++;
		}
	}
}
