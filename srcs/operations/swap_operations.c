/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:57:10 by jpeyron           #+#    #+#             */
/*   Updated: 2021/05/21 16:55:22 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	swap_stack(t_stack *stack)
{
	void	*tmp;

	if (stack->size < 2)
		return (0);
	tmp = stack->list->next->content;
	stack->list->next->content = stack->list->content;
	stack->list->content = tmp;
	write(1, "s", 1);
	write(1, &stack->id, 1);
	write(1, "\n", 1);
	return (1);
}

int	push_stack(t_swap *swap, t_stack *from_stack)
{
	t_stack	*to_stack;
	t_list	*next;

	if (from_stack->size == 0)
		return (0);
	to_stack = swap->b;
	if (from_stack->id == 'a')
		to_stack = swap->a;
	if (to_stack->list->next)
		next = to_stack->list->next;
	ft_lstadd_front(&to_stack->list, from_stack->list);
	from_stack->list = from_stack->list->next;
		
	write(1, "s", 1);
	write(1, &from_stack->id, 1);
	write(1, "\n", 1);
	print_stack(to_stack->list);
	return (1);
}
