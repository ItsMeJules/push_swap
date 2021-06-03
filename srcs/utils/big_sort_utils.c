/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:42:17 by jules             #+#    #+#             */
/*   Updated: 2021/06/03 17:30:38 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_between(int min, int nb, int max)
{
	return (nb >= min && nb <= max);
}

int	index_of_val(int min, int max, int top, t_stack *stack)
{
	int		i;

	if (!top)
	{
		i = stack->size - 1;
		while (!is_between(min, get_val(ft_lstat(stack->list, i), 0)->e, max))
			i--;
	}
	else
	{
		i = 0;
		while (!is_between(min, get_val(ft_lstat(stack->list, i), 0)->e, max))
			i++;
	}
	return (i);
}
