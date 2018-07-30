/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 14:43:47 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/10 19:43:28 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ssrc;
	unsigned char	*ddst;
	size_t			i;

	i = -1;
	ssrc = (unsigned char *)src;
	ddst = (unsigned char *)dst;
	if (ssrc < ddst)
	{
		while ((int)--len >= 0)
		{
			*(ddst + len) = *(ssrc + len);
		}
	}
	else
	{
		while (++i < len)
		{
			*(ddst + i) = *(ssrc + i);
		}
	}
	return (ddst);
}
