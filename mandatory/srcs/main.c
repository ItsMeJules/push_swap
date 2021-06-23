/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:57:20 by jpeyron           #+#    #+#             */
/*   Updated: 2021/06/23 15:10:06 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	choose_algorithm(t_swap *swap)
{
	if (is_sorted(swap->a->list))
		return (1);
	if (swap->a->size < 3)
		return (swap_stack(swap, swap->a));
	else if (swap->a->size == 3)
		return (sort_three(swap));
	else if (swap->a->size <= 15)
		return (sort_fifteen(swap));
	else if (swap->a->size <= 100)
		return (sort_big(swap, 30));
	else
		return (sort_big(swap, 80));
	return (1);
}

int	main(int ac, char **av)
{
	t_swap	*swap;	

	swap = init_swap(ac, av);
	choose_algorithm(swap);
	//print_stacks(swap);
	//ft_putstr_fd("There was ", 1);
	//ft_putnbr_fd(swap->nb_op, 1);
	//ft_putstr_fd(" operations.", 1);
	ft_lstclear(&swap->a->list, free);
	ft_lstclear(&swap->b->list, free);
	free(swap->a);
	free(swap->b);
	free(swap);
}
