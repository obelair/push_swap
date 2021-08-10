/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:51:40 by obelair           #+#    #+#             */
/*   Updated: 2021/08/04 18:23:04 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_element(t_stack **list, void (*del)(void *))
{
	t_stack	*cur;
	t_stack	*tmp;

	cur = *list;
	if (!*list)
		return ;
	while (cur)
	{
		tmp = cur->next;
		del(cur);
		cur = tmp;
	}
	*list = NULL;
}
