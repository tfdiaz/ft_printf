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

void	set_null_char(t_vect *vect)
{
	vect->len += 1;
	vect->has_null_char = 1;
	vect->index[vect->index_len] = vect->len;
	vect->index_len++;
}

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
	if (*str != '\0')
		vect->len += ft_strlen(str);
	else
		set_null_char(vect);
	vect->str = ft_strcat(vect->str, str);
	vect->num_chars += num_char;
	return (vect);
}
