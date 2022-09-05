/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:09:32 by lufelip2          #+#    #+#             */
/*   Updated: 2022/06/14 17:12:23 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*us_dst;
	unsigned char	*us_src;

	us_dst = (unsigned char *)dst;
	us_src = (unsigned char *)src;
	if (us_dst < us_src)
		ft_memcpy(dst, src, n);
	else
	{
		while (n-- > 0)
			us_dst[n] = us_src[n];
	}
	return (dst);
}
