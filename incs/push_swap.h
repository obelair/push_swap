/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:31:13 by obelair           #+#    #+#             */
/*   Updated: 2021/09/06 17:01:15 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

typedef struct s_nbr
{
	int				ind;
	int				val;
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
	t_nbr	*lst;
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
	int		bit;
	t_chunk	*ind_chunk;
	int		f_hold;
	int		s_hold;
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

void	algo_3(t_data *td);
void	algo_5(t_data *td);
void	algo_chunk_start(t_data *td);
void	algo_chunk_end(t_data *td);

void	find_hold(t_data *td, int inter, int first);
void	find_min_max(t_nbr *stack, int *min, int *max);
int		nb_into_chunk(t_data *td, int inter);

int		find_ind(t_nbr *stack, int size, int ind);
int		insert_into_a(t_data *td);

void	use_r_or_rr(t_data *td, int i, void (*r)(t_data *, int), \
	void (*rr)(t_data *, int));
void	asc_a_r_or_rr(t_data *td, int i, void (*r)(t_data *, int), \
	void (*rr)(t_data *, int));

int		cmp_hold(t_data *td);
void	cmp_top_stack(t_data *td);

void	parsing_arg(t_data *td, int ac, char **ag);

void	radix(t_data *td);

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

#endif
