/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:59:56 by jpeyron           #+#    #+#             */
/*   Updated: 2021/05/31 18:58:14 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_mediane(t_stack *stack)
{
	t_list	*list;
	int		i;

	list = stack->list;
	i = stack->size / 2;
	while (list)
	{
		i--;
		if (i == 0)
			break ;
		list = list->next;
	}
	return (get_val(list, 0)->e);
}

int	is_sorted(t_list *list)
{
	while (list)
	{
		if (list->next && get_val(list, 0)->e > get_val(list->next, 0)->e)
			return (0);
		list = list->next;
	}
	return (1);
}

int		get_smallest(t_stack *stack)
{
	t_list	*list;
	int		nb;

	nb = get_val(stack->list, 0)->e;
	list = stack->list->next;
	while (list)
	{
		if (get_val(list, 0)->e < nb)
			nb = get_val(list, 0)->e;
		list = list->next;
	}
	return (nb);
}

void	move_to_first_pos(t_swap *swap, t_stack *stack, int number)
{
	int	index;
	int	(*rotate_func)(t_swap *, t_stack *);

	if (get_val(stack->list, 0)->e == number)
		return ;
	index = get_index(stack->list, number);
	rotate_func = rotate_stack;
	if (index > stack->size / 2)
		rotate_func = rev_rotate_stack;
	while (get_val(stack->list, 0)->e != number)
		rotate_func(swap, stack);
}
