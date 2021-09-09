/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:39:04 by obelair           #+#    #+#             */
/*   Updated: 2021/09/09 11:08:23 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(int err, char *str)
{
	printf("Error\n");
	if (!err)
		printf("\t--> Not enough argument!\n");
	else if (err == 1)
		printf("\t--> %s is not a number!\n", str);
	else if (err == 2)
		printf("\t--> '%s' is already existing!\n", str);
	else if (err == 3)
		printf("\t--> Cannot allocate memory!\n");
	else if (err == 4)
		printf("\t--> %s is not an int!\n", str);
	else if (err == 5)
		printf("\t--> '%s' is not an instruction!\n", str);
}

void	ft_exit(t_data *td, int err, char *str)
{
	write_error(err, str);
	clear_element(&td->a->lst, free);
	clear_element(&td->b->lst, free);
	ft_lstclear(&td->list, free);
	exit(EXIT_FAILURE);
}
