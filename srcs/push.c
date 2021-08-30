/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:50 by obelair           #+#    #+#             */
/*   Updated: 2021/08/30 03:19:01 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *td)
{
	t_nbr	*tmp;

	tmp = td->b->list;
	td->b->list = td->b->list->next;
	tmp->next = NULL;
	add_element(&td->a->list, tmp, 0);
	td->a->len = size_element(td->a->list);
	td->b->len = size_element(td->b->list);
	printf("pa\n");
	// print_stack(td);
}

void	pb(t_data *td)
{
	t_nbr	*tmp;

	tmp = td->a->list;
	td->a->list = td->a->list->next;
	tmp->next = NULL;
	add_element(&td->b->list, tmp, 0);
	td->a->len = size_element(td->a->list);
	td->b->len = size_element(td->b->list);
	printf("pb\n");
	// print_stack(td);
}
