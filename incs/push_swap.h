/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:31:13 by obelair           #+#    #+#             */
/*   Updated: 2021/08/30 15:41:42 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

typedef struct s_nbr
{
	int				index;
	int				value;
	struct s_nbr	*next;
}	t_nbr;

t_nbr	*new_element(int value, int index);
t_nbr	*last_element(t_nbr *list);
int		add_element(t_nbr **list, t_nbr *new, int back);
void	clear_element(t_nbr **list, void (*del)(void *));
int		size_element(t_nbr *list);

typedef struct s_stack
{
	int		len;
	t_nbr	*list;
}	t_stack;

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
	t_stack	*a;
	t_stack	*b;
	t_list	*list;
}	t_data;

void	ft_exit(t_data *td, int err, char *str);

void	init_chunk(t_data *td);
void	init_data(t_data *td, int ac);
void	init_stack(t_data *td, int size);

int		ascending_sort(t_nbr *list);
int		descending_sort(t_nbr *list);
void	sorting_3(t_data *td);
void	sorting_5(t_data *td);
void	sorting_list(t_data *td);
void	rev_sorting_list(t_data *td);

void	find_hold(t_data *td, int inter, int first);
void	find_min_max(t_nbr *stack, int *ind, int min);
int		find_rot(t_nbr *stack, int size, int ind);
int		count_element(t_data *td, int inter);

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
void	rr(t_data *td, int rr);

void	rra(t_data *td, int rrr);
void	rrb(t_data *td, int rrr);
void	rrr(t_data *td, int rrr);

/* Don't keep */

void	print_stack(t_data *td);

#endif
