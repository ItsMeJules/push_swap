/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:36:46 by jpeyron           #+#    #+#             */
/*   Updated: 2021/06/25 15:39:39 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	quit_prgm(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

t_selem	*get_val(t_list *elem, int clone)
{
	t_selem	*selem;

	if (!clone)
		return ((t_selem *)elem->content);
	else
	{
		selem = malloc(sizeof(t_selem));
		selem->e = ((t_selem *)elem->content)->e;
		return (selem);
	}
}

void	print_op(char *op, char id)
{
	write(1, op, ft_strlen(op));
	write(1, &id, 1);
	write(1, "\n", 1);
}

int	get_index(t_list *list, int e)
{
	int	index;

	index = 0;
	while (list)
	{
		if (get_val(list, 0)->e == e)
			return (index);
		index++;
		list = list->next;
	}
	return (index);
}
