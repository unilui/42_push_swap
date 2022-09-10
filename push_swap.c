/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:25:29 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/10 01:43:01 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
			ft_printf("| %d |", stack->a[i]);
		else
			ft_printf("|   |");
		if (i <= stack->b_top)
			ft_printf("| %d |", stack->b[i]);
		else
			ft_printf("|   |");
		ft_printf("\n");
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	stack_parser(&stack, argv[1]);
	(void)argc;
	frank_sort(&stack);
	//print_stack(&stack);
}
