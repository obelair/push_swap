/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:31:13 by obelair           #+#    #+#             */
/*   Updated: 2021/08/10 14:40:00 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}	t_stack;

t_stack	*new_element(int value, int index);
t_stack	*last_element(t_stack *list);
int		add_element(t_stack **list, t_stack *new, int back);
void	clear_element(t_stack **list, void (*del)(void *));
int		size_element(t_stack *list);

typedef struct s_chunk
{
	int	start;
	int	end;
}	t_chunk;

typedef struct s_data
{
	int		*nb;
	int		*ind;
	int		chunk;
	t_chunk	*ind_chunk;
	int		first_hold;
	int		second_hold;
	int		len_a;
	int		len_b;
	t_stack	*a;
	t_stack	*b;
	t_list	*list;
}	t_data;

void	ft_exit(t_data *td, int err, char *str);

void	init_chunk(t_data *td);
void	init_data(t_data *td, int ac);
void	init_stack(t_data *td, int size);

int		ascending_sort(t_stack *list);
int		descending_sort(t_stack *list);
void	sorting_list(t_data *td);

void	find_first(t_data *td, int inter);
void	find_second(t_data *td, int inter);

int		cmp_hold(t_data *td);
void	cmp_top_stack(t_data *td);

void	parsing_arg(t_data *td, int ac, char **ag);

void	pb(t_data *td);
void	pa(t_data *td);

void	sa(t_data *td, int ss);
void	sb(t_data *td, int ss);
void	ss(t_data *td);

void	ra(t_data *td, int rr);
void	rb(t_data *td, int rr);
void	rr(t_data *td);

void	rra(t_data *td, int rrr);
void	rrb(t_data *td, int rrr);
void	rrr(t_data *td);

#endif