/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:05:15 by jpeyron           #+#    #+#             */
/*   Updated: 2021/05/27 17:34:54 by jpeyron          ###   ########.fr       */
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
