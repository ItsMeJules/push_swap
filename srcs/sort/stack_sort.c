/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:05:15 by jpeyron           #+#    #+#             */
/*   Updated: 2021/05/31 15:11:44 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_three(t_swap *swap)
{
	int	fi;
	int	se;
	int	th;

	fi = get_val(ft_lstat(swap->a->list, 0), 0)->e;
	se = get_val(ft_lstat(swap->a->list, 1), 0)->e;
	th = get_val(ft_lstat(swap->a->list, 2), 0)->e;
	if (fi < th)
	{
		if (th > se)	
			return (swap_stack(swap, swap->a));
		swap_stack(swap, swap->a);
		rotate_stack(swap, swap->a);
	}
	else
	{
		if (se < th)
			return (rotate_stack(swap, swap->a));
		if (fi > se)
			swap_stack(swap, swap->a);
		return (rev_rotate_stack(swap, swap->a));
	}
	return (1);
}

int	sort_fifteen(t_swap *swap)
{
	while (swap->a->size != 3)
	{
		move_to_first_pos(swap, swap->a, get_smallest(swap->a));
		push_stack(swap, swap->a);
	}
	if (!is_sorted(swap->a->list))
		sort_three(swap);
	while (swap->b->size != 0)
		push_stack(swap, swap->b);
	return (1);
}
