/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:33:27 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/20 16:33:30 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_dispatch  g_dispatch[10] = {
	{.prt = &prt_ptr, .s = "p"},
	{.prt = &prt_str, .s = "s"},
	{.prt = &prt_oct, .s = "oO"},
	{.prt = &prt_wstr, .s = "S"},
	{.prt = &prt_int, .s = "idD"},
	{.prt = &prt_uint, .s = "uU"},
	{.prt = &prt_hex, .s = "xX"},
	{.prt = &prt_c, .s = "c"},
	{.prt = &prt_wc, .s = "C"},
	{0, 0}
};

char    *cloudy(t_flags **flags_set)
{
	char	*str;

	intmax_t x = (*flags_set)->padlen;
	if ((*flags_set)->padlen <= 0)
		return (NULL);
	if ((*flags_set)->zeropad && (*flags_set)->plus && !((*flags_set)->leftjust))
		(*flags_set)->padlen--;	
	str = ft_strnew((*flags_set)->padlen + 1);
	if ((*flags_set)->zeropad && !((*flags_set)->leftjust))
		str = ft_memset(str, '0', (*flags_set)->padlen);
	else
		str = ft_memset(str, ' ', (*flags_set)->padlen);
	if ((*flags_set)->zeropad && (*flags_set)->plus && !((*flags_set)->leftjust))
		str = ft_strjoin("+", str);
	return (str);
}

wchar_t *wcloudy(t_flags **flags_set)
{
	wchar_t *wstr;

	intmax_t x = (*flags_set)->padlen;
	if ((*flags_set)->padlen <= 0)
		return (NULL);
	wstr = ft_wstrnew((*flags_set)->padlen + 1);
	wstr = wstr_set(wstr, L' ', (*flags_set)->padlen);
	return (wstr);
}

void    prt_c(va_list ap, t_flags **flags_set, t_vect **vect)
{
	char c;
	char *str;

	c = va_arg(ap, int);
	str = ft_strnew(1);
	str[0] = c;
	if ((*flags_set)->preclen < ft_strlen(str) && (*flags_set)->preclen !=0)
		str[((*flags_set)->preclen)] = '\0';
	if ((*flags_set)->padlen - ft_strlen(str) > 0)
		(*flags_set)->padlen -= ft_strlen(str);
	if((*flags_set)->leftjust)
		str = ft_strjoin(str, cloudy(flags_set));
	else
		str = ft_strjoin(cloudy(flags_set), str);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}

void    prt_wc(va_list ap, t_flags **flags_set, t_vect **vect)
{
	wchar_t *wstr;
	wchar_t wc;
	char *str;

	wc = va_arg(ap, wchar_t);
	wstr = ft_wstrnew(1);
	wstr[0] = wc;
	if ((*flags_set)->preclen < ft_wstrlen(wstr) && (*flags_set)->preclen !=0)
		wstr[((*flags_set)->preclen)] = '\0';
	if ((*flags_set)->padlen - ft_wstrlen(wstr) > 0)
		(*flags_set)->padlen -= ft_wstrlen(wstr);
	if((*flags_set)->leftjust)
		wstr = ft_wstrjoin(wstr, wcloudy(flags_set));
	else
		wstr = ft_wstrjoin(wcloudy(flags_set), wstr);
	str = str_wstr(wstr);
	vect_add((*vect), str, ft_wstrlen(wstr));
	free(str);
	free(wstr);
}

void    prt_hex(va_list ap, t_flags **flags_set, t_vect **vect)
{
	char *str;

	str = itoa_base(va_arg(ap, intmax_t), 16);
	if ((*flags_set)->x)
		up_str(&str);
	if ((*flags_set)->pound)
		str = ft_strjoin("0x", str);       
	while ((*flags_set)->preclen > ft_strlen(str))
		str = ft_strjoin("0", str);
	if ((*flags_set)->padlen - ft_strlen(str) > 0)
		(*flags_set)->padlen -= ft_strlen(str); 
	if((*flags_set)->leftjust)
		str = ft_strjoin(str, cloudy(flags_set));
	else
		str = ft_strjoin(cloudy(flags_set), str);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}

