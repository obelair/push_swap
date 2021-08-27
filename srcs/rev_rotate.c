/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:08 by obelair           #+#    #+#             */
/*   Updated: 2021/08/27 17:35:10 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *td, int rrr)
{
	t_stack	*tmp;
	t_stack	*cur;

	tmp = last_element(td->a);
	cur = td->a;
	while (cur->next != tmp)
		cur = cur->next;
	cur->next = NULL;
	add_element(&td->a, tmp, 0);
	if (!rrr)
	{
		printf("rra\n");
		// print_stack(td);
	}
}

void	rrb(t_data *td, int rrr)
{
	t_stack	*tmp;
	t_stack	*cur;

	tmp = last_element(td->b);
	cur = td->b;
	while (cur->next != tmp)
		cur = cur->next;
	cur->next = NULL;
	add_element(&td->b, tmp, 0);
	if (!rrr)
	{
		printf("rrb\n");
		// print_stack(td);
	}
}

void	rrr(t_data *td)
{
	rra(td, 1);
	rrb(td, 1);
	printf("rrr\n");
	// print_stack(td);
}
