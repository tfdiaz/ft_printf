/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:30:20 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/09 17:34:56 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char const *s, size_t len)
{
	write(1, s, len);
}

void	ft_putvec(t_vect *vec)
{
	size_t i;

	i = 0;
	if (vec->has_null_char)
	{
		while (i < vec->index_len)
		{
			if (i == 0)
				write(1, vec->str, vec->index[i] - 1);
			write(1, "", 1);
			if (i + 1 == vec->index_len)
				write(1, vec->str + vec->index[i] - i,
					vec->len - vec->index[i]);
			else
				write(1, vec->str + vec->index[i],
					vec->index[i + 1] - vec->index[i] - 1);
			i++;
		}
	}
	else
		write(1, vec->str, vec->len);
}
