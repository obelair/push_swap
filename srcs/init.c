/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:54:31 by obelair           #+#    #+#             */
/*   Updated: 2021/07/31 22:27:16 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *td, int ac)
{
	td->list = ft_lstnew(NULL);
	td->a.nb_el = ac - 1;
	td->b.nb_el = 0;
	td->a.stack = ft_calloc(ac - 1, sizeof(int));
	if (ft_lstadd_void(&td->list, td->a.stack, 0))
		ft_exit(&td->list, 3, NULL);
	td->b.stack = ft_calloc(ac - 1, sizeof(int));
	if (ft_lstadd_void(&td->list, td->b.stack, 0))
		ft_exit(&td->list, 3, NULL);
}
