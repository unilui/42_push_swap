/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 03:58:44 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/12 06:13:15 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	value_check(char **stack)
{
	int		i;
	int		x;
	long	nbr;

	i = 1;
	x = 1;
	while (stack[i])
	{
		nbr = ft_atoi(stack[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		while (stack[x])
		{
			if (ft_atoi(stack[x]) == nbr && x != i)
				return (0);
			x++;
		}
		x = 1;
		i++;
	}
	return (1);
}

static int	digit_check(char *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (ft_isdigit(stack[i])
			|| stack[i] == '+'
			|| stack[i] == '-'
			|| stack[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	table_digit_check(char **stack)
{
	int	i;

	i = 1;
	while (stack[i])
	{
		if (digit_check(stack[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	bash_validate(char **stack)
{
	if (table_digit_check(stack)
		&& value_check(stack))
		return (1);
	return (0);
}
