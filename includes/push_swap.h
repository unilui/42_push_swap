/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 02:32:38 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/12 06:17:27 by lufelip2         ###   ########.fr       */
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

# define INT_MIN -2147483648
# define INT_MAX 2147483647

void	free_table(char **table);
void	free_stack(t_stacks *stack);
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
int		zsh_validate(char *stack);
int		bash_validate(char **stack);
void	pre_sort_push_a(t_stacks *stack, int max_group);
void	pre_sort_push_b(t_stacks *stack, int max_group);
int		zsh_stack_parser(t_stacks *stack, char *stack_input);
int		bash_stack_parser(t_stacks *stack, char **stack_input);
int		ascending_check(t_stacks *stack);
int		count_stack(char **stack);

#endif
