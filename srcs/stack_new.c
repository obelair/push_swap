/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:14:20 by obelair           #+#    #+#             */
/*   Updated: 2021/08/30 19:06:27 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nbr	*new_element(int value, int index)
{
	t_nbr	*new;

	new = malloc(sizeof(t_nbr));
	if (!new)
		return (NULL);
	new->val = value;
	new->ind = index;
	new->next = NULL;
	return (new);
}