void sconvert(intmax_t *x, t_flags **flags_set)
{
	if ((*flags_set)->hh)
	{
		while (*x > SCHAR_MAX || *x < SCHAR_MIN)
			*x = *x % (SCHAR_MAX + 1) - (SCHAR_MAX + 1);
	}
	else if ((*flags_set)->h)
	{
		while (*x > SHRT_MAX || *x < SHRT_MIN)
			*x = *x % (SHRT_MAX + 1) - (SHRT_MAX + 1);
	}
	else if ((*flags_set)->l)
	{
		while (*x > INT_MAX || *x < INT_MIN)
			*x = *x % ((long)INT_MAX + 1) - ((long)INT_MAX + 1);
	}
	else if ((*flags_set)->ll)
	{
		while (*x > LONG_MAX || *x < LONG_MIN)
			*x = *x % LONG_MAX - 1 - LONG_MAX - 1;
	}
}

void uconvert(uintmax_t *x, t_flags **flags_set)
{
	if ((*flags_set)->hh)
	{
		while (*x > UCHAR_MAX)
			*x = *x % (UCHAR_MAX + 1);
	}
	else if ((*flags_set)->h)
	{
		while (*x > USHRT_MAX)
			*x = *x % (USHRT_MAX + 1);
	}
	else if ((*flags_set)->l)
	{
		while (*x > UINT_MAX)
			*x = *x % ((long)UINT_MAX + 1);
	}
	else if ((*flags_set)->ll)
	{
		while (*x > ULONG_MAX)
			*x = *x % ULONG_MAX - 1;
	}
}

void    prt_int(va_list ap, t_flags **flags_set, t_vect **vect)
{
	char *str;
	intmax_t x;

	x = va_arg(ap, intmax_t);
	sconvert(&x, flags_set);
	str = itoa_base(x, 10);
	if (str[0] == '-')
	{
		(*flags_set)->preclen++;
		(*flags_set)->plus = 0;
	}
	while ((*flags_set)->preclen > ft_strlen(str))
		str = ft_strjoin("0", str);
	if ((*flags_set)->preclen == ft_strlen(str))
		(*flags_set)->zeropad = 0;
	if (((*flags_set)->plus) && !(*flags_set)->zeropad)
	{
		str = ft_strjoin("+", str);
		(*flags_set)->plus = 0;
	}
	if ((*flags_set)->padlen - ft_strlen(str) > 0)
		(*flags_set)->padlen -= ft_strlen(str);
	if ((*flags_set)->leftjust)
		str = ft_strjoin(str, cloudy(flags_set));
	else
		str = ft_strjoin(cloudy(flags_set), str);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}

void    prt_uint(va_list ap, t_flags **flags_set, t_vect **vect)
{
	char *str;
	uintmax_t x;

	x = va_arg(ap, uintmax_t);
	uconvert(&x, flags_set);
	str = itoa_base(x, 10);
	if (str[0] == '-')
	{
		(*flags_set)->preclen++;
		(*flags_set)->plus = 0;
	}
	while ((*flags_set)->preclen > ft_strlen(str))
		str = ft_strjoin("0", str);
	if ((*flags_set)->preclen == ft_strlen(str))
		(*flags_set)->zeropad = 0;
	if (((*flags_set)->plus) && !(*flags_set)->zeropad)
	{
		str = ft_strjoin("+", str);
		(*flags_set)->plus = 0;
	}
	if ((*flags_set)->padlen - ft_strlen(str) > 0)
		(*flags_set)->padlen -= ft_strlen(str);
	if ((*flags_set)->leftjust)
		str = ft_strjoin(str, cloudy(flags_set));
	else
		str = ft_strjoin(cloudy(flags_set), str);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}

