/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:57:10 by jpeyron           #+#    #+#             */
/*   Updated: 2021/05/22 14:23:12 by jules            ###   ########.fr       */
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
	print_op("s", stack->id);
	return (1);
}

int	push_stack(t_swap *swap, t_stack *from_stack)
{
	t_stack	*to_stack;
	t_list	*tmp;

	if (from_stack->size == 0)
		return (0);
	tmp = from_stack->list;
	to_stack = swap->a;
	if (from_stack->id == 'a')
		to_stack = swap->b;
	ft_lstadd_front(&to_stack->list, ft_lstnew(get_val(from_stack->list, 1)));
	from_stack->list = from_stack->list->next;
	ft_lstdelone(tmp, free);
	print_op("p", to_stack->id);
	print_stack(to_stack->list);
	return (1);
}

int	rotate_stack(t_stack *stack)
{
	t_list	*new;

	if (stack->size < 2)
		return (0);
	new = ft_lstnew(get_val(stack->list, 1));
	ft_lstadd_back(&stack->list, new);
	new = stack->list;
	stack->list = stack->list->next;
	ft_lstdelone(new, free);
	print_op("r", stack->id);
	print_stack(stack->list);
	return (1);
}

int	rev_rotate_stack(t_stack *stack)
{
	t_list	*new;
	t_list	*last;
	
	if (stack->size < 2)
		return (0);
	last = ft_lstlast(stack->list);
	new = ft_lstnew(get_val(last, 1));
	ft_lstat(stack->list, stack->size - 1)->next = NULL;
	ft_lstadd_front(&stack->list, new);
	print_op("rr", stack->id);
	print_stack(stack->list);
	return (1);
}
