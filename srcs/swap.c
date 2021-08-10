/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:42 by obelair           #+#    #+#             */
/*   Updated: 2021/08/08 10:44:21 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *td, int ss)
{
	t_stack	*tmp;

	tmp = td->a;
	td->a = td->a->next;
	tmp->next = td->a->next;
	td->a->next = tmp;
	if (!ss)
		printf("sa\n");
}

void	sb(t_data *td, int ss)
{
	t_stack	*tmp;

	tmp = td->b;
	td->b = td->b->next;
	tmp->next = td->b->next;
	td->b->next = tmp;
	if (!ss)
		printf("sb\n");
}

void	ss(t_data *td)
{
	sa(td, 1);
	sb(td, 1);
	printf("ss\n");
}
