/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:25 by obelair           #+#    #+#             */
/*   Updated: 2021/09/01 12:35:17 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *td, int rr)
{
	t_nbr	*tmp;

	tmp = td->a->lst;
	td->a->lst = td->a->lst->next;
	tmp->next = NULL;
	add_element(&td->a->lst, tmp, 1);
	if (!rr)
	{
		printf("ra\n");
		// print_stack(td);
	}
}

void	rb(t_data *td, int rr)
{
	t_nbr	*tmp;

	tmp = td->b->lst;
	td->b->lst = td->b->lst->next;
	tmp->next = NULL;
	add_element(&td->b->lst, tmp, 1);
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
