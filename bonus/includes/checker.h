/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:50:26 by jules             #+#    #+#             */
/*   Updated: 2021/06/23 14:55:19 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_stack
{
	t_list	*list;
	long	size;
}				t_stack;

typedef struct s_selem
{
	int	e;
}				t_selem;

/*
** UTILS/parser.c
*/
t_selem	*get_val(t_list *elem, int clone);
void	parse_stack(int ac, char **av, t_stack *a);
void	print_stacks(t_stack *a, t_stack *b);

/*
** UTILS/utils.c
*/
int		is_sorted(t_list *list);
void	quit_prgm(t_stack *stacka, t_stack *stackb);

/*
** READER/read_operations.c
*/
void	read_ops(t_stack *stacka, t_stack *stackb);

/*
** OPERATIONS/swap_double_operations.c
*/
int		double_rotate(t_stack *stacka, t_stack *stackb);
int		double_rev_rotate(t_stack *stacka, t_stack *stackb);
int		double_swap(t_stack *stacka, t_stack *stackb);

/*
** OPERATIONS/swap_operations.c
*/
int		swap_stack(t_stack *stack);
int		push_stack(t_stack *src, t_stack *dest);
int		rotate_stack(t_stack *stack);
int		rev_rotate_stack(t_stack *stack);

#endif
