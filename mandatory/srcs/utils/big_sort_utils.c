/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:42:17 by jules             #+#    #+#             */
/*   Updated: 2021/06/04 14:48:54 by jules            ###   ########.fr       */
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

int	index_from(int val1, int val2, int top, t_stack *stack)
{
	int	i;
	int	val;

	if (!top)
	{
		i = stack->size - 1;
		while (i != stack->size)
		{
			val = get_val(ft_lstat(stack->list, i), 0)->e;
			if (val == val1 || val == val2)
				return (stack->size - i - 1);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < stack->size)
		{
			val = get_val(ft_lstat(stack->list, i), 0)->e;
			if (val == val1 || val == val2)
				return (i);
			i++;
		}
	}
	return (0);
}

void	rot_from_index(int idx_beg, int idx_end, t_swap *swap, t_stack *stack)
{
	if (idx_beg <= idx_end)
	{
		while (idx_beg-- > 0)
			rotate_stack(swap, stack);
	}
	else
	{
		while (idx_end-- >= 0)
			rev_rotate_stack(swap, stack);
	}
}
