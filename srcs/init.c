/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:54:31 by obelair           #+#    #+#             */
/*   Updated: 2021/09/01 12:29:14 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_data *td, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (add_element(&td->a->lst, new_element(td->nb[i], td->ind[i]), 1))
			ft_exit(td, 3, "");
		i++;
	}
	td->a->len = size_element(td->a->lst);
}

void	init_data(t_data *td, int ac)
{
	td->list = ft_lstnew(NULL);
	td->a = ft_calloc(1, sizeof(t_stack));
	if (ft_lstadd_void(&td->list, td->a, 0))
		ft_exit(td, 3, NULL);
	td->b = ft_calloc(1, sizeof(t_stack));
	if (ft_lstadd_void(&td->list, td->b, 0))
		ft_exit(td, 3, NULL);
	td->ind_chunk = NULL;
	td->nb = ft_calloc(ac - 1, sizeof(int));
	if (ft_lstadd_void(&td->list, td->nb, 0))
		ft_exit(td, 3, NULL);
	td->ind = ft_calloc(ac - 1, sizeof(int));
	if (ft_lstadd_void(&td->list, td->ind, 0))
		ft_exit(td, 3, NULL);
	td->bit = 0;
	td->max_bit = 0;
}
