/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_double_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:47:22 by jules             #+#    #+#             */
/*   Updated: 2021/06/04 19:42:52 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	double_rotate(t_stack *stacka, t_stack *stackb)
{
	int	ret;

	ret = 0;
	if (rotate_stack(stacka) == 0)
		ret--;
	if (rotate_stack(stackb) == 0)
		ret--;
	if (ret == 0)
		return (1);
	return (ret);
}

int	double_rev_rotate(t_stack *stacka, t_stack *stackb)
{
	int	ret;

	ret = 0;
	if (rev_rotate_stack(stacka) == 0)
		ret--;
	if (rev_rotate_stack(stackb) == 0)
		ret--;
	if (ret == 0)
		return (1);
	return (ret);
}

int	double_swap(t_stack *stacka, t_stack *stackb)
{
	int	ret;

	ret = 0;
	if (swap_stack(stacka) == 0)
		ret--;
	if (swap_stack(stackb) == 0)
		ret--;
	if (ret == 0)
		return (1);
	return (ret);
}
