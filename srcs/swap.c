/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:42 by obelair           #+#    #+#             */
/*   Updated: 2021/09/21 10:17:56 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *td, int ss, int print)
{
	t_nbr	*tmp;

	if (td->a->len > 1)
	{
		tmp = td->a->lst;
		td->a->lst = td->a->lst->next;
		tmp->next = td->a->lst->next;
		td->a->lst->next = tmp;
		if (print && !ss)
			printf("sa\n");
	}
}

void	sb(t_data *td, int ss, int print)
{
	t_nbr	*tmp;

	if (td->b->len > 1)
	{
		tmp = td->b->lst;
		td->b->lst = td->b->lst->next;
		tmp->next = td->b->lst->next;
		td->b->lst->next = tmp;
		if (print && !ss)
			printf("sb\n");
	}
}

void	ss(t_data *td, int ss, int print)
{
	sa(td, ss, print);
	sb(td, ss, print);
	if (print)
		printf("ss\n");
}
