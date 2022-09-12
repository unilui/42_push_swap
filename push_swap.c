/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:25:29 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/12 06:05:33 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		if (zsh_validate(argv[1]) && zsh_stack_parser(&stack, argv[1]))
		{
			frank_sort(&stack);
			free_stack(&stack);
		}
		else
			ft_putstr_fd("Error\n", 2);
	}
	else
	{
		if (bash_validate(argv) && bash_stack_parser(&stack, argv))
		{
			frank_sort(&stack);
			free_stack(&stack);
		}
		else
			ft_putstr_fd("Error\n", 2);
	}
	return (0);
}
