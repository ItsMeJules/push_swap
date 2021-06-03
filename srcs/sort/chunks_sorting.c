/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:03:17 by jules             #+#    #+#             */
/*   Updated: 2021/06/03 17:30:40 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_chunk_vals(t_swap *swap, t_stack *a, t_stack *b, t_chunk chunk)
{
	int		top;
	int		bot;
	(void)b;

	while (b->size < chunk.size)
	{
		top = index_of_val(chunk.min, chunk.max, 1, a);
		bot = index_of_val(chunk.min, chunk.max, 0, a);
		if (top >= a->size - bot)
			move_to_first_pos(swap, a, get_val(ft_lstat(a->list, bot), 0)->e);
		else
			move_to_first_pos(swap, a, get_val(ft_lstat(a->list, top), 0)->e);
		push_stack(swap, a);
		if (get_val(b->list, 0)->e > chunk.med)
			rotate_stack(swap, b);
	}
}

void	push_back_a(t_swap *swap)
{
//	int	min;
//	int	max;

	while (swap->b->size != 0)
	{

	}
}
