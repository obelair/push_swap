/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:49:15 by obelair           #+#    #+#             */
/*   Updated: 2021/09/04 22:40:11 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_3(t_data *td)
{
	find_min_max(td->a->lst, &td->f_hold, &td->s_hold);
	cmp_top_stack(td);
	if ((td->a->lst->next)->ind == td->s_hold && ascending_sort(td->a->lst))
		rra(td, 0);
	else if (ascending_sort(td->a->lst))
		ra(td, 0);
	cmp_top_stack(td);
}

void	sorting_5(t_data *td)
{
	int	i;

	find_min_max(td->a->lst, &td->f_hold, &td->s_hold);
	i = ind_element(td->a->lst, td->a->len, td->f_hold);
	if (ft_abs(ind_element(td->a->lst, td->a->len, td->f_hold))
		> ft_abs(ind_element(td->a->lst, td->a->len, td->s_hold)))
		i = ind_element(td->a->lst, td->a->len, td->s_hold);
	asc_a_r_or_rr(td, i, ra, rra);
	if (td->a->lst->ind == td->s_hold && !ascending_sort(td->a->lst->next))
		ra(td, 0);
	else if (ascending_sort(td->a->lst))
	{
		pb(td);
		if (td->f_hold == td->b->lst->ind)
			i = ind_element(td->a->lst, td->a->len, td->s_hold);
		else
			i = ind_element(td->a->lst, td->a->len, td->f_hold);
		asc_a_r_or_rr(td, i, ra, rra);
		if (ascending_sort(td->a->lst))
		{
			pb(td);
			sorting_3(td);
		}
		// while (td->b->len)
		// {
		// 	pa(td);
		// 	if(ascending_sort(td->a->lst))
		// 		ra(td, 0);
		// }
	}
}

void	sorting_list(t_data *td)
{
	int	i;
	int	inter;

	inter = 0;
	while (!count_element(td, inter))
		inter++;
	find_hold(td, inter, 1);
	find_hold(td, inter, 0);
	i = cmp_hold(td);
	asc_a_r_or_rr(td, i, ra, rra);
	if (ascending_sort(td->a->lst))
	{
		pb(td);
		if (td->a->len == 5)
			sorting_5(td);
	}
}

void	rev_sorting_list(t_data *td)
{
	int		i;

	find_min_max(td->b->lst, &td->f_hold, &td->s_hold);
	i = ind_element(td->b->lst, td->b->len, td->s_hold);
	use_r_or_rr(td, i, rb, rrb);
	find_min_max(td->a->lst, &td->f_hold, &td->s_hold);
	if (td->b->lst->ind < td->f_hold || td->b->lst->ind > td->s_hold)
	{
		i = ind_element(td->a->lst, td->a->len, td->f_hold);
		use_r_or_rr(td, i, ra, rra);
	}
	else
	{
		i = insert_into_a(td);
		use_r_or_rr(td, i, ra, rra);
	}
	pa(td);
	if (!td->b->len)
	{
		find_min_max(td->a->lst, &td->f_hold, &td->s_hold);
		i = ind_element(td->a->lst, td->a->len, td->f_hold);
		use_r_or_rr(td, i, ra, rra);
	}
}
