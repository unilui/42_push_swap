/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:23:20 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/04 22:18:11 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	classify_group(int nbr, t_stacks *stack)
{
	int	i;

	i = 0;
	while (i <= 99)
	{
		if (stack->index[i] == nbr)
			break;
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

void	try_to_push_b(int position, int group, t_stacks *stack)
{
	static int	pushed_group;
	int			sort_b;

	sort_b = 0;
	if (position == stack->a_top)
	{
		push_b(stack);
		if (group == pushed_group)
			sort_b = 1;
		pushed_group = group;
	}
	else
	{
		if ((stack->a_top - position) < position)
			rotate_a(stack);
		else
			r_rotate_a(stack);
	}
	if (sort_b)
	{
		if (stack->b[stack->b_top - 1] > stack->b[stack->b_top])
			swap_b(stack);
		sort_b = 0;
	}
}

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

void	ascending_sort(t_stacks *stack)
{
	while (!ascending_check(stack))
	{
		if (stack->a[stack->a_top] > stack->a[0])
			rotate_a(stack);
		else
			swap_a(stack);
	}
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

void	group_push_b(t_stacks *stack)
{
	int	m_group;
	int	group;
	int	position;

	m_group = max_group(stack);
	group = 1;
	while (group < m_group)
	{
		position = find_group(group, stack);
		while (position != -1 && stack->a_top >= 3)
		{
			try_to_push_b(position, group, stack);
			position = find_group(group, stack);
		}
		group++;
	}
}

void	try_to_push_a(int position, t_stacks *stack)
{
	if ((stack->b_top - position) == 0)
		push_a(stack);
	else
	{
		swap_b(stack);
		push_a(stack);
	}
}

int	get_biggest(int group, t_stacks *stack)
{
	int	i;
	int	biggest;
	int	biggest_i;

	i = stack->b_top;
	biggest = 0;
	biggest_i = 0;
	while (i >= 0 && classify_group(stack->b[i], stack) == group)
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

void	group_push_a(t_stacks *stack)
{
	int	m_group;
	int	group;
	int	position;

	m_group = max_group(stack);
	group = m_group - 1;
	while (group >= 1)
	{
		position = find_group_b(group, stack);
		while (position != -1)
		{
			try_to_push_a(get_biggest(group, stack), stack);
			position = find_group_b(group, stack);
		}
		group--;
	}
}

void	radix_sort(t_stacks *stack)
{
	group_push_b(stack);
	ascending_sort(stack);
	group_push_a(stack);
}
