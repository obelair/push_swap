/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:30:00 by obelair           #+#    #+#             */
/*   Updated: 2021/08/30 03:32:13 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **ag)
{
	t_data	td;
	// t_stack	*cur_a;
	// t_stack	*cur_b;
	// int		i;

	// i = 0;
	parsing_arg(&td, ac, ag);
	if (ascending_sort(td.a->list))
	{
		init_chunk(&td);
		if (td.a->len == 3)
			sorting_3(&td);
		else if (td.a->len == 5)
			sorting_5(&td);
		else
		{
			while (ascending_sort(td.a->list))
				sorting_list(&td);
			while (td.b->len > 0)
				rev_sorting_list(&td);
		}
		// if (!descending_sort(td.a))
		// {
		// 	while (i < td.len_a - 1)
		// 	{
		// 		// printf("asc_a : %d | adr : %p\n", ascending_sort(td.a), td.a);
		// 		ra(&td, 0);
		// 		i++;
		// 	}
		// 	// printf("asc_a : %d | adr : %p | ind : %d\n", ascending_sort(td.a), td.a, td.a->index);
		// }
	}
	// i = 0;
	// printf("================================================================================================\n");
	// printf("\tNb\t|\tInd\t|\tA.v\t|\tA.i\t|\tB.v\t|\tB.i\n");
	// printf("================================================================================================\n");
	// cur_a = td.a;
	// cur_b = td.b;
	// while (i < td.len_a + td.len_b)
	// {
	// 	printf("\t%d\t|\t%d", td.nb[i], td.ind[i]);
	// 	if (cur_a && cur_b)
	// 	{
	// 		printf("\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", cur_a->value, cur_a->index, cur_b->value, cur_b->index);
	// 		cur_a = cur_a->next;
	// 		cur_b = cur_b->next;
	// 	}
	// 	else if (cur_a)
	// 	{
	// 		printf("\t|\t%d\t|\t%d\t|\t-\t|\t-\n", cur_a->value, cur_a->index);
	// 		cur_a = cur_a->next;
	// 	}
	// 	else if (cur_b)
	// 	{
	// 		printf("\t|\t-\t|\t-\t|\t%d\t|\t%d\n", cur_b->value, cur_b->index);
	// 		cur_b = cur_b->next;
	// 	}
	// 	else
	// 		printf("\t|\t-\t|\t-\t|\t-\t|\t-\n");
	// 	i++;
	// }
	// printf("------------------------------------------------------------------------------------------------\n");
	// printf("\t\t\t\t|\tsize_a\t:\t%d\t|\tsize_b\t:\t%d\n", td.len_a, td.len_b);
	// printf("------------------------------------------------------------------------------------------------\n");
	// printf("nb_chunk : [%d-%d] |", td.ind_chunk[0].start, td.ind_chunk[0].end);
	// i = 1;
	// while (i < td.chunk - 1)
	// {
	// 	printf(" [%d-%d] |", td.ind_chunk[i].start, td.ind_chunk[i].end);
	// 	i++;
	// }
	// printf(" [%d-%d]\n", td.ind_chunk[i].start, td.ind_chunk[i].end);
	// printf("------------------------------------------------------------------------------------------------\n");
	// printf("asc_a : %d | asc_b : %d | desc_a : %d | desc_b : %d\n", ascending_sort(td.a), ascending_sort(td.b), descending_sort(td.a), descending_sort(td.b));
	// printf("------------------------------------------------------------------------------------------------\n");
	// printf("f_hold : %d | s_hold : %d\n", td.first_hold, td.second_hold);
	clear_element(&td.a->list, free);
	clear_element(&td.b->list, free);
	ft_lstclear(&td.list, free);
	return (0);
}
