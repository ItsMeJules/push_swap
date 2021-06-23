/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:01:56 by jules             #+#    #+#             */
/*   Updated: 2021/06/23 15:12:41 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_valid_op(char *op)
{
	if (ft_strlen(op) > 3)
		return (0);
	return (!ft_strcmp(op, "sa") || !ft_strcmp(op, "sb") || !ft_strcmp(op, "ss")
			|| !ft_strcmp(op, "pa") || !ft_strcmp(op, "pb")
			|| !ft_strcmp(op, "ra") || !ft_strcmp(op, "rb")
			|| !ft_strcmp(op, "rr") || !ft_strcmp(op, "rra")
			|| !ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrr"));
}

void	do_op(char *op, t_stack *stacka, t_stack *stackb)
{
	if (!ft_strcmp(op, "sa"))
		swap_stack(stacka);
	else if (!ft_strcmp(op, "sb"))
		swap_stack(stackb);
	else if (!ft_strcmp(op, "ss"))
		double_swap(stacka, stackb);
	else if (!ft_strcmp(op, "pa"))
		push_stack(stackb, stacka);
	else if (!ft_strcmp(op, "pb"))
		push_stack(stacka, stackb);
	else if (!ft_strcmp(op, "ra"))
		rotate_stack(stacka);
	else if (!ft_strcmp(op, "rb"))
		rotate_stack(stackb);
	else if (!ft_strcmp(op, "rr"))
		double_rotate(stacka, stackb);
	else if (!ft_strcmp(op, "rra"))
		rev_rotate_stack(stacka);
	else if (!ft_strcmp(op, "rrb"))
		rev_rotate_stack(stackb);
	else if (!ft_strcmp(op, "rrr"))
		double_rev_rotate(stacka, stackb);
//	print_stacks(stacka, stackb);
}

void	read_ops(t_stack *stacka, t_stack *stackb)
{
	char	*line;

	while (get_next_line(0, &line) != 0)
	{
		if (!is_valid_op(line))
		{
			free(line);
			quit_prgm(stacka, stackb);
		}
		do_op(line, stacka, stackb);
		free(line);
	}
}
