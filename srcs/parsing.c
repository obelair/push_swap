/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:47:12 by obelair           #+#    #+#             */
/*   Updated: 2021/09/21 10:15:23 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_ind(t_data *td, int size)
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

void	parsing_arg(t_data *td, int ac, char **av)
{
	int	i;

	init_data(td, ac);
	i = 1;
	while (av[i])
	{
		if (ft_strisdigit(av[i]))
			ft_exit(td, 1, av[i]);
		td->nb[i - 1] = ft_atoi(av[i]);
		if ((int)ft_strlen(av[i]) != ft_intblen(td->nb[i - 1], 10)
			|| !ft_strcmp(av[i], "-"))
			ft_exit(td, 4, av[i]);
		if (ft_nbishere(td->nb, td->nb[i - 1], i - 1))
			ft_exit(td, 2, av[i]);
		set_ind(td, i - 1);
		i++;
	}
	init_stack(td, ac - 1);
}
