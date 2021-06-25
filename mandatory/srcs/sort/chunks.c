/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:31:22 by jules             #+#    #+#             */
/*   Updated: 2021/06/25 15:28:39 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_list	*clone_list(t_list *list)
{
	t_list	*clone;

	clone = NULL;
	while (list)
	{
		ft_lstadd_back(&clone, ft_lstnew(get_val(list, 1)));
		list = list->next;
	}
	return (clone);
}

t_list	*bubble_sort_numbers(t_list *list)
{
	t_list	*origin;
	t_list	*list_iter;

	origin = list;
	while (list)
	{
		list_iter = list->next;
		while (list_iter)
		{
			if (get_val(list, 0)->e > get_val(list_iter, 0)->e)
				ft_swap(&get_val(list_iter, 0)->e, &get_val(list, 0)->e);
			list_iter = list_iter->next;
		}
		list = list->next;
	}
	return (origin);
}

t_chunk	*create_chunks(t_swap *swap, int chunk_size)
{
	t_chunk	*chunks;
	t_list	*sorted;
	int		i;

	sorted = bubble_sort_numbers(clone_list(swap->a->list));
	swap->chunks_nb = swap->a->size / chunk_size;
	if (swap->a->size % chunk_size != 0)
		swap->chunks_nb++;
	chunks = malloc(swap->chunks_nb * sizeof(t_chunk));
	if (!chunks)
		return (NULL);
	i = -1;
	while (++i < swap->chunks_nb)
	{
		chunks[i].size = chunk_size;
		if (i == swap->chunks_nb - 1)
			chunks[i].size = swap->a->size % chunk_size;
		chunks[i].min = get_val(ft_lstat(sorted, i * chunk_size), 0)->e;
		chunks[i].med = get_val(ft_lstat(sorted, i * chunk_size
					+ (chunks[i].size / 2)), 0)->e;
		chunks[i].max = get_val(ft_lstat(sorted, i * chunk_size
					+ chunks[i].size - 1), 0)->e;
	}
	ft_lstclear(&sorted, free);
	return (chunks);
}
