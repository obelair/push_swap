/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:50 by obelair           #+#    #+#             */
/*   Updated: 2021/09/09 13:37:44 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *td, int print)
{
	t_nbr	*tmp;

	if (td->b->len)
	{
		tmp = td->b->lst;
		td->b->lst = td->b->lst->next;
		tmp->next = NULL;
		add_element(&td->a->lst, tmp, 0);
		td->a->len = size_element(td->a->lst);
		td->b->len = size_element(td->b->lst);
		if (print)
			printf("pa\n");
	}
}

void	pb(t_data *td, int print)
{
	t_nbr	*tmp;

	if (td->a->len)
	{
		tmp = td->a->lst;
		td->a->lst = td->a->lst->next;
		tmp->next = NULL;
		add_element(&td->b->lst, tmp, 0);
		td->a->len = size_element(td->a->lst);
		td->b->len = size_element(td->b->lst);
		if (print)
			printf("pb\n");
	}
}
