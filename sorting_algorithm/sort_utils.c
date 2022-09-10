/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:38:14 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/10 01:30:23 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	classify_group(int nbr, t_stacks *stack)
{
	int	i;

	i = 0;
	while (i <= stack->size)
	{
		if (stack->index[i] == nbr)
			break ;
		i++;
	}
	return ((i / 3) + 1);
}

int	find_group(int group, t_stacks *stack)
{
	int	i;

	i = stack->a_top;
	while (i >= 0)
	{
		if (classify_group(stack->a[i], stack) == group)
			return (i);
		i--;
	}
	return (-1);
}

int	find_group_b(int group, t_stacks *stack)
{
	int	i;

	i = stack->b_top;
	while (i >= 0)
	{
		if (classify_group(stack->b[i], stack) == group)
			return (i);
		i--;
	}
	return (-1);
}

int	max_group(t_stacks *stack)
{
	int	i;
	int	max;

	i = stack->a_top;
	max = 0;
	while (i >= 0)
	{
		if (classify_group(stack->a[i], stack) > max)
			max = classify_group(stack->a[i], stack);
		i--;
	}
	return (max);
}

int	get_biggest(int group, t_stacks *stack)
{
	int	i;
	int	biggest;
	int	biggest_i;

	i = stack->b_top;
	biggest = 0;
	biggest_i = 0;
	while (classify_group(stack->b[i], stack) == group && i >= 0)
	{
		if (stack->b[i] > biggest)
		{
			biggest = stack->b[i];
			biggest_i = i;
		}
		i--;
	}
	return (biggest_i);
}
