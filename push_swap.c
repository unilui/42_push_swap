/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:25:29 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/10 03:16:54 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (validate(argv[1]) && stack_parser(&stack, argv[1]))
		ft_printf("Ok!\n");
	(void)argc;
	//frank_sort(&stack);
}
