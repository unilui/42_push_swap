/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:35:15 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/09 00:35:37 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ascending_check(t_stacks *stack)
{
	int	i;

	i = stack->a_top;
	while (i > 0)
	{
		if (stack->a[i] > stack->a[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	simple_sort(t_stacks *stack)
{
	while (!ascending_check(stack))
	{
		if (stack->a[stack->a_top] > stack->a[0])
			rotate_a(stack);
		else
			swap_a(stack);
	}
}
