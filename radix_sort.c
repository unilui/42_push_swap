/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:23:20 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/01 02:54:38 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	classify_group(int nbr)
{
	int	group;
	//int subgroup;
	int	bit_counter;

	bit_counter = 0;
	group = 0;
	while (bit_counter < 32)
	{
		if ((nbr & (1 << bit_counter)) >> bit_counter)
			group = bit_counter;
		bit_counter++;
	}
	group++;
	if (group > 2 && (nbr & (1 << (group - 2))) >> (group - 2))
		return (group + 1);
	return (group);
}

int	find_group(int group, t_stacks *stack)
{
	int	i;

	i = stack->a_top;
	while (i >= 0)
	{
		if (classify_group(stack->a[i]) == group)
			return (i);
		i--;
	}
	return (-1);
}

void	try_to_push_b(int position, t_stacks *stack)
{
	if (position == stack->a_top)
		push_b(stack);
	else if (position == 0)
	{
		r_rotate_a(stack);
		push_b(stack);
	}
	else
	{
		if ((stack->a_top - position) < position)
			rotate_a(stack);
		else
			r_rotate_a(stack);
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
		if (stack->a[stack->a_top] > stack->a[stack->a_top - 1]
		&&	stack->a[stack->a_top] != 8)
			swap_a(stack);
		else
			rotate_a(stack);
	}
}

void	radix_sort(t_stacks *stack)
{
	//int	max_group;
	//int	group;
	//int	position;
//
	//max_group = 2;
	//group = 1;
	//while (group < max_group)
	//{
	//	position = find_group(group, stack);
	//	while (position != -1)
	//	{
	//		try_to_push_b(position, stack);
	//		position = find_group(group, stack);
	//	}
	//	group++;
	//}
	//ascending_sort(stack);
	//print_stack(stack);
	(void)stack;
	//printf("%d\n", classify_group(0));
	printf("1  -> %d\n", classify_group(1));
	printf("2  -> %d\n", classify_group(2));
	printf("3  -> %d\n", classify_group(3));
	printf("4  -> %d\n", classify_group(4));
	printf("5  -> %d\n", classify_group(5));
	printf("6  -> %d\n", classify_group(6));
	printf("7  -> %d\n", classify_group(7));
	printf("8  -> %d\n", classify_group(8));
	printf("9  -> %d\n", classify_group(9));
	printf("10 -> %d\n", classify_group(10));
	printf("11 -> %d\n", classify_group(11));
	printf("12 -> %d\n", classify_group(12));
	printf("13 -> %d\n", classify_group(13));
	printf("14 -> %d\n", classify_group(14));
	printf("15 -> %d\n", classify_group(15));
	//printf("16 -> %d\n", classify_group(16));
	//printf("17 -> %d\n", classify_group(17));
	//printf("18 -> %d\n", classify_group(18));
	//printf("19 -> %d\n", classify_group(19));
	//printf("20 -> %d\n", classify_group(20));
}
