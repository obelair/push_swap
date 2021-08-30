/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:39:04 by obelair           #+#    #+#             */
/*   Updated: 2021/08/30 14:34:24 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(int err, char *str)
{
	if (!err)
		printf("Not enough argument!\n");
	else if (err == 1)
		printf("%s is not a number!\n", str);
	else if (err == 2)
		printf("'%s' is already existing!\n", str);
	else if (err == 3)
		printf("Cannot allocate memory!\n");
	else if (err == 4)
		printf("%s is not an int!\n", str);
}

void	ft_exit(t_data *td, int err, char *str)
{
	write_error(err, str);
	clear_element(&td->a->list, free);
	clear_element(&td->b->list, free);
	ft_lstclear(&td->list, free);
	exit(EXIT_FAILURE);
}
