/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:25 by obelair           #+#    #+#             */
/*   Updated: 2021/08/29 19:04:41 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *td, int rr)
{
	t_stack	*tmp;

	tmp = td->a;
	td->a = td->a->next;
	tmp->next = NULL;
	add_element(&td->a, tmp, 1);
	if (!rr)
	{
		printf("ra\n");
		// print_stack(td);
	}
}

void	rb(t_data *td, int rr)
{
	t_stack	*tmp;

	tmp = td->b;
	td->b = td->b->next;
	tmp->next = NULL;
	add_element(&td->b, tmp, 1);
	if (!rr)
	{
		printf("rb\n");
		// print_stack(td);
	}
}

void	rr(t_data *td)
{
	ra(td, 1);
	rb(td, 1);
	printf("rr\n");
	// print_stack(td);
}
