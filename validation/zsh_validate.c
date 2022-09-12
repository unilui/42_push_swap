/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zsh_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 02:56:02 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/12 06:13:52 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	value_check(char **stack)
{
	int		i;
	int		x;
	long	nbr;

	i = 0;
	x = 0;
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
		x = 0;
		i++;
	}
	return (1);
}

int	digit_check(char *stack)
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

int	zsh_validate(char *stack)
{
	char	**splitted_stack;

	splitted_stack = ft_split(stack, ' ');
	if (digit_check(stack)
		&& value_check(splitted_stack))
	{
		free_table(splitted_stack);
		return (1);
	}
	free_table(splitted_stack);
	return (0);
}
