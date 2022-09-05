/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:27:42 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/24 12:01:10 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	replace_handler(t_str *str)
{
	static int	rep = 0;
	t_replace	replace;

	if (str->chr == '%' && !rep)
	{
		rep++;
		return ;
	}
	if (rep)
	{
		replace = placeholder(str->chr);
		replace(str);
		rep--;
	}
	else
		skip_replace(str);
}
