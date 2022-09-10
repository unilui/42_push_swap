/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:40:47 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/09 23:53:33 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	count_stack(char **stack)
{
	int	i;

	i = 0;
	while(stack[i])
		i++;
	return (i);
}

void	fill_stack(int *dest, char **src, int size)
{
	int	i;
	int	x;

	i = size - 1;
	x = 0;
	while(i >= 0)
	{
		dest[x] = ft_atoi(src[i]);
		i--;
		x++;
	}
}

int	stack_parser(t_stacks *stack, char *stack_input)
{
	char	**splitted_stack;
	int		stack_size;

	splitted_stack = ft_split(stack_input, ' ');
	stack_size = count_stack(splitted_stack);
	stack->a = malloc(stack_size * sizeof(int));
	stack->b = malloc(stack_size * sizeof(int));
	stack->index = malloc(stack_size * sizeof(int));
	if (!stack->a || !stack->b || !stack->index)
		return (0);
	fill_stack(stack->a, splitted_stack, stack_size);
	fill_stack(stack->index, splitted_stack, stack_size);
	ft_sort_int_tab(stack->index, stack_size);
	stack->size = stack_size - 1;
	stack->a_top = stack_size - 1;
	stack->b_top = - 1;
	return (1);
}
