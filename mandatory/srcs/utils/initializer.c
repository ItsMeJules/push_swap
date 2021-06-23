/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:29:59 by jpeyron           #+#    #+#             */
/*   Updated: 2021/06/04 17:37:55 by jules            ###   ########.fr       */
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

int	check_unique(int nb, t_list *list)
{
	while (list)
	{
		if (nb == get_val(list, 0)->e)
			return (0);
		list = list->next;
	}
	return (1);
}

int	check_int(char *nbr)
{
	static char*	min = "-2147483648";
	static char*	max = "2147483647";
	int				len;
	int				i;

	len = ft_strlen(nbr);
	if (len == 11)
	{
		i = 1;
		while (nbr[i] && nbr[i] == min[i]) 
			i++;
		if (nbr[i] && nbr[i] > min[i])
			return (0);
	}
	else if (len == 10)
	{
		i = 0;
		while (nbr[i] && nbr[i] == max[i]) 
			i++;
		if (nbr[i] && nbr[i] > max[i])
			return (0);
	}
	return (len <= 11);
}

void	parse_stack(int ac, char **av, t_stack *stack)
{
	t_selem	*selem;
	int		i;

	stack->list = NULL;
	i = 0;
	while (++i < ac)
	{
		if (!string_is_num(av[i]) || !check_int(av[i]))
			quit_prgm();
		selem = malloc(sizeof(t_selem));
		if (!selem)
			quit_prgm();
		selem->e = ft_atoi(av[i]);
		if (!check_unique(selem->e, stack->list))
		{
			ft_lstclear(&stack->list, free);
			free(stack);
			quit_prgm();
		}
		ft_lstadd_back(&stack->list, ft_lstnew(selem));
	}
}

t_swap	*init_swap(int ac, char **av)
{
	t_swap	*swap;

	swap = malloc(sizeof(t_swap));
	if (!swap)
		quit_prgm();
	swap->a = malloc(sizeof(t_stack));
	if (!swap->a)
		quit_prgm();
	parse_stack(ac, av, swap->a);
	swap->a->size = ft_lstsize(swap->a->list);
	swap->a->id = 'a';
	swap->b = malloc(sizeof(t_stack));
	if (!swap->b)
		quit_prgm();
	parse_stack(0, NULL, swap->b);
	swap->b->size = 0;
	swap->b->id = 'b';
	swap->nb_op = 0;
	return (swap);
}
