/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:36:46 by jpeyron           #+#    #+#             */
/*   Updated: 2021/05/21 16:40:59 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	quit_prgm()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

t_selem	*get_val(t_list *elem)
{
	return ((t_selem *)elem->content);
}

void	print_stack(t_list *stack)
{
	while (stack)
	{
		ft_putnbr_fd(get_val(stack)->e, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}
