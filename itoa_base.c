/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:10:06 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/21 11:34:23 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

char *itoa_base(intmax_t x, intmax_t base)
{
	int			i;
	char		*str;
	char		*alph;
	intmax_t	tmp;
	intmax_t	sgn;

	i = 0;
	tmp = x;
	sgn = 1;
	alph = "0123456789abcdef";
	if (x == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	if (x < 0)
	{
		sgn = -1;
		i++;
	}
	while (tmp != 0)
	{
		tmp = tmp / base;
		i++;
	}
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	i--;
	while (x != 0)
	{
		tmp = x % base * sgn;
		str[i] = alph[tmp];
		x /= base;
		i--;
	}
	if (sgn == -1)
		str[i] = '-';
	return (str);
}

char *uitoa_base(uintmax_t x, intmax_t base)
{
	int			i;
	char		*str;
	char		*alph;
	uintmax_t	tmp;

	i = 0;
	tmp = x;
	alph = "0123456789abcdef";
	if (x == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	while (tmp != 0)
	{
		tmp = tmp / base;
		i++;
	}
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	i--;
	while (x != 0)
	{
		tmp = x % base;
		str[i] = alph[tmp];
		x /= base;
		i--;
	}
	return (str);
}