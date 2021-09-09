/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 09:38:42 by obelair           #+#    #+#             */
/*   Updated: 2021/09/09 11:36:09 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	end_prog(t_data *td)
{
	clear_element(&td->a->lst, free);
	clear_element(&td->b->lst, free);
	ft_lstclear(&td->list, free);
	return (EXIT_SUCCESS);
}

void	execute_operation(t_data *td, char *line)
{
	if (!ft_strcmp(line, "pa"))
		pa(td, 0);
	else if (!ft_strcmp(line, "pb"))
		pb(td, 0);
	else if (!ft_strcmp(line, "ra"))
		ra(td, 0, 0);
	else if (!ft_strcmp(line, "rb"))
		rb(td, 0, 0);
	else if (!ft_strcmp(line, "rr"))
		rr(td, 1, 0);
	else if (!ft_strcmp(line, "rra"))
		rra(td, 0, 0);
	else if (!ft_strcmp(line, "rrb"))
		rrb(td, 0, 0);
	else if (!ft_strcmp(line, "rrr"))
		rrr(td, 1, 0);
	else if (!ft_strcmp(line, "sa"))
		sa(td, 0, 0);
	else if (!ft_strcmp(line, "sb"))
		sb(td, 0, 0);
	else if (!ft_strcmp(line, "ss"))
		ss(td, 1, 0);
	else
		ft_exit(td, 5, line);
}

int	main(int ac, char **av)
{
	t_data	td;
	char	*line;

	parsing_arg(&td, ac, av);
	while (get_next_line(0, &line))
	{
		if (ft_lstadd_void(&td.list, line, 0))
			ft_exit(&td, 3, NULL);
		execute_operation(&td, line);
	}
	if (ascending_sort(td.a->lst) || td.b->len)
		printf("KO\n");
	else
		printf("OK\n");
	return (end_prog(&td));
}
