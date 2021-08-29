/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 06:10:42 by obelair           #+#    #+#             */
/*   Updated: 2021/08/28 19:17:43 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_data *td)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	int		i;

	i = 0;
	printf("================================================================================================\n");
	printf("\tNb\t|\tInd\t|\tA.v\t|\tA.i\t|\tB.v\t|\tB.i\n");
	printf("================================================================================================\n");
	cur_a = td->a;
	cur_b = td->b;
	while (i < (td->len_a + td->len_b))
	{
		printf("\t%d\t|\t%d", td->nb[i], td->ind[i]);
		if (cur_a && cur_b)
		{
			printf("\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", cur_a->value, cur_a->index, cur_b->value, cur_b->index);
			cur_a = cur_a->next;
			cur_b = cur_b->next;
		}
		else if (cur_a)
		{
			printf("\t|\t%d\t|\t%d\t|\t-\t|\t-\n", cur_a->value, cur_a->index);
			cur_a = cur_a->next;
		}
		else if (cur_b)
		{
			printf("\t|\t-\t|\t-\t|\t%d\t|\t%d\n", cur_b->value, cur_b->index);
			cur_b = cur_b->next;
		}
		else
			printf("\t|\t-\t|\t-\t|\t-\t|\t-\n");
		i++;
	}
}