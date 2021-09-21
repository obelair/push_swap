/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:30:00 by obelair           #+#    #+#             */
/*   Updated: 2021/09/21 10:16:29 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	end_prog(t_data *td)
{
	clear_element(&td->a->lst, free);
	clear_element(&td->b->lst, free);
	ft_lstclear(&td->list, free);
	return (EXIT_SUCCESS);
}

void	low_sort(t_data *td)
{
	if (td->a->len == 3)
		algo_3(td);
	else if (td->a->len == 5)
	{
		algo_5(td);
		while (td->b->len)
		{
			pa(td, 1);
			if (ascending_sort(td->a->lst))
				ra(td, 0, 1);
		}
	}
	else if (td->a->len <= 100)
	{
		while (ascending_sort(td->a->lst))
			algo_chunk_start(td);
		while (td->b->len)
			algo_chunk_end(td);
	}
}

int	main(int ac, char **av)
{
	t_data	td;

	parsing_arg(&td, ac, av);
	if (ascending_sort(td.a->lst))
	{
		init_chunk(&td);
		if (td.a->len <= 100)
			low_sort(&td);
		else
			while (ascending_sort(td.a->lst))
				radix(&td);
	}
	return (end_prog(&td));
}
