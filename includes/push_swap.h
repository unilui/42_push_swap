/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 02:32:38 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/10 03:17:33 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stacks {
	int	*a;
	int	*b;
	int	size;
	int	a_top;
	int	b_top;
	int	*index;
}	t_stacks;

void	swap_a(t_stacks *stack);
void	swap_b(t_stacks *stack);
void	push_a(t_stacks *stack);
void	push_b(t_stacks *stack);
void	rotate_a(t_stacks *stack);
void	rotate_b(t_stacks *stack);
void	r_rotate_a(t_stacks *stack);
void	r_rotate_b(t_stacks *stack);
void	frank_sort(t_stacks *stack);
int		classify_group(int nbr, t_stacks *stack);
int		find_group(int group, t_stacks *stack);
int		find_group_b(int group, t_stacks *stack);
int		max_group(t_stacks *stack);
void	simple_sort(t_stacks *stack);
int		validate(char *stack);
void	pre_sort_push_a(t_stacks *stack, int max_group);
void	pre_sort_push_b(t_stacks *stack, int max_group);
int		stack_parser(t_stacks *stack, char *stack_input);

#endif
