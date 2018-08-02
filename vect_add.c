/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_add_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:07:32 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/17 21:13:48 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vect	*vect_add(t_vect *vect, char *str, size_t num_char)
{
	char *tmp;
	char *n_str;

	if (vect->cap < vect->len + ft_strlen(str))
	{
		while (vect->cap < vect->len + ft_strlen(str))
			vect->cap *= 2;
		n_str = ft_strnew(vect->cap);
		tmp = vect->str;
		vect->str = ft_memmove(n_str, vect->str, vect->len);
		if (tmp != NULL)
			free(tmp);
	}
	vect->len += ft_strlen(str);
	vect->str = ft_strcat(vect->str, str);
	vect->num_chars += num_char;
	return (vect);
}
