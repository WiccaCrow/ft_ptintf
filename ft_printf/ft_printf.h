/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 03:02:42 by mdulcie           #+#    #+#             */
/*   Updated: 2021/01/12 03:02:52 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>

char		g_flag[5][14];
extern char		g_transform_10_16[16];
int				g_ret;
int				g_len_s;
int				g_width;
int				g_precision;
int				ft_printf(const char *string, ...);
int				ft_flag(char *st, va_list vl_ptr, char *st0);
void			ft_flag_push_width_precis(int *ret, char *st);
int				ft_finish_specif_form(char *st);
int				ft_parser(va_list vl_ptr);
void			ft_type_c(va_list vl_ptr);
void			ft_type_s(va_list vl_ptr);
int				ft_type_p(va_list vl_ptr);
int				ft_type_diux(va_list vl_ptr);
char			*ft_convert_to_string(char *s, int di, unsigned long ux);
void			ft_write_diux(char *s);
int				ft_width(va_list vl_ptr);
int				ft_precision(va_list vl_ptr);
void			check_x_low_or_up(void);
void			ft_clear_flag_global(void);
int				ft_atoi(const char *str);
int				ft_strlen(const char *s);
char			*ft_itoa_base(unsigned long n, int base, int pr);
char			*ft_itoa_pr(long n, int pr);

#endif
