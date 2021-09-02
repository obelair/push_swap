/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:42:08 by obelair           #+#    #+#             */
/*   Updated: 2021/08/31 17:19:43 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	index_chunk(t_data *td)
{
	int	i;
	int	nb;
	int	rest;

	nb = td->a->len / td->chunk;
	rest = td->a->len % td->chunk;
	td->ind_chunk[0].start = 0;
	td->ind_chunk[0].end = nb - 1;
	if (rest)
	{
		td->ind_chunk[0].end += 1;
		rest--;
	}
	i = 1;
	while (i < td->chunk)
	{
		td->ind_chunk[i].start = td->ind_chunk[i - 1].end + 1;
		td->ind_chunk[i].end = td->ind_chunk[i - 1].end + nb;
		if (rest)
		{
			td->ind_chunk[i].end += 1;
			rest--;
		}
		i++;
	}
}

void	init_chunk(t_data *td)
{
	float	chunk;

	chunk = ft_sqrt(td->a->len) / 2;
	if (chunk - (int)chunk > 0)
		td->chunk = (int)chunk + 1;
	else
		td->chunk = (int)chunk;
	td->ind_chunk = ft_calloc(td->chunk, sizeof(t_chunk));
	if (ft_lstadd_void(&td->list, td->ind_chunk, 0))
		ft_exit(td, 3, "");
	index_chunk(td);
}
