/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_double_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:22:02 by jules             #+#    #+#             */
/*   Updated: 2021/06/04 19:12:32 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	double_rotate(t_swap *swap)
{
	int	ret;

	ret = 0;
	if (rotate_stack(swap, swap->a) == 0)
		ret--;
	if (rotate_stack(swap, swap->b) == 0)
		ret--;
	if (ret == 0)
		return (1);
	return (ret);
}

int	double_rev_rotate(t_swap *swap)
{
	int	ret;

	ret = 0;
	if (rev_rotate_stack(swap, swap->a) == 0)
		ret--;
	if (rev_rotate_stack(swap, swap->b) == 0)
		ret--;
	if (ret == 0)
		return (1);
	return (ret);
}

int	double_swap(t_swap *swap)
{
	int	ret;
	
	ret = 0;
	if (swap_stack(swap, swap->a) == 0)
		ret--;
	if (swap_stack(swap, swap->b) == 0)
		ret--;
	if (ret == 0)
		return (1);
	return (ret);
}
