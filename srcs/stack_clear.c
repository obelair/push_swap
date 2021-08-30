/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:51:40 by obelair           #+#    #+#             */
/*   Updated: 2021/08/30 03:40:32 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_element(t_nbr **list, void (*del)(void *))
{
	t_nbr	*cur;
	t_nbr	*tmp;

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
