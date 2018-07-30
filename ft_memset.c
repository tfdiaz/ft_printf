/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:00:08 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/10 19:43:04 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*cpy;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	cpy = (char*)b;
	while (i < len)
	{
		cpy[i] = ch;
		i++;
	}
	return (cpy);
}
