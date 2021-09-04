/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:51:20 by obelair           #+#    #+#             */
/*   Updated: 2021/09/04 23:22:59 by obelair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	purge_pa_pb(t_instr *elem, int pa, int pb)
{
	t_instr	*cur;
	int		nb_pa;
	int		nb_pb;

	cur = elem;
	nb_pa = pa;
	nb_pb = pb;
	while (cur->next && pa != pb)
	{
		if (!ft_strcmp(cur->op, "pa\n") && pa != pb)
			nb_pa++;
		else if (!ft_strcmp(cur->op, "pb\n") && pa != pb)
			nb_pb++;
		else
			break ;
		cur = cur->next;
	}
	if (pa == pb)
		return (nb_pa);
	return (0);
}

int	purge_ra_rra(t_instr *elem, int ra, int rra)
{
	t_instr	*cur;
	int		nb_ra;
	int		nb_rra;

	cur = elem;
	nb_ra = ra;
	nb_rra = rra;
	while (cur->next && ra != rra)
	{
		if (!ft_strcmp(cur->op, "ra\n") && ra != rra)
			nb_ra++;
		else if (!ft_strcmp(cur->op, "rra\n") && ra != rra)
			nb_rra++;
		else
			break ;
		cur = cur->next;
	}
	if (ra == rra)
		return (nb_ra);
	return (0);
}

int	purge_rb_rrb(t_instr *elem, int rb, int rrb)
{
	t_instr	*cur;
	int		nb_rb;
	int		nb_rrb;

	cur = elem;
	nb_rb = rb;
	nb_rrb = rrb;
	while (cur->next && rb != rrb)
	{
		if (!ft_strcmp(cur->op, "rb\n") && rb != rrb)
			nb_rb++;
		else if (!ft_strcmp(cur->op, "rrb\n") && rb != rrb)
			nb_rrb++;
		else
			break ;
		cur = cur->next;
	}
	if (rb == rrb)
		return (nb_rb);
	return (0);
}

void	purge_instr(t_instr **list)
{
	int		i;
	t_instr	*tmp;
	t_instr	*cur;

	if (!*list)
		return ;
	cur = *list;
	i = 0;
	while (cur->next)
	{
		if (!ft_strcmp(cur->op, "pb\n"))
			i = purge_pa_pb(cur, 0, 1);
		else if (!ft_strcmp(cur->op, "pa\n"))
			i = purge_pa_pb(cur, 0, 1);
		else if (!ft_strcmp(cur->op, "ra\n"))
			i = purge_pa_pb(cur, 0, 1);
		else if (!ft_strcmp(cur->op, "rra\n"))
			i = purge_pa_pb(cur, 0, 1);
		else if (!ft_strcmp(cur->op, "rb\n"))
			i = purge_pa_pb(cur, 0, 1);
		else if (!ft_strcmp(cur->op, "rrb\n"))
			i = purge_pa_pb(cur, 0, 1);
		while(i)
		{
			tmp = cur->next;
			del_one(cur, free);
			cur = tmp;
			i--;
		}
		cur = cur->next;
	}
}
