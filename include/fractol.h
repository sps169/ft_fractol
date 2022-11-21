/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:27:08 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/15 12:52:41 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

struct	s_node {
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
};
typedef struct s_node	t_node;

t_node		*parse_args_list(int argc, char *argv[]);

t_node		*add_last(int value, t_node **list);

t_node		*add_first(int value, t_node **list);

void		clear_list(t_node **list);

int			find_value_position(int value, t_node *list);

void		swap(t_node **stack, char name);

void		rotate(t_node **stack, char name);

void		reverse_rotate(t_node **stack, char name);

void		push(t_node **src, t_node **dst, char dstname);

int			list_size(t_node *list);

void		print_list(t_node *list);

void		bubble_min_to_max(t_node **stack);

void		bubble_max_to_min(t_node **stack);

int			find_max(t_node *stack);

int			find_min(t_node *stack);

void		values_to_position(t_node **stack);

void		double_stack_bubble_sort(t_node **stack_a, t_node **stack_b);

int			is_sorted(t_node *stack);

int			is_reverse_sorted(t_node *stack);

void		radix_sort(t_node **stack_a, t_node **stack_b);

void		simple_sort(t_node **list);

void		reset_list(t_node **node);

float		stack_mean(t_node *stack);

void		free_split(char **split);

#endif
