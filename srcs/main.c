/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:57:20 by jpeyron           #+#    #+#             */
/*   Updated: 2021/05/31 15:24:46 by jules            ###   ########.fr       */
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
	return (1);
}

int	main(int ac, char **av)
{
	t_swap	*swap;	

	swap = init_swap(ac, av);
	choose_algorithm(swap);
	printf("There was %d operations.", swap->nb_op);
	ft_lstclear(&swap->a->list, free);
	ft_lstclear(&swap->b->list, free);
	free(swap->a);
	free(swap->b);
	free(swap);
}
