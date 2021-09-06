/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:08 by obelair           #+#    #+#             */
/*   Updated: 2021/09/06 16:49:58 by obelair          ###   ########lyon.fr   */
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
		printf("rra\n");
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
		printf("rrb\n");
}

void	rrr(t_data *td, int rrr)
{
	rra(td, rrr);
	rrb(td, rrr);
	printf("rrr\n");
}
