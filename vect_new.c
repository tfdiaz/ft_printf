/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:04:14 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/17 21:17:15 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vect	*vect_new(size_t size)
{
	t_vect	*vect;

	vect = (t_vect*)malloc(sizeof(t_vect));
	if (!vect)
		return (NULL);
	vect->cap = size;
	vect->len = 0;
	vect->num_chars = 0;
	vect->str = ft_strnew(size);
	return (vect);
}
