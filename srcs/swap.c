/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:42 by obelair           #+#    #+#             */
/*   Updated: 2021/09/04 22:29:41 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *td, int ss)
{
	t_nbr	*tmp;

	if (td->a->len > 1)
	{
		tmp = td->a->lst;
		td->a->lst = td->a->lst->next;
		tmp->next = td->a->lst->next;
		td->a->lst->next = tmp;
		if (!ss)
		{
			add_instr(&td->instr, new_instr("sa\n"), 1);
			// printf("sa\n");
			// print_stack(td);
		}
	}
}

void	sb(t_data *td, int ss)
{
	t_nbr	*tmp;

	if (td->b->len > 1)
	{
		tmp = td->b->lst;
		td->b->lst = td->b->lst->next;
		tmp->next = td->b->lst->next;
		td->b->lst->next = tmp;
		if (!ss)
		{
			add_instr(&td->instr, new_instr("sb\n"), 1);
			// printf("sb\n");
			// print_stack(td);
		}
	}
}

void	ss(t_data *td)
{
	sa(td, 1);
	sb(td, 1);
	add_instr(&td->instr, new_instr("ss\n"), 1);
	// printf("ss\n");
	// print_stack(td);
}
