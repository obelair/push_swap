/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:42 by obelair           #+#    #+#             */
/*   Updated: 2021/08/29 19:04:41 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *td, int ss)
{
	t_stack	*tmp;

	if (td->len_a > 1)
	{
		tmp = td->a;
		td->a = td->a->next;
		tmp->next = td->a->next;
		td->a->next = tmp;
		if (!ss)
		{
			printf("sa\n");
			// print_stack(td);
		}
	}
}

void	sb(t_data *td, int ss)
{
	t_stack	*tmp;

	if (td->len_b > 1)
	{
		tmp = td->b;
		td->b = td->b->next;
		tmp->next = td->b->next;
		td->b->next = tmp;
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
