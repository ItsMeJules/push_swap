/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:24:15 by jpeyron           #+#    #+#             */
/*   Updated: 2021/05/22 14:23:31 by jules            ###   ########.fr       */
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
}				t_swap;

typedef struct s_selem
{
	int	e;
}				t_selem;

/*
** utils.c
*/
void	quit_prgm();
t_selem	*get_val(t_list *elem, int clone);
void	print_stack(t_list *stack);
void	print_op(char *op, char id);

/*
** initializer.c
*/
int		string_is_num(char *str);
t_stack	*parse_stack(int ac, char **av);
t_swap	*init_swap(int ac, char **av);

/*
** OPERATIONS/stack_operations.c
*/
int	swap_stack(t_stack *stack);
int	push_stack(t_swap *swap, t_stack *from_stack);
int	rotate_stack(t_stack *stack);
int	rev_rotate_stack(t_stack *stack);


#endif
