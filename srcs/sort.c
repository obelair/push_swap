/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:26:25 by obelair           #+#    #+#             */
/*   Updated: 2021/08/30 15:50:02 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ascending_sort(t_nbr *list)
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

int	descending_sort(t_nbr *list)
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
	find_min_max(td->a->list, &td->first_hold, 0);
	cmp_top_stack(td);
	if (td->a->list->index == td->first_hold && ascending_sort(td->a->list))
		ra(td, 0);
	else if (ascending_sort(td->a->list))
		rra(td, 0);
	cmp_top_stack(td);
}

void	sorting_5(t_data *td)
{
	int	i;

	find_min_max(td->a->list, &td->first_hold, 0);
	find_min_max(td->a->list, &td->second_hold, 1);
	i = find_rot(td->a->list, td->a->len, td->first_hold);
	if (ft_abs(find_rot(td->a->list, td->a->len, td->first_hold)) > ft_abs(find_rot(td->a->list, td->a->len, td->second_hold)))
		i = find_rot(td->a->list, td->a->len, td->second_hold);
	if (i > 0 && ascending_sort(td->a->list))
	{
		while (i > 0 && ascending_sort(td->a->list))
		{
			ra(td, 0);
			i--;
		}
	}
	else if (i < 0 && ascending_sort(td->a->list))
	{
		while (i < 0 && ascending_sort(td->a->list))
		{
			rra(td, 0);
			i++;
		}
	}
	if (td->a->list->index == td->second_hold && !ascending_sort(td->a->list->next))
		ra(td, 0);
	else if (ascending_sort(td->a->list))
	{
		pb(td);
		if (td->first_hold == td->b->list->index)
			i = find_rot(td->a->list, td->a->len, td->second_hold);
		else
			i = find_rot(td->a->list, td->a->len, td->first_hold);
		if (i > 0 && ascending_sort(td->a->list))
		{
			while (i > 0 && ascending_sort(td->a->list))
			{
				ra(td, 0);
				i--;
			}
		}
		else if (i < 0 && ascending_sort(td->a->list))
		{
			while (i < 0 && ascending_sort(td->a->list))
			{
				rra(td, 0);
				i++;
			}
		}
		if (ascending_sort(td->a->list))
		{
			pb(td);
			sorting_3(td);
			pa(td);
			ra(td, 0);
		}
		pa(td);
		if (ascending_sort(td->a->list))
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
	find_hold(td, inter, 1);
	find_hold(td, inter, 0);
	i = cmp_hold(td);
	cmp_top_stack(td);
	if (i > 0 && ascending_sort(td->a->list))
	{
		while (i > 0 && ascending_sort(td->a->list))
		{
			ra(td, 0);
			if (td->first_hold != td->a->list->index && td->second_hold != td->a->list->index)
				cmp_top_stack(td);
			i--;
		}
	}
	else if (i < 0 && ascending_sort(td->a->list))
	{
		while (i < 0 && ascending_sort(td->a->list))
		{
			rra(td, 0);
			if (td->first_hold != td->a->list->index && td->second_hold != td->a->list->index)
				cmp_top_stack(td);
			i++;
		}
	}
	if (ascending_sort(td->a->list))
	{
		pb(td);
		if (td->a->len == 5)
			sorting_5(td);
	}
}

void	rev_sorting_list(t_data *td)
{
	t_nbr	*cur;
	int		check;
	int		i;

	find_min_max(td->b->list, &td->second_hold, 0);
	i = find_rot(td->b->list, td->b->len, td->second_hold);
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
	find_min_max(td->a->list, &td->first_hold, 1);
	find_min_max(td->a->list, &td->second_hold, 0);
	cur = td->a->list;
	check = 0;
	if (td->b->list->index < td->first_hold || td->b->list->index > td->second_hold)
	{
		i = find_rot(td->a->list, td->a->len, td->first_hold);
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
			if (cur->index < td->b->list->index && td->b->list->index < (cur->next)->index)
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
				if (cur->index < td->b->list->index && td->b->list->index < (cur->next)->index)
					check = 1;
				i++;
				cur = cur->next;
			}
		}
		if (i <= td->a->len / 2 && check)
		{
			while (i > 0)
			{
				ra(td, 0);
				i--;
			}
		}
		else if (check)
		{
			i = i - td->a->len;
			while (i < 0)
			{
				rra(td, 0);
				i++;
			}
		}
	}
	pa(td);
	if (!td->b->len)
	{
		find_min_max(td->a->list, &td->first_hold, 1);
		i = find_rot(td->a->list, td->a->len, td->first_hold);
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
