/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:40:25 by tdiaz             #+#    #+#             */
/*   Updated: 2018/07/20 16:41:50 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define BUFF_SIZE 32


typedef unsigned char t_byte;

typedef unsigned char t_bool;

typedef struct  s_flags
{
    t_byte leftjust;
    t_byte zeropad;
    t_byte pound;
    t_byte prec;
    t_byte plus;
    t_byte hh;
    t_byte h;
    t_byte l;
    t_byte ll;
    t_byte j;
    t_byte z;
    t_byte x;
    int     padlen;
    int     preclen;

}               t_flags;

typedef	struct	s_vect
{
	size_t	len;
	size_t	cap;
    size_t  num_chars;
	char	*str;
}				t_vect;

typedef struct  s_dispatch
{
    void     (*prt)(va_list ap, t_flags **flags_set, t_vect **vect);
    char     *s;
}               t_dispatch;

int             ft_printf(const char * restrict format, ...);
char			*ft_strnew(size_t size);
char            *itoa_base(intmax_t x, intmax_t base);
void			ft_putnbr(uintmax_t n);
void			ft_putchar(char c);
void			ft_putendl(char const *s);
void			ft_putstr(char const *s);
void			*ft_memset(void *b, int c, size_t len);
int	            ft_atoi(const char *str);
void            freeflags(t_flags **flags_set);
size_t	        ft_strlen(const char *s);
t_vect			*vect_new(size_t size);
t_vect	        *vect_add(t_vect *vect, char *str, size_t num_char);
void			vect_free(t_vect **vect);
void	        *ft_memmove(void *dst, const void *src, size_t len);
char	        *ft_strcat(char *s1, const char *s2);
char	        *ft_strjoin(char *s1, char *s2);
char	        *ft_strcpy(char *dst, const char *src);
char	        *ft_strdup(const char *s1);
void            up_str(char **s);
void            set_length(char **s, t_flags **flags_set);

char            *unicode(wchar_t wchar);
char            *str_wstr(wchar_t *wchar);
wchar_t         *wstr_set(wchar_t *wstr, wchar_t wc, size_t len);

void            prt_ptr(va_list ap, t_flags **flags_set, t_vect **vect);
void            prt_str(va_list ap, t_flags **flags_set, t_vect **vect);
void            prt_oct(va_list ap, t_flags **flags_set, t_vect **vect);
void            prt_wstr(va_list ap, t_flags **flags_set, t_vect **vect);
void            prt_int(va_list ap, t_flags **flags_set, t_vect **vect);
void            prt_uint(va_list ap, t_flags **flags_set, t_vect **vect);
void            prt_hex(va_list ap, t_flags **flags_set, t_vect **vect);
void            prt_wc(va_list ap, t_flags **flags_set, t_vect **vect);
void            prt_c(va_list ap, t_flags **flags_set, t_vect **vect);

size_t	        ft_wstrlen(wchar_t *wchar);
wchar_t         *ft_wstrjoin(wchar_t *ws1, wchar_t *ws2);
wchar_t	        *ft_wstrcpy(wchar_t *dst, wchar_t *src);
wchar_t         *ft_wstrcat(wchar_t *ws1, wchar_t *ws2);
wchar_t         *ft_wstrnew(size_t size);
wchar_t         *ft_wstrdup(wchar_t *ws1);

#endif