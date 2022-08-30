/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 02:32:38 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/28 04:53:48 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>

typedef struct s_stacks {
	int	*a;
	int	b[6];
	int	a_top;
	int	b_top;
}	t_stacks;

void	swap_a(t_stacks *stack);
void	swap_b(t_stacks *stack);
void	push_a(t_stacks *stack);
void	push_b(t_stacks *stack);
void	rotate_a(t_stacks *stack);
void	rotate_b(t_stacks *stack);
void	r_rotate_a(t_stacks *stack);
void	r_rotate_b(t_stacks *stack);

#endif