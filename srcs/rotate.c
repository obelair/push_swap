/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:25 by obelair           #+#    #+#             */
/*   Updated: 2021/09/09 13:41:32 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *td, int rr, int print)
{
	t_nbr	*tmp;

	if (td->a->len > 1)
	{
		tmp = td->a->lst;
		td->a->lst = td->a->lst->next;
		tmp->next = NULL;
		add_element(&td->a->lst, tmp, 1);
		if (print && !rr)
			printf("ra\n");
	}
}

void	rb(t_data *td, int rr, int print)
{
	t_nbr	*tmp;

	if (td->b->len > 1)
	{
		tmp = td->b->lst;
		td->b->lst = td->b->lst->next;
		tmp->next = NULL;
		add_element(&td->b->lst, tmp, 1);
		if (print && !rr)
			printf("rb\n");
	}
}

void	rr(t_data *td, int rr, int print)
{
	ra(td, rr, print);
	rb(td, rr, print);
	if (print)
		printf("rr\n");
}
