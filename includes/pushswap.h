/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:24:15 by jpeyron           #+#    #+#             */
/*   Updated: 2021/06/03 17:41:44 by jules            ###   ########.fr       */
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
	int		chunks_nb;
}				t_swap;

typedef struct s_selem
{
	int	e;
}				t_selem;

typedef struct s_chunk
{
	int	min;
	int	med;
	int	max;
	int	size;
}				t_chunk;

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
t_swap	*init_swap(int ac, char **av);

/*
** UTILS/sort_utils.c
*/
int		get_mediane(t_stack *stack);
int		is_sorted(t_list *list);
int		get_smallest(t_stack *stack);
int		get_biggest(t_stack *stack);
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
int		sort_big(t_swap *swap, int chunk_size);

/*
** SORT/chunks.c
*/
t_list	*clone_list(t_list *list);
t_list	*bubble_sort_numbers(t_list *list);
t_chunk	*create_chunks(t_swap *swap, int chunk_size);

/*
** SORT/chunks_sorting.c
*/
void	push_chunk_vals(t_swap *swap, t_stack *a, t_chunk chunk);

/*
** SORT/big_sort_utils.c
*/
int		is_between(int min, int nb, int max);
int		index_of_val(int min, int max, int top, t_stack *stack);

#endif
