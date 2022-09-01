/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:25:29 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/01 01:22:15 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stacks *stack)
{
	int i;

	if (stack->a_top > stack->b_top)
		i = stack->a_top;
	else
		i = stack->b_top;
	while (i >= 0)
	{
		if (i <= stack->a_top)
			printf("| %d |", stack->a[i]);
		else
			printf("|   |");
		if (i <= stack->b_top)
			printf("| %d |", stack->b[i]);
		else
			printf("|   |");
		printf("\n");
		i--;
	}
}

int	main(void)
{
	t_stacks	stack;
	int arr[] = { 2, 5, 6, 3, 1, 8 };

	stack.a = arr;
	stack.a_top = 5;
	stack.b_top = -1;

	radix_sort(&stack);
}
