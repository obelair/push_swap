/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:53:47 by obelair           #+#    #+#             */
/*   Updated: 2021/08/31 02:57:55 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ind_element(t_nbr *stack, int size, int ind)
{
	t_nbr	*cur;
	int		i;

	cur = stack;
	i = 0;
	while (cur->ind != ind)
	{
		i++;
		cur = cur->next;
	}
	if (i > size * 0.5)
		return (i - size);
	return (i);
}

int	insert_into_a(t_data *td)
{
	t_nbr	*cur;
	int		i;
	int		check;

	cur = td->a->lst;
	check = 0;
	i = 0;
	while (cur && cur->next && !check)
	{
		if (cur->ind < td->b->lst->ind && td->b->lst->ind < (cur->next)->ind)
			check = 1;
		i++;
		cur = cur->next;
	}
	if (i <= td->a->len / 2 && check)
		return (i - td->a->len);
	else if (check)
		return (i);
	return (0);
}

int	insert_into_b(t_data *td)
{
	t_nbr	*cur;
	int		i;
	int		check;

	cur = td->b->lst;
	check = 0;
	i = 0;
	while (cur && cur->next && !check)
	{
		if (cur->ind > td->a->lst->ind && td->a->lst->ind > (cur->next)->ind)
			check = 1;
		i++;
		cur = cur->next;
	}
	if (i <= td->b->len / 2 && check)
		return (i - td->b->len);
	else if (check)
		return (i);
	return (0);
}
