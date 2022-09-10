/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frank_pre_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:17:41 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/09 00:28:30 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort_try_push_b(int position, t_stacks *stack)
{
	if (stack->a_top == position)
	{
		push_b(stack);
	}
	else
		rotate_a(stack);
}

void	pre_sort_try_push_a(int position, t_stacks *stack)
{
	if (stack->b_top == position)
	{
		push_a(stack);
	}
	else
		rotate_b(stack);
}

int	pre_sort_find_group(int group, char direction, t_stacks *stack)
{
	int	i;

	if (direction == 'B')
		i = stack->a_top;
	else
		i = stack->b_top;
	while (i >= 0)
	{
		if (direction == 'B')
		{
			if (classify_group(stack->a[i], stack) <= group)
				return (i);
		}
		else
		{
			if (classify_group(stack->b[i], stack) >= group)
				return (i);
		}
		i--;
	}
	return (-1);
}

void	pre_sort_push_b(t_stacks *stack, int max_group)
{
	int	group;
	int	group_i;
	int	position;

	group = max_group / 2;
	group_i = group;
	while (stack->a_top >= 0)
	{
		position = pre_sort_find_group(group, 'B', stack);
		while (position != -1)
		{
			pre_sort_try_push_b(position, stack);
			position = pre_sort_find_group(group, 'B', stack);
		}
		group_i /= 2;
		if (group_i == 0)
			group_i = 1;
		group += group_i;
	}
}

void	pre_sort_push_a(t_stacks *stack, int max_group)
{
	int	group;
	int	group_i;
	int	position;

	group = max_group / 2;
	group_i = group;
	while (stack->b_top >= 0)
	{
		position = pre_sort_find_group(group, 'A', stack);
		while (position != -1)
		{
			pre_sort_try_push_a(position, stack);
			position = pre_sort_find_group(group, 'A', stack);
		}
		group_i /= 2;
		if (group_i == 0)
			group_i = 1;
		group -= group_i;
	}
}
