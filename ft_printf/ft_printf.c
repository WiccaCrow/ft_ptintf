/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 08:42:46 by mdulcie           #+#    #+#             */
/*   Updated: 2021/01/10 08:42:49 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precision(va_list vl_ptr)
{
	g_precision = 0;
	if (g_flag[2][1] == '*')
	{
		g_precision = va_arg(vl_ptr, int);
		g_precision < 0 ? g_flag[2][0] = 0 : 0;
	}
	else if (g_flag[2][0])
		g_precision = ft_atoi(&(g_flag[2][1]));
	return (g_precision);
}

int		ft_width(va_list vl_ptr)
{
	g_width = 0;
	if (g_flag[1][0] == '*')
	{
		g_width = va_arg(vl_ptr, int);
		g_width < 0 ? g_flag[0][0] = '-' : 0;
		g_width < 0 ? g_width = -g_width : 0;
	}
	else if (g_flag[1][0])
		g_width = ft_atoi(g_flag[1]);
	return (g_width);
}

void	check_x_low_or_up(void)
{
	int	i;

	i = 10;
	while (i < 16 && g_transform_10_16[i])
	{
		if (g_flag[4][0] == 'x' || g_flag[4][0] == 'p')
			if (g_transform_10_16[i] >= 'A' && g_transform_10_16[i] <= 'Z')
				g_transform_10_16[i] += 'a' - 'A';
		if (g_flag[4][0] == 'X')
			if (g_transform_10_16[i] >= 'a' && g_transform_10_16[i] <= 'z')
				g_transform_10_16[i] += 'A' - 'a';
		i++;
	}
}

int		ft_parser(va_list vl_ptr)
{
	int	ret;

	ret = 0;
	if (g_flag[4][0] == 'c' || g_flag[4][0] == '%')
		ft_type_c(vl_ptr);
	if (g_flag[4][0] == 's')
		ft_type_s(vl_ptr);
	if (g_flag[4][0] == 'p')
	{
		check_x_low_or_up();
		if (ft_type_p(vl_ptr) < 0)
			return (-1);
	}
	if (g_flag[4][0] == 'd' || g_flag[4][0] == 'i' || g_flag[4][0] == 'u' ||
		g_flag[4][0] == 'x' || g_flag[4][0] == 'X')
	{
		if (g_flag[4][0] == 'x' || g_flag[4][0] == 'X')
			check_x_low_or_up();
		if (ft_type_diux(vl_ptr) < 0)
			return (-1);
	}
	ft_clear_flag_global();
	return (0);
}

int		ft_printf(const char *string, ...)
{
	int		i;
	va_list vl_ptr;

	g_ret = 0;
	if (!string)
		return (-1);
	va_start(vl_ptr, string);
	i = 0;
	while (string[i])
	{
		while (string[i] && string[i] != '%')
			if ((write(1, &string[i++], 1)) > 0)
				g_ret++;
		while (string[i] == '%')
			if (string[++i])
				if ((i += ft_flag(&((char*)string)[i], vl_ptr,
					(char*)string)) < 0)
					return (i);
	}
	va_end(vl_ptr);
	return (g_ret);
}
