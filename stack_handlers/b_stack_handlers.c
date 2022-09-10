/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 02:27:22 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/09 00:48:24 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap_b(t_stacks *stack)
{
	int	tmp;

	ft_printf("sb\n");
	if (stack->b_top <= 0)
		return ;
	tmp = stack->b[stack->b_top];
	stack->b[stack->b_top] = stack->b[stack->b_top - 1];
	stack->b[stack->b_top - 1] = tmp;
}

void	push_b(t_stacks *stack)
{
	ft_printf("pb\n");
	if (stack->a_top == -1)
		return ;
	stack->b_top++;
	stack->b[stack->b_top] = stack->a[stack->a_top];
	stack->a_top--;
}

void	rotate_b(t_stacks *stack)
{
	int	tmp;
	int	i;

	ft_printf("rb\n");
	if (stack->b_top <= 0)
		return ;
	i = stack->b_top;
	tmp = stack->b[stack->b_top];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
}

void	r_rotate_b(t_stacks *stack)
{
	int	tmp;
	int	i;

	ft_printf("rrb\n");
	if (stack->b_top <= 0)
		return ;
	i = 0;
	tmp = stack->b[0];
	while (i < stack->b_top)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->b_top] = tmp;
}
