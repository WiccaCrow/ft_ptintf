/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 07:28:54 by mdulcie           #+#    #+#             */
/*   Updated: 2021/01/10 07:28:57 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_c(va_list vl_ptr)
{
	char	c;

	g_width = ft_width(vl_ptr);
	c = (g_flag[4][0] == '%' ? '%' : va_arg(vl_ptr, int));
	if (g_flag[0][0] == '-')
		write(1, &c, 1);
	g_ret += g_width > 0 ? g_width : 1;
	if (g_width > 0)
		while (--g_width)
			g_flag[0][0] != '-' && g_flag[0][1] == '0' ? write(1, "0", 1) :
				write(1, " ", 1);
	if (g_flag[0][0] != '-')
		write(1, &c, 1);
}

void	ft_type_s(va_list vl_ptr)
{
	char	*s;

	g_width = ft_width(vl_ptr);
	g_precision = ft_precision(vl_ptr);
	if (!(s = va_arg(vl_ptr, char *)))
		s = "(null)";
	g_len_s = ft_strlen(s);
	if (g_flag[2][0] && g_precision >= 0 && g_precision < g_len_s)
		g_len_s = g_precision;
	g_flag[0][0] == '-' ? write(1, s, g_len_s) : 0;
	g_width > g_len_s ? g_ret += (g_width - g_len_s) : 0;
	g_ret += g_len_s;
	if (g_width > g_len_s)
		while ((g_width-- - g_len_s))
			write(1, " ", 1);
	if (g_flag[0][0] != '-')
		write(1, s, g_len_s);
}

int		ft_type_p(va_list vl_ptr)
{
	unsigned long	arg;
	char			*s;

	g_width = ft_width(vl_ptr);
	g_precision = ft_precision(vl_ptr);
	arg = va_arg(vl_ptr, unsigned long);
	if (!(s = ft_itoa_base(arg, 16, 0)))
		return (-1);
	s[2] = arg == 0 && g_flag[2][0] == '.' && !g_flag[2][1] ? '\0' : s[2];
	g_len_s = ft_strlen(s);
	if (g_flag[0][0] == '-')
		write(1, s, g_len_s);
	g_ret += (g_width - g_len_s) > 0 ? g_width : g_len_s;
	while ((g_width-- - g_len_s) > 0)
		write(1, " ", 1);
	if (g_flag[0][0] != '-')
		write(1, s, g_len_s);
	free(s);
	s = NULL;
	return (0);
}

char	*ft_convert_to_string(char *s, int di, unsigned long ux)
{
	if (g_flag[4][0] == 'u' || g_flag[4][0] == 'X' || g_flag[4][0] == 'x')
		s = ft_itoa_base(ux, (g_flag[4][0] == 'X' ||
		g_flag[4][0] == 'x' ? 16 : 10), g_precision);
	g_flag[4][0] == 'd' || g_flag[4][0] == 'i' ?
		s = ft_itoa_pr(di, g_precision) : 0;
	if (!s)
		return (NULL);
	if ((((g_flag[4][0] == 'd' || g_flag[4][0] == 'i') && di == 0) ||
		((g_flag[4][0] == 'u' || g_flag[4][0] == 'X' || g_flag[4][0] == 'x') &&
		ux == 0)) && g_flag[2][0] == '.' && g_precision == 0)
		s[0] = '\0';
	g_len_s = ft_strlen(s);
	return (s);
}

int		ft_type_diux(va_list vl_ptr)
{
	int				di;
	unsigned long	ux;
	char			*s;

	s = NULL;
	g_width = ft_width(vl_ptr);
	g_precision = ft_precision(vl_ptr);
	di = (g_flag[4][0] == 'd' || g_flag[4][0] == 'i' ? va_arg(vl_ptr, int) : 0);
	ux = (g_flag[4][0] == 'u' || g_flag[4][0] == 'x' || g_flag[4][0] == 'X' ?
		va_arg(vl_ptr, unsigned int) : 0);
	if (!(s = ft_convert_to_string(s, di, ux)))
		return (-1);
	g_ret += (g_width - g_len_s) > 0 ? g_width : g_len_s;
	ft_write_diux(s);
	free(s);
	s = NULL;
	return (0);
}
