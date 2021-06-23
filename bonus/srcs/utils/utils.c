/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:06:53 by jules             #+#    #+#             */
/*   Updated: 2021/06/23 14:55:44 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	quit_prgm(t_stack *stacka, t_stack *stackb)
{
	ft_lstclear(&stacka->list, free);
	free(stacka);
	if (stackb != NULL)
	{
		ft_lstclear(&stackb->list, free);
		free(stackb);
	}
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
