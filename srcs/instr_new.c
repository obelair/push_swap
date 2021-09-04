/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:10:20 by obelair           #+#    #+#             */
/*   Updated: 2021/09/04 20:43:50 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instr	*new_instr(char *instr)
{
	t_instr	*new;

	new = malloc(sizeof(t_instr));
	if (!new)
		return (NULL);
	new->op = instr;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}
