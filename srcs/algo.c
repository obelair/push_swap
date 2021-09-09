/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:49:15 by obelair           #+#    #+#             */
/*   Updated: 2021/09/09 11:37:26 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_3(t_data *td)
{
	find_min_max(td->a->lst, &td->f_hold, &td->s_hold);
	cmp_top_stack(td);
	if ((td->a->lst->next)->ind == td->s_hold && ascending_sort(td->a->lst))
		rra(td, 0, 1);
	else if (ascending_sort(td->a->lst))
		ra(td, 0, 1);
	cmp_top_stack(td);
}

void	algo_5(t_data *td)
{
	int	i;

	find_min_max(td->a->lst, &td->f_hold, &td->s_hold);
	i = find_ind(td->a->lst, td->a->len, td->f_hold);
	if (ft_abs(find_ind(td->a->lst, td->a->len, td->f_hold))
		> ft_abs(find_ind(td->a->lst, td->a->len, td->s_hold)))
		i = find_ind(td->a->lst, td->a->len, td->s_hold);
	asc_a_r_or_rr(td, i, ra, rra);
	if (td->a->lst->ind == td->s_hold && !ascending_sort(td->a->lst->next))
		ra(td, 0, 1);
	else if (ascending_sort(td->a->lst))
	{
		pb(td, 1);
		if (td->f_hold == td->b->lst->ind)
			i = find_ind(td->a->lst, td->a->len, td->s_hold);
		else
			i = find_ind(td->a->lst, td->a->len, td->f_hold);
		asc_a_r_or_rr(td, i, ra, rra);
		if (ascending_sort(td->a->lst))
		{
			pb(td, 1);
			algo_3(td);
		}
	}
}

void	algo_chunk_start(t_data *td)
{
	int	i;
	int	inter;

	inter = 0;
	while (!nb_into_chunk(td, inter))
		inter++;
	find_hold(td, inter, 1);
	find_hold(td, inter, 0);
	i = cmp_hold(td);
	asc_a_r_or_rr(td, i, ra, rra);
	if (ascending_sort(td->a->lst))
	{
		pb(td, 1);
		if (td->a->len == 5)
			algo_5(td);
	}
}

void	algo_chunk_end(t_data *td)
{
	int		i;

	find_min_max(td->b->lst, &td->f_hold, &td->s_hold);
	i = find_ind(td->b->lst, td->b->len, td->s_hold);
	use_r_or_rr(td, i, rb, rrb);
	find_min_max(td->a->lst, &td->f_hold, &td->s_hold);
	if (td->b->lst->ind < td->f_hold || td->b->lst->ind > td->s_hold)
	{
		i = find_ind(td->a->lst, td->a->len, td->f_hold);
		use_r_or_rr(td, i, ra, rra);
	}
	else
	{
		i = insert_into_a(td);
		use_r_or_rr(td, i, ra, rra);
	}
	pa(td, 1);
	if (!td->b->len)
	{
		find_min_max(td->a->lst, &td->f_hold, &td->s_hold);
		i = find_ind(td->a->lst, td->a->len, td->f_hold);
		use_r_or_rr(td, i, ra, rra);
	}
}
