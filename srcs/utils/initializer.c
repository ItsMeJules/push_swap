/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:29:59 by jpeyron           #+#    #+#             */
/*   Updated: 2021/05/24 15:07:01 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	string_is_num(char *str)
{
	int	i;

	i = 0;
	if (!ft_isdigit(str[i]) && str[i] != '-')
		return (0);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

t_stack	*parse_stack(int ac, char **av)
{
	t_stack	*stack;
	t_selem	*selem;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		quit_prgm();
	stack->list = NULL;
	i = 0;
	while (++i < ac)
	{
		if (!string_is_num(av[i]))
			quit_prgm();
		selem = malloc(sizeof(t_selem));
		if (!selem)
			quit_prgm();
		selem->e = ft_atoi(av[i]);
		ft_lstadd_back(&stack->list, ft_lstnew(selem));
	}
	return (stack);
}

t_swap	*init_swap(int ac, char **av)
{
	t_swap	*swap;

	swap = malloc(sizeof(t_swap));
	if (!swap)
		quit_prgm();
	swap->a = parse_stack(ac, av);
	swap->a->size = ft_lstsize(swap->a->list);
	swap->a->id = 'a';
	swap->b = parse_stack(0, NULL);
	swap->b->size = 0;
	swap->b->id = 'b';
	return (swap);
}
