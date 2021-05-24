/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:59:56 by jpeyron           #+#    #+#             */
/*   Updated: 2021/05/24 16:39:36 by jpeyron          ###   ########.fr       */
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
	return (get_val(list)->e);
}
