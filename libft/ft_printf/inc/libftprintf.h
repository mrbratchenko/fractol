/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:38:22 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/01 21:38:24 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define FLAG1 (print->fl1)
# define FLAG2 (print->fl2)
# define FLAG3 (print->fl3)
# define FLAG4 (print->fl4)
# define VLD_FLS (*s == '+' || *s == '-' || *s == ' ' || *s == '#' || *s == '0')
# define HASH_FL (FLAG1 == '#' || FLAG2 == '#' || FLAG3 == '#' || FLAG4 == '#')
# define ZERO_FL (FLAG1 == '0' || FLAG2 == '0' || FLAG3 == '0' || FLAG4 == '0')
# define MINUS_FL (FLAG1 == '-' || FLAG2 == '-' || FLAG3 == '-' || FLAG4 == '-')
# define PLUS_FL (FLAG1 == '+' || FLAG2 == '+'|| FLAG3 == '+' || FLAG4 == '+')
# define SPACE_FL (FLAG1 == ' ' || FLAG2 == ' '|| FLAG3 == ' ' || FLAG4 == ' ')
# define MIN_WID (print->min_width)
# define DOT (print->dot)
# define PREC (print->prec)
# define SZ_MOD1 (print->size_mod1)
# define SZ_MOD2 (print->size_mod2)
# define CONV_LET (print->conv_let)
# define INVLD_SP (print->invalid_spec)

typedef struct	s_struct
{
	char		invalid_spec;
	char		fl1;
	char		fl2;
	char		fl3;
	char		fl4;
	int			min_width;
	char		dot;
	int			prec;
	char		size_mod1;
	char		size_mod2;
	char		conv_let;

}				t_struct;

int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
void			ft_putchar(char c);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_strnew(size_t size);
void			*ft_memset(void *b, int c, size_t len);
int				ft_printf(const char *format, ...);
void			ft_base(int nbr, int base, char is_cap);
char			*ft_actual_printf(char *format, va_list *arg, int *chars_ret);
char			*ft_itoa_base_signed(intmax_t n);
char			*ft_itoa_base_unsigned(uintmax_t n, int base, int is_cap);
void			ft_get_specs(char **format, t_struct *print);
void			ft_print_str(char *ret_str, int *chars_ret);
void			ft_print_char(char c, int *chars_ret);
void			ft_process_nbrs(va_list *arg, t_struct *print, int *chars_ret);
void			ft_process_str(va_list *arg, t_struct *print, int *chars_ret);
void			ft_process_char(va_list *arg, t_struct *print, int *chars_ret);
void			ft_process_min_width(int i, t_struct *print, char *str,
														int *chars_ret);
void			ft_process_d_i(t_struct *print, intmax_t *nbr, char *str,
														int *chars_ret);
void			ft_process_percent(t_struct *print, int *chars_ret);
void			ft_process_w_char(t_struct *print, wchar_t value,
												int *chars_ret, int if_wstr);
int				ft_calc_w_len(wchar_t value);
void			ft_process_w_str(wchar_t *value, int *chars_ret,
															t_struct *print);
void			ft_process_unsigned(t_struct *print, intmax_t *nbr, char *str,
														int *chars_ret);
void			ft_process_hex(t_struct *print, intmax_t *nbr, char *str,
														int *chars_ret);
void			ft_process_oct(t_struct *print, intmax_t *nbr, char *str,
														int *chars_ret);
void			ft_process_address(t_struct *print, char *str, intmax_t *nbr,
														int *chars_ret);
int				ft_process_invalid(t_struct *print, char invalid,
														int *chars_ret);
void			ft_process_float(t_struct *print, double nbr, char *str,
														int *chars_ret);
char			*ft_itoa_base_float(intmax_t n);

#endif
