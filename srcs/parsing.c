/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:47:12 by obelair           #+#    #+#             */
/*   Updated: 2021/08/03 18:50:14 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_ind(t_data *td, int size)
{
	int	i;

	i = 0;
	td->ind[size] = size;
	while (i < size)
	{
		if (td->nb[i] > td->nb[size])
			td->ind[size]--;
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (td->ind[i] >= td->ind[size])
			td->ind[i] += 1;
		i++;
	}
}

void	parsing_arg(t_data *td, int ac, char **ag)
{
	int	i;

	init_data(td, ac);
	i = 1;
	while (ag[i])
	{
		if (ft_strisdigit(ag[i]))
			ft_exit(td, 1, ag[i]);
		td->nb[i - 1] = ft_atoi(ag[i]);
		if ((int)ft_strlen(ag[i]) != ft_intblen(td->nb[i - 1], 10))
			ft_exit(td, 4, ag[i]);
		if (ft_nbishere(td->nb, td->nb[i - 1], i - 1))
			ft_exit(td, 2, ag[i]);
		find_ind(td, i - 1);
		i++;
	}
	init_stack(td, ac - 1);
}
