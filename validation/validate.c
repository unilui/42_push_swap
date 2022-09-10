/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 02:56:02 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/10 03:17:11 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	digit_check(char *stack)
{
	int	i;

	i = 0;
	while(stack[i])
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

int	validate(char *stack)
{
	if (digit_check(stack))
		return (1);
	return (0);
}
