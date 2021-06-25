/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:37:13 by jules             #+#    #+#             */
/*   Updated: 2021/06/25 15:03:30 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	swap_stack(t_stack *stack)
{
	void	*tmp;

	if (stack->size < 2)
		return (0);
	tmp = stack->list->next->content;
	stack->list->next->content = stack->list->content;
	stack->list->content = tmp;
	return (1);
}

int	push_stack(t_stack *src, t_stack *dest)
{
	t_list	*tmp;

	if (src->size == 0)
		return (0);
	tmp = src->list;
	ft_lstadd_front(&dest->list, ft_lstnew(get_val(src->list, 1)));
	src->list = src->list->next;
	ft_lstdelone(tmp, free);
	src->size--;
	dest->size++;
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
	ft_lstdelone(last, free);
	ft_lstat(stack->list, stack->size - 2)->next = NULL;
	ft_lstadd_front(&stack->list, new);
	return (1);
}
