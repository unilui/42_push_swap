/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:19:49 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/12 00:48:37 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_table(char **table)
{
	char	**tmp;

	tmp = table;
	while (*table)
		free(*table++);
	free(tmp);
}

void	free_stack(t_stacks *stack)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->index)
		free(stack->index);
}
