/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:40:39 by obelair           #+#    #+#             */
/*   Updated: 2021/09/21 10:19:16 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

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

void	find_hold(t_data *td, int inter, int first);
void	find_min_max(t_nbr *stack, int *min, int *max);
int		nb_into_chunk(t_data *td, int inter);

int		find_ind(t_nbr *stack, int size, int ind);
int		insert_into_a(t_data *td);

void	use_r_or_rr(t_data *td, int i, void (*r)(t_data *, int, int), \
	void (*rr)(t_data *, int, int));
void	asc_a_r_or_rr(t_data *td, int i, void (*r)(t_data *, int, int), \
	void (*rr)(t_data *, int, int));

int		cmp_hold(t_data *td);
void	cmp_top_stack(t_data *td);

void	parsing_arg(t_data *td, int ac, char **av);

void	pb(t_data *td, int print);
void	pa(t_data *td, int print);

void	sa(t_data *td, int ss, int print);
void	sb(t_data *td, int ss, int print);
void	ss(t_data *td, int ss, int print);

void	ra(t_data *td, int rr, int print);
void	rb(t_data *td, int rr, int print);
void	rr(t_data *td, int rr, int print);

void	rra(t_data *td, int rrr, int print);
void	rrb(t_data *td, int rrr, int print);
void	rrr(t_data *td, int rrr, int print);

/* Do not Keep */

void	print_stack(t_data *td);

#endif