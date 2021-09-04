/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:50 by obelair           #+#    #+#             */
/*   Updated: 2021/09/04 22:29:41 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *td)
{
	t_nbr	*tmp;

	tmp = td->b->lst;
	td->b->lst = td->b->lst->next;
	tmp->next = NULL;
	add_element(&td->a->lst, tmp, 0);
	td->a->len = size_element(td->a->lst);
	td->b->len = size_element(td->b->lst);
	add_instr(&td->instr, new_instr("pa\n"), 1);
	// printf("pa\n");
	// print_stack(td);
}

void	pb(t_data *td)
{
	t_nbr	*tmp;

	tmp = td->a->lst;
	td->a->lst = td->a->lst->next;
	tmp->next = NULL;
	add_element(&td->b->lst, tmp, 0);
	td->a->len = size_element(td->a->lst);
	td->b->len = size_element(td->b->lst);
	add_instr(&td->instr, new_instr("pb\n"), 1);
	// printf("pb\n");
	// print_stack(td);
}
