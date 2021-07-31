/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:47:12 by obelair           #+#    #+#             */
/*   Updated: 2021/08/01 00:08:58 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing_arg(t_data *td, int ac, char **ag)
{
	int	i;

	init_data(td, ac);
	i = 1;
	while (ag[i])
	{
		if (ft_strisdigit(ag[i]))
			ft_exit(&td->list, 1, ag[i]);
		td->a.stack[i - 1] = ft_atoi(ag[i]);
		if (ft_nbishere(td->a.stack, td->a.stack[i - 1], i - 1))
			ft_exit(&td->list, 2, ag[i]);
		i++;
	}
}
