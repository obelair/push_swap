/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:25 by obelair           #+#    #+#             */
/*   Updated: 2021/08/08 10:44:00 by obelair          ###   ########lyon.fr   */
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
		printf("ra\n");
}

void	rb(t_data *td, int rr)
{
	t_stack	*tmp;

	tmp = td->b;
	td->b = td->a->next;
	tmp->next = NULL;
	add_element(&td->b, tmp, 1);
	if (!rr)
		printf("rb\n");
}

void	rr(t_data *td)
{
	ra(td, 1);
	rb(td, 1);
	printf("rr\n");
}
