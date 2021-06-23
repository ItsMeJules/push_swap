/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:36:46 by jpeyron           #+#    #+#             */
/*   Updated: 2021/06/04 14:49:54 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	quit_prgm()
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

void	print_stacks(t_swap *swap)
{
	long	i;

	i = swap->a->size;
	if (swap->b->size > i)
		i = swap->b->size;
	while (i--)
	{
		if (i < swap->a->size)
			ft_putnbr_fd(get_val(ft_lstat(swap->a->list, swap->a->size - 1 - i),
				0)->e, 1);
		ft_putstr_fd("\t | ", 1);
		if (i < swap->b->size)
			ft_putnbr_fd(get_val(ft_lstat(swap->b->list, swap->b->size - 1 - i),
				0)->e, 1);
		ft_putchar_fd('\n', 1);
	}
	ft_putchar_fd('\n', 1);
}

void	print_op(char *op, char id)
{
	write(1, op, ft_strlen(op));
	write(1, &id, 1);
	write(1, "\n", 1);
}

int		get_index(t_list *list, int e)
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
