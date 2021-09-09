/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbishere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 23:15:18 by obelair           #+#    #+#             */
/*   Updated: 2021/09/09 13:07:39 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbishere(int *tab, int nb, int size)
{
	int	i;

	i = 0;
	while (i < size && tab[i] != nb)
		i++;
	if (i < size && tab[i] == nb)
		return (1);
	return (0);
}
