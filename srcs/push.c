/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:50 by obelair           #+#    #+#             */
/*   Updated: 2021/09/06 16:49:35 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *td)
{
	t_nbr	*tmp;

	tmp = td->b->lst;
	td->b->lst = td->b->lst->next;
	tmp->next = NULL;
	add_element(&td->a->lst, tmp, 0);
	td->a->len = size_element(td->a->lst);
	td->b->len = size_element(td->b->lst);
	printf("pa\n");
}

void	pb(t_data *td)
{
	t_nbr	*tmp;

	tmp = td->a->lst;
	td->a->lst = td->a->lst->next;
	tmp->next = NULL;
	add_element(&td->b->lst, tmp, 0);
	td->a->len = size_element(td->a->lst);
	td->b->len = size_element(td->b->lst);
	printf("pb\n");
}
