/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_and_part_of_diux.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 08:54:22 by mdulcie           #+#    #+#             */
/*   Updated: 2021/01/10 08:54:31 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_diux(char *s)
{
	g_flag[0][0] == '-' ? write(1, s, g_len_s) : 0;
	if (g_flag[0][0] != '-' && g_flag[2][0] != '.' && g_flag[0][1] == '0' &&
		s[0] == '-')
		(write(1, "-", 1));
	while ((g_width-- - g_len_s) > 0)
		(g_flag[0][0] != '-' && g_flag[2][0] != '.' && g_flag[0][1] == '0') ?
			(write(1, "0", 1)) : (write(1, " ", 1));
	if (g_flag[0][0] != '-')
	{
		if (g_flag[0][0] != '-' && g_flag[2][0] != '.' && g_flag[0][1] == '0' &&
			s[0] == '-')
			write(1, s + 1, g_len_s - 1);
		else
			write(1, s, g_len_s);
	}
}

void	ft_clear_flag_global(void)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < 5 && (j = 0) == 0)
		while (j < 14)
			g_flag[i][j++] = '\0';
	g_len_s = 0;
	g_width = 0;
	g_precision = 0;
}

int		ft_finish_specif_form(char *st)
{
	if (*st == 'c' || *st == 's' || *st == 'p' ||
		*st == 'd' || *st == 'i' || *st == 'u' ||
		*st == 'x' || *st == 'X' || *st == '%')
		return (1);
	else
		return (0);
}

void	ft_flag_push_width_precis(int *ret, char *st)
{
	int	i;
	int	j;

	j = 0;
	i = 11;
	st[*ret] == '*' ? g_flag[1][0] = '*' : 0;
	st[*ret] == '*' ? (*ret)++ : 0;
	if (st[*ret] != '*')
	{
		while (st[*ret] >= '0' && st[*ret] <= '9' && j < i)
			g_flag[1][j++] = st[(*ret)++];
		while (st[*ret] >= '0' && st[*ret] <= '9')
			(*ret)++;
	}
	if (st[*ret] == '.')
	{
		g_flag[2][0] = st[(*ret)++];
		j = 1;
		st[*ret] == '*' ? g_flag[2][j] = '*' : 0;
		st[*ret] == '*' ? (*ret)++ : 0;
		while (st[*ret] >= '0' && st[*ret] <= '9' && j < i)
			g_flag[2][j++] = st[(*ret)++];
	}
}

int		ft_flag(char *st, va_list vl_ptr, char *st0)
{
	int	ret;

	ret = 0;
	while (st[ret] == '-' || st[ret] == '0')
	{
		while (st[ret] == '-')
			g_flag[0][0] = st[ret++];
		while (st[ret] == '0')
			g_flag[0][1] = st[ret++];
	}
	ft_flag_push_width_precis(&ret, st);
	if (ft_finish_specif_form(&st[ret]))
		g_flag[4][0] = st[ret];
	if (!ft_finish_specif_form(&st[ret]) || ft_parser(vl_ptr) < 0)
	{
		va_end(vl_ptr);
		return (st0 - st - 1);
	}
	return (++ret);
}
