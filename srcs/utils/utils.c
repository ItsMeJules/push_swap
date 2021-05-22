/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:36:46 by jpeyron           #+#    #+#             */
/*   Updated: 2021/05/22 14:23:18 by jules            ###   ########.fr       */
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

void	print_stack(t_list *stack)
{
	while (stack)
	{
		ft_putnbr_fd(get_val(stack, 0)->e, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

void	print_op(char *op, char id)
{
	write(1, op, ft_strlen(op));
	write(1, &id, 1);
	write(1, "\n", 1);
}
