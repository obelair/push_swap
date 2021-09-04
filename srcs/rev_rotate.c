/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:08 by obelair           #+#    #+#             */
/*   Updated: 2021/09/04 22:29:41 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *td, int rrr)
{
	t_nbr	*tmp;
	t_nbr	*cur;

	tmp = last_element(td->a->lst);
	cur = td->a->lst;
	while (cur->next != tmp)
		cur = cur->next;
	cur->next = NULL;
	add_element(&td->a->lst, tmp, 0);
	if (!rrr)
	{
		add_instr(&td->instr, new_instr("rra\n"), 1);
		// printf("rra\n");
		// print_stack(td);
	}
}

void	rrb(t_data *td, int rrr)
{
	t_nbr	*tmp;
	t_nbr	*cur;

	tmp = last_element(td->b->lst);
	cur = td->b->lst;
	while (cur->next != tmp)
		cur = cur->next;
	cur->next = NULL;
	add_element(&td->b->lst, tmp, 0);
	if (!rrr)
	{
		add_instr(&td->instr, new_instr("rrb\n"), 1);
		// printf("rrb\n");
		// print_stack(td);
	}
}

void	rrr(t_data *td, int rrr)
{
	rra(td, rrr);
	rrb(td, rrr);
	add_instr(&td->instr, new_instr("rrr\n"), 1);
	// printf("rrr\n");
	// print_stack(td);
}
