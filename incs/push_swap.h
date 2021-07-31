/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:31:13 by obelair           #+#    #+#             */
/*   Updated: 2021/07/31 22:07:11 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

typedef struct s_stack
{
	int	nb_el;
	int	*stack;
}	t_stack;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	t_list	*list;
}	t_data;

void	ft_exit(t_list **list, int err, char *str);

void	init_data(t_data *td, int ac);

void	parsing_arg(t_data *td, int ac, char **ag);



#endif