/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:26:25 by obelair           #+#    #+#             */
/*   Updated: 2021/08/29 19:09:46 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ascending_sort(t_stack *list)
{
	if (!list)
		return (0);
	while (list->next)
	{
		if (list->index > (list->next)->index)
			return (1);
		list = list->next;
	}
	return (0);
}

int	descending_sort(t_stack *list)
{
	if (!list)
		return (0);
	while (list->next)
	{
		if (list->index < (list->next)->index)
			return (1);
		list = list->next;
	}
	return (0);
}

void	sorting_3(t_data *td)
{
	find_max(td->a, &td->first_hold);
	cmp_top_stack(td);
	if (td->a->index == td->first_hold && ascending_sort(td->a))
		ra(td, 0);
	else if (ascending_sort(td->a))
		rra(td, 0);
	cmp_top_stack(td);
}

void	sorting_5(t_data *td)
{
	int	i;

	find_min(td->a, &td->first_hold);
	find_max(td->a, &td->second_hold);
	i = find_rot(td->a, td->len_a, td->first_hold);
	if (ft_abs(find_rot(td->a, td->len_a, td->first_hold)) > ft_abs(find_rot(td->a, td->len_a, td->second_hold)))
		i = find_rot(td->a, td->len_a, td->second_hold);
	if (i > 0 && ascending_sort(td->a))
	{
		while (i > 0 && ascending_sort(td->a))
		{
			ra(td, 0);
			i--;
		}
	}
	else if (i < 0 && ascending_sort(td->a))
	{
		while (i < 0 && ascending_sort(td->a))
		{
			rra(td, 0);
			i++;
		}
	}
	if (ascending_sort(td->a))
	{
		pb(td);
		if (td->first_hold == td->b->index)
			i = find_rot(td->a, td->len_a, td->second_hold);
		else
			i = find_rot(td->a, td->len_a, td->first_hold);
		if (i > 0 && ascending_sort(td->a))
		{
			while (i > 0 && ascending_sort(td->a))
			{
				ra(td, 0);
				i--;
			}
		}
		else if (i < 0 && ascending_sort(td->a))
		{
			while (i < 0 && ascending_sort(td->a))
			{
				rra(td, 0);
				i++;
			}
		}
		if (ascending_sort(td->a))
		{
			pb(td);
			sorting_3(td);
			pa(td);
			ra(td, 0);
		}
		pa(td);
		if (ascending_sort(td->a))
			ra(td, 0);
	}
}

void	sorting_list(t_data *td)
{
	int	i;
	int	inter;

	inter = 0;
	while (!count_element(td, inter))
		inter++;
	find_first(td, inter);
	find_second(td, inter);
	i = cmp_hold(td);
	cmp_top_stack(td);
	if (i > 0 && ascending_sort(td->a))
	{
		while (i > 0 && ascending_sort(td->a))
		{
			ra(td, 0);
			if (td->first_hold != td->a->index && td->second_hold != td->a->index)
				cmp_top_stack(td);
			i--;
		}
	}
	else if (i < 0 && ascending_sort(td->a))
	{
		while (i < 0 && ascending_sort(td->a))
		{
			rra(td, 0);
			if (td->first_hold != td->a->index && td->second_hold != td->a->index)
				cmp_top_stack(td);
			i++;
		}
	}
	if (ascending_sort(td->a))
	{
		pb(td);
		if (td->len_a == 5)
			sorting_5(td);
	}
}

void	rev_sorting_list(t_data *td)
{
	t_stack *cur;
	int		check;
	int		i;

	find_max(td->b, &td->second_hold);
	i = find_rot(td->b, td->len_b, td->second_hold);
	if (i < 0)
	{
		while (i < 0)
		{
			rrb(td, 0);
			i++;
		}
	}
	else if (i > 0)
	{
		while (i > 0)
		{
			rb(td, 0);
			i--;
		}
	}
	find_min(td->a, &td->first_hold);
	find_max(td->a, &td->second_hold);
	cur = td->a;
	check = 0;
	if (td->b->index < td->first_hold || td->b->index > td->second_hold)
	{
		i = find_rot(td->a, td->len_a, td->first_hold);
		if (i < 0)
		{
			while (i < 0)
			{
				rra(td, 0);
				i++;
			}
		}
		else if (i > 0)
		{
			while (i > 0)
			{
				ra(td, 0);
				i--;
			}
		}
	}
	else
	{
		i = 0;
		while (cur->next && cur->index != td->second_hold && !check)
		{
			if (cur->index < td->b->index && td->b->index < (cur->next)->index)
				check = 1;
			i++;
			cur = cur->next;
		}
		if (cur->next && !check)
		{
			i++;
			cur = cur->next;
			while (cur->next && !check)
			{
				if (cur->index < td->b->index && td->b->index < (cur->next)->index)
					check = 1;
				i++;
				cur = cur->next;
			}
		}
		if (i <= td->len_a / 2 && check)
		{
			while (i > 0)
			{
				ra(td, 0);
				i--;
			}
		}
		else if (check)
		{
			i = i - td->len_a;
			while (i < 0)
			{
				rra(td, 0);
				i++;
			}
		}
	}
	pa(td);
	if (!td->len_b)
	{
		find_min(td->a, &td->first_hold);
		i = find_rot(td->a, td->len_a, td->first_hold);
		if (i < 0)
		{
			while (i < 0)
			{
				rra(td, 0);
				i++;
			}
		}
		else if (i > 0)
		{
			while (i > 0)
			{
				ra(td, 0);
				i--;
			}
		}
	}
}
