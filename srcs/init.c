/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:54:31 by obelair           #+#    #+#             */
/*   Updated: 2021/08/08 20:13:20 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_data *td, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (add_element(&td->a, new_element(td->nb[i], td->ind[i]), 1))
			ft_exit(td, 3, "");
		i++;
	}
	td->len_a = size_element(td->a);
}

void	init_data(t_data *td, int ac)
{
	td->list = ft_lstnew(NULL);
	td->a = NULL;
	td->b = NULL;
	td->ind_chunk = NULL;
	td->len_a = 0;
	td->len_b = 0;
	td->nb = ft_calloc(ac - 1, sizeof(int));
	if (ft_lstadd_void(&td->list, td->nb, 0))
		ft_exit(td, 3, NULL);
	td->ind = ft_calloc(ac - 1, sizeof(int));
	if (ft_lstadd_void(&td->list, td->ind, 0))
		ft_exit(td, 3, NULL);
}
