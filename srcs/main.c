/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:57:20 by jpeyron           #+#    #+#             */
/*   Updated: 2021/05/22 21:12:34 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


int	main(int ac, char **av)
{
	t_swap	*swap;	

	swap = init_swap(ac, av);
	rev_rotate_stack(swap->a);
	ft_lstclear(&swap->a->list, free);
	ft_lstclear(&swap->b->list, free);
	free(swap->a);
	free(swap->b);
	free(swap);
}