void    prt_wstr(va_list ap, t_flags **flags_set, t_vect **vect)
{
	wchar_t *wstr;
	char *str;

	wstr = ft_wstrdup(va_arg(ap, wchar_t*));
	if (wstr == NULL)
		wstr = ft_wstrdup(L"(null)");
	if ((*flags_set)->preclen < ft_wstrlen(wstr) && (*flags_set)->preclen !=0)
		wstr[((*flags_set)->preclen)] = '\0';
	if ((*flags_set)->padlen - ft_wstrlen(wstr) > 0)
		(*flags_set)->padlen -= ft_wstrlen(wstr);
	if((*flags_set)->leftjust)
		wstr = ft_wstrjoin(wstr, wcloudy(flags_set));
	else
		wstr = ft_wstrjoin(wcloudy(flags_set), wstr);
	str = str_wstr(wstr);
	vect_add((*vect), str, ft_wstrlen(wstr));
	free(str);
	free(wstr);
}

void prt_ptr(va_list ap, t_flags **flags_set, t_vect **vect)
{
	char *str;
	intmax_t x;

	x = va_arg(ap, void *) - (void*)0;
	str = itoa_base(x, 16);
	while ((*flags_set)->preclen > ft_strlen(str))
		str = ft_strjoin("0", str);
	str = ft_strjoin("0x", str);
	if ((*flags_set)->padlen - ft_strlen(str) > 0)
		(*flags_set)->padlen -= ft_strlen(str);
	if((*flags_set)->leftjust)
		str = ft_strjoin(str, cloudy(flags_set));
	else
		str = ft_strjoin(cloudy(flags_set), str);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}

void    prt_str(va_list ap, t_flags **flags_set, t_vect **vect)
{
	char *str;

	str = ft_strdup(va_arg(ap, const char *));
	if (str == NULL)
		str = ft_strdup("(null)");
	if ((*flags_set)->preclen < ft_strlen(str) && (*flags_set)->preclen !=0)
		str[((*flags_set)->preclen)] = '\0';
	if ((*flags_set)->padlen - ft_strlen(str) > 0)
		(*flags_set)->padlen -= ft_strlen(str);
	if((*flags_set)->leftjust)
		str = ft_strjoin(str, cloudy(flags_set));
	else
		str = ft_strjoin(cloudy(flags_set), str);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}

void    prt_oct(va_list ap, t_flags **flags_set, t_vect **vect)
{
	char *str;

	str = itoa_base(va_arg(ap, intmax_t), 8);
	if ((*flags_set)->pound)
		str = ft_strjoin("0", str);       
	while ((*flags_set)->preclen > ft_strlen(str))
		str = ft_strjoin("0", str);
	if ((*flags_set)->padlen - ft_strlen(str) > 0)
		(*flags_set)->padlen -= ft_strlen(str); 
	if((*flags_set)->leftjust)
		str = ft_strjoin(str, cloudy(flags_set));
	else
		str = ft_strjoin(cloudy(flags_set), str);
	vect_add((*vect), str, ft_strlen(str));
	free(str);
}

t_bool  argsymb(char c)
{
	if (c == 's' || c == 'S' || c == 'd' || c == 'D' || c == 'i'|| c == 'o'
	|| c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'c'
	|| c == 'C' || c == 'p' || c == '\0')
		return (TRUE);
	return (FALSE);
}

t_flags *newflags()
{
	t_flags *new_fl;
	
	if ((new_fl = (t_flags*)malloc(sizeof(t_flags))) == NULL)
		return (NULL);
	new_fl->leftjust = 0;
	new_fl->zeropad = 0;
	new_fl->pound = 0;
	new_fl->prec = 0;
	new_fl->padlen = 0;
	new_fl->preclen = 0;
	new_fl->plus = 0;
	new_fl->hh = 0;
	new_fl->h = 0;
	new_fl->l = 0;
	new_fl->ll = 0;
	new_fl->j = 0;
	new_fl->z = 0;
	new_fl->x = 0;
	return (new_fl);
}

