/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:13:05 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/09 16:44:45 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s++) != '\0')
		i++;
	return (i);
}
