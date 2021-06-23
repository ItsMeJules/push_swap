/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:55:18 by jules             #+#    #+#             */
/*   Updated: 2021/06/23 15:00:28 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_selem	*get_val(t_list *elem, int clone)
{
	t_selem	*selem;

	if (!clone)
		return ((t_selem *)elem->content);
	else
	{
		selem = malloc(sizeof(t_selem));
		selem->e = ((t_selem *)elem->content)->e;
		return (selem);
	}
}

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
			quit_prgm(stack, NULL);
		selem = malloc(sizeof(t_selem));
		if (!selem)
			quit_prgm(stack, NULL);
		selem->e = ft_atoi(av[i]);
		if (!check_unique(selem->e, stack->list))
			quit_prgm(stack, NULL);
		stack->size++;
		ft_lstadd_back(&stack->list, ft_lstnew(selem));
	}
}