void freeflags(t_flags **flags_set)
{
	if (flags_set == NULL)
		return;
	free(*flags_set);
	*flags_set = NULL;
}

void setnumber(char **s, t_flags **flags, va_list ap)
{
	int x;
	int i;
	char str[12];

	i = 0;
	if (**s == '*')
	{
		if ((*flags)->prec)
			(*flags)->preclen = va_arg(ap, int);
		else
			(*flags)->padlen = va_arg(ap, int);
		return ; 
	}
	while (**s >= '0' && **s <= '9')
	{
		str[i] = **s;
		i++;
		(*s)++;
	}
	(*s)--;
	str[i] = '\0';
	x = ft_atoi(str);
	if ((*flags)->prec)
		(*flags)->preclen = x;
	else
		(*flags)->padlen = x;
}

t_flags *setflags(char **s, va_list ap)
{
	t_flags *flags_set;

	if ((flags_set = newflags()) == NULL)
		return (NULL);
	while (argsymb(**s) == FALSE)
	{
		if(**s == '-')
			flags_set->leftjust = 1;
		else if(**s == '0')
			flags_set->zeropad = 1;
		else if(**s == '#')
			flags_set->pound = 1;
		else if (**s == '.')
			flags_set->prec = 1;
		else if (**s == '+')
			flags_set->plus = 1;
		else if ((**s >= '1' && **s <= '9') || **s == '*')
			setnumber(s, &flags_set, ap);
		else
			set_length(s, &flags_set);
		(*s)++;
	}
	if(**s == 'X')
		(flags_set)->x = 1;
	return (flags_set);
}

void    set_length(char **s, t_flags **flags_set)
{
	if (**s == 'h' && (*flags_set)->h)
	{
		(*flags_set)->hh = 1;
		(*flags_set)->h = 0;
	}
	else if (**s == 'l' && (*flags_set)->l)
	{
		(*flags_set)->ll = 1;
		(*flags_set)->l = 0;
	}
	else if (**s == 'h')
		(*flags_set)->h = 1;
	else if (**s == 'l')
		(*flags_set)->l = 1;
	else if(**s == 'j')
		(*flags_set)->j = 1;
	else if(**s == 'z')
		(*flags_set)->z = 1;
}

void    funct(char **s, va_list ap, t_vect **vect)
{
	t_flags *flags_set;
	int i;
	int j;

	i = 0;
	j = 0;
	if (**s == '%')
		return ;
	flags_set = setflags(s, ap);
	while(g_dispatch[i].prt != NULL)
	{
		if(**s == 's' && flags_set->l)
			**s = 'S';
		if(**s == 'c' && flags_set->l)
			**s = 'C';
		j = 0;
		while (g_dispatch[i].s[j] != '\0')
		{
			if (**s == g_dispatch[i].s[j])
				g_dispatch[i].prt(ap, &flags_set, vect);
			j++;
		}
		i++;
	}
	freeflags(&flags_set);
	(*s)++;
}

size_t parsefor(char *s, va_list ap)
{
	t_vect *vect;
	char str[2];
	size_t x;

	str[1] = '\0';
	vect = vect_new(BUFF_SIZE);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			funct(&s, ap, &vect);
		}
		if (!*s)
			break;
		str[0] = *s;
		vect_add(vect, str, ft_strlen(str));
		s++;
	}
	ft_putstr(vect->str);
	x = vect->num_chars;
	vect_free(&vect);
	return (x);
}

int ft_printf(const char *format, ...)
 {
	 va_list ap;
	 char *s;
	 int x;

	 va_start(ap, format);
	 s = ft_strdup(format);
	 x = (int)parsefor(s, ap);
	 va_end(ap);
	 return(x);
 }