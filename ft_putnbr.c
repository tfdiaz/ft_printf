/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:38:44 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/09 17:52:16 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(uintmax_t n)
{
	uintmax_t digit;

	digit = n % 10;
	if (digit != n)
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + digit);
	}
	else
		ft_putchar('0' + digit);
}
