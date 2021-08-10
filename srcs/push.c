/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:50 by obelair           #+#    #+#             */
/*   Updated: 2021/08/07 14:19:40 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *td)
{
	t_stack	*tmp;

	tmp = td->b;
	td->b = td->b->next;
	tmp->next = NULL;
	add_element(&td->a, tmp, 0);
	td->len_a = size_element(td->a);
	td->len_b = size_element(td->b);
	printf("pa\n");
}

void	pb(t_data *td)
{
	t_stack	*tmp;

	tmp = td->a;
	td->a = td->a->next;
	tmp->next = NULL;
	add_element(&td->b, tmp, 0);
	td->len_a = size_element(td->a);
	td->len_b = size_element(td->b);
	printf("pb\n");
}