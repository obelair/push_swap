/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:30:00 by obelair           #+#    #+#             */
/*   Updated: 2021/09/04 22:49:28 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	end_prog(t_data *td)
{
	clear_element(&td->a->lst, free);
	clear_element(&td->b->lst, free);
	clear_instr(&td->instr, free);
	ft_lstclear(&td->list, free);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **ag)
{
	t_data	td;

	parsing_arg(&td, ac, ag);
	if (true_ascending_sort(td.a->lst))
	{
		init_chunk(&td);
		if (td.a->len == 3)
			sorting_3(&td);
		else if (td.a->len == 5)
		{
			sorting_5(&td);
			while (td.b->len)
			{
				pa(&td);
				if(ascending_sort(td.a->lst))
					ra(&td, 0);
			}
		}
		else if (td.a->len <= 100)
		{
			while (true_ascending_sort(td.a->lst))
				sorting_list(&td);
			while (td.b->len)
				rev_sorting_list(&td);
		}
		else
		{
			while (true_ascending_sort(td.a->lst))
				radix(&td);
		}
	}
	purge_instr(&td.instr);
	instr_print(td.instr);
	return (end_prog(&td));
}
