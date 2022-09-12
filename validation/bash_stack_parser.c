/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_stack_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 03:58:48 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/12 05:06:24 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	fill_stack(int *dest, char **src, int size)
{
	int	i;
	int	x;

	i = size;
	x = 0;
	while (i >= 1)
	{
		dest[x] = ft_atoi(src[i]);
		i--;
		x++;
	}
}

int	bash_stack_parser(t_stacks *stack, char **stack_input)
{
	int		stack_size;

	stack_size = count_stack(stack_input) - 1;
	stack->a = malloc(stack_size * sizeof(int));
	stack->b = malloc(stack_size * sizeof(int));
	stack->index = malloc(stack_size * sizeof(int));
	if (!stack->a || !stack->b || !stack->index)
		return (0);
	fill_stack(stack->a, stack_input, stack_size);
	fill_stack(stack->index, stack_input, stack_size);
	ft_sort_int_tab(stack->index, stack_size);
	stack->size = stack_size - 1;
	stack->a_top = stack_size - 1;
	stack->b_top = -1;
	return (1);
}
