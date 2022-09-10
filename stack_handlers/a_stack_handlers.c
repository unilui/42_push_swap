/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 02:27:25 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/09 00:48:09 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap_a(t_stacks *stack)
{
	int	tmp;

	ft_printf("sa\n");
	if (stack->a_top <= 0)
		return ;
	tmp = stack->a[stack->a_top];
	stack->a[stack->a_top] = stack->a[stack->a_top - 1];
	stack->a[stack->a_top - 1] = tmp;
}

void	push_a(t_stacks *stack)
{
	ft_printf("pa\n");
	if (stack->b_top == -1)
		return ;
	stack->a_top++;
	stack->a[stack->a_top] = stack->b[stack->b_top];
	stack->b_top--;
}

void	rotate_a(t_stacks *stack)
{
	int	tmp;
	int	i;

	ft_printf("ra\n");
	if (stack->a_top <= 0)
		return ;
	i = stack->a_top;
	tmp = stack->a[stack->a_top];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
}

void	r_rotate_a(t_stacks *stack)
{
	int	tmp;
	int	i;

	ft_printf("rra\n");
	if (stack->a_top <= 0)
		return ;
	i = 0;
	tmp = stack->a[0];
	while (i < stack->a_top)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->a_top] = tmp;
}
