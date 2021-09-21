/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:53:47 by obelair           #+#    #+#             */
/*   Updated: 2021/09/21 10:16:43 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insert_into_a(t_data *td)
{
	t_nbr	*cur;
	int		i;
	int		check;

	cur = td->a->lst;
	check = 0;
	i = 0;
	while (cur && cur->next && !check)
	{
		if (cur->ind < td->b->lst->ind && td->b->lst->ind < (cur->next)->ind)
			check = 1;
		i++;
		cur = cur->next;
	}
	if (i <= td->a->len / 2 && check)
		return (i - td->a->len);
	else if (check)
		return (i);
	return (0);
}
