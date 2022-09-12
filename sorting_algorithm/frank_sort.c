/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frank_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:23:20 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/12 05:54:47 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	group_push_a(t_stacks *stack)
{
	push_a(stack);
	if (stack->a_top > 0)
	{
		if (stack->a[stack->a_top - 1] < stack->a[stack->a_top])
			swap_a(stack);
	}
}

void	sort_push_a(t_stacks *stack, int max_group)
{
	int	m_group;
	int	group;
	int	position;

	m_group = max_group;
	group = m_group - 1;
	while (group >= 1)
	{
		position = find_group_b(group, stack);
		while (position != -1)
		{
			group_push_a(stack);
			position = find_group_b(group, stack);
		}
		group--;
	}
}

void	sort_push_b(t_stacks *stack, int max_group)
{
	int	m_group;
	int	group;
	int	position;

	m_group = max_group;
	group = 1;
	while (group < m_group)
	{
		position = find_group(group, stack);
		while (position != -1 && stack->a_top >= (2 + (stack->size == 4)))
		{
			try_to_push_b(position, group, stack);
			position = find_group(group, stack);
		}
		group++;
	}
}

void	frank_sort(t_stacks *stack)
{
	int	max;

	if (stack->size == 0 || ascending_check(stack))
		return ;
	max = max_group(stack);
	if (stack->size > 4)
	{
		pre_sort_push_b(stack, max);
		pre_sort_push_a(stack, max);
	}
	sort_push_b(stack, max);
	simple_sort(stack);
	sort_push_a(stack, max);
}
