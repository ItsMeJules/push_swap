/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:52:21 by jules             #+#    #+#             */
/*   Updated: 2021/06/23 15:10:47 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	verif_and_free(t_stack *a, t_stack *b)
{
	if (!is_sorted(a->list) || b->size != 0)
		ft_putstr_fd("KO\n", 2);
	else
		ft_putstr_fd("OK\n", 2);
	ft_lstclear(&a->list, free);
	if (b->list != NULL)
		ft_lstclear(&b->list, free);
	free(a);
	free(b);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	long	i;

	i = a->size;
	if (b->size > i)
		i = b->size;
	while (i--)
	{
		if (i < a->size)
			ft_putnbr_fd(get_val(ft_lstat(a->list, a->size - 1 - i),
				0)->e, 1);
		ft_putstr_fd("\t | ", 1);
		if (i < b->size)
			ft_putnbr_fd(get_val(ft_lstat(b->list, b->size - 1 - i),
				0)->e, 1);
		ft_putchar_fd('\n', 1);
	}
	ft_putchar_fd('\n', 1);
}

int	main(int ac, char **av)
{
	t_stack	*stacka;
	t_stack	*stackb;

	if (ac == 1)
		return (0);
	stacka = malloc(sizeof(t_stack));
	stackb = malloc(sizeof(t_stack));
	if (!stacka || !stackb)
		return (0);
	stacka->size = 0;
	stackb->size = 0;
	stackb->list = NULL;
	parse_stack(ac, av, stacka);
	read_ops(stacka, stackb);
	//print_stacks(stacka, stackb);
	verif_and_free(stacka, stackb);
	return (1);
}
