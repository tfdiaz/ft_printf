/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 18:25:54 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/10 18:43:06 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	ltot;
	char	*str;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	if (s2 == NULL && s1 != NULL)
		return (ft_strdup(s1));
	ltot = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((str = (char*)malloc(sizeof(char) * ltot)) == NULL)
		return (NULL);
	if (*s1 == '0' && *s2 == '-')
	{
		s2++;
		*str++ = '-';
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		str--;
		return (str);
	}
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
