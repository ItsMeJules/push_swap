/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:24:15 by jpeyron           #+#    #+#             */
/*   Updated: 2021/06/01 16:17:44 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	t_list	*list;
	char	id;
	long	size;
}				t_stack;

typedef struct s_swap
{
	t_stack	*a;
	t_stack	*b;
	int		nb_op;
}				t_swap;

typedef struct s_selem
{
	int	e;
}				t_selem;

/*
** main.c
*/
int		choose_algorithm(t_swap *swap);

/*
** UTILS/utils.c
*/
void	quit_prgm();
t_selem	*get_val(t_list *elem, int clone);
void	print_stacks(t_swap *swap);
void	print_op(char *op, char id);
int		get_index(t_list *list, int e);

/*
** UTILS/initializer.c
*/
int		string_is_num(char *str);
t_stack	*parse_stack(int ac, char **av);
t_swap	*init_swap(int ac, char **av);

/*
** UTILS/sort_utils.c
*/
int		get_mediane(t_stack *stack);
int		is_sorted(t_list *list);
int		get_smallest(t_stack *stack);
void	move_to_first_pos(t_swap *swap, t_stack *stack, int number);

/*
** OPERATIONS/swap_operations.c
*/
int		swap_stack(t_swap *swap, t_stack *stack);
int		push_stack(t_swap *swap, t_stack *from_stack);
int		rotate_stack(t_swap *swap, t_stack *stack);
int		rev_rotate_stack(t_swap *swap, t_stack *stack);

/*
** SORT/stack_sort.c
*/
int		sort_three(t_swap *swap);
int		sort_fifteen(t_swap *swap);
int		sort_a_lot(t_swap *swap);

#endif
