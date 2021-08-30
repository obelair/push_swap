/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:25 by obelair           #+#    #+#             */
/*   Updated: 2021/08/30 15:03:54 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *td, int rr)
{
	t_nbr	*tmp;

	tmp = td->a->list;
	td->a->list = td->a->list->next;
	tmp->next = NULL;
	add_element(&td->a->list, tmp, 1);
	if (!rr)
	{
		printf("ra\n");
		// print_stack(td);
	}
}

void	rb(t_data *td, int rr)
{
	t_nbr	*tmp;

	tmp = td->b->list;
	td->b->list = td->b->list->next;
	tmp->next = NULL;
	add_element(&td->b->list, tmp, 1);
	if (!rr)
	{
		printf("rb\n");
		// print_stack(td);
	}
}

void	rr(t_data *td, int rr)
{
	ra(td, rr);
	rb(td, rr);
	printf("rr\n");
	// print_stack(td);
}
