/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:42 by obelair           #+#    #+#             */
/*   Updated: 2021/08/30 03:21:28 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *td, int ss)
{
	t_nbr	*tmp;

	if (td->a->len > 1)
	{
		tmp = td->a->list;
		td->a->list = td->a->list->next;
		tmp->next = td->a->list->next;
		td->a->list->next = tmp;
		if (!ss)
		{
			printf("sa\n");
			// print_stack(td);
		}
	}
}

void	sb(t_data *td, int ss)
{
	t_nbr	*tmp;

	if (td->b->len > 1)
	{
		tmp = td->b->list;
		td->b->list = td->b->list->next;
		tmp->next = td->b->list->next;
		td->b->list->next = tmp;
		if (!ss)
		{
			printf("sb\n");
			// print_stack(td);
		}
	}
}

void	ss(t_data *td)
{
	sa(td, 1);
	sb(td, 1);
	printf("ss\n");
	// print_stack(td);
}
