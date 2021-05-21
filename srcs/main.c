/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:57:20 by jpeyron           #+#    #+#             */
/*   Updated: 2021/05/21 16:52:20 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


int	main(int ac, char **av)
{
	t_swap	*swap;	

	swap = init_swap(ac, av);
	swap_stack(swap->a);
	push_stack(swap, swap->a);
}
