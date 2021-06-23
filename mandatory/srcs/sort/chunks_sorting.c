/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:03:17 by jules             #+#    #+#             */
/*   Updated: 2021/06/04 17:17:50 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_chunk_vals(t_swap *swap, t_stack *a, t_stack *b, t_chunk chunk)
{
	int		top;
	int		bot;

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

void	push_small_big_a(t_swap *swap)
{
	int	idx_beg;
	int	idx_end;
	int	sml;
	int	big;
	int	rot_a;

	while (swap->b->size != 0)
	{
		rot_a = 0;
		sml = get_smallest(swap->b);
		big = get_biggest(swap->b);
		idx_beg = index_from(sml, big, 1, swap->b);
		idx_end = index_from(sml, big, 0, swap->b);
		if (idx_beg <= idx_end
				&& get_val(ft_lstat(swap->b->list, idx_beg), 0)->e == sml)
			rot_a = 1;
		else if (idx_beg > idx_end && get_val(ft_lstat(
				swap->b->list, swap->b->size - idx_end - 1), 0)->e == sml)
			rot_a = 1;
		rot_from_index(idx_beg, idx_end, swap, swap->b);
		push_stack(swap, swap->b);
		if (rot_a)
			rotate_stack(swap, swap->a);
	}
}

void	small_a_sort(t_swap *swap, t_chunk *chunk)
{
	t_list	*list;

	if (chunk == NULL)
		return ;
	list = swap->a->list;
	while (list)
	{
		if (get_val(list, 0)->e == chunk->max)
		{
			move_to_first_pos(swap, swap->a, chunk->max);
			rotate_stack(swap, swap->a);
			return ;
		}
		list = list->next;
	}
}
