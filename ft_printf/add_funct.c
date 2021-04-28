/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 08:04:25 by mdulcie           #+#    #+#             */
/*   Updated: 2021/01/10 08:04:28 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	g_transform_10_16[16] = "0123456789abcdef";

char	*ft_itoa_base(unsigned long n, int base, int pr)
{
	char				*s;
	int					i;
	unsigned long		c;

	i = 1;
	c = n;
	while ((c /= (unsigned long)base))
		i++;
	g_flag[4][0] == 'p' ? (i += 2) : 0;
	pr = pr > i ? pr - i : 0;
	pr > 0 ? i += pr : 0;
	if (!(s = (char *)malloc(sizeof(char) * ++i)))
		return (NULL);
	s[--i] = 0;
	n ? 0 : (s[i - 1] = '0');
	n ? (n = (unsigned long)n * (unsigned long)base) : 0;
	while (c < (unsigned long)pr)
		s[c++] = '0';
	while ((g_flag[4][0] == 'p' ? i > 2 : i) && (n /= (unsigned long)base))
		s[--i] = g_transform_10_16[n % (unsigned long)base];
	g_flag[4][0] == 'p' ? s[0] = '0' : 0;
	g_flag[4][0] == 'p' ? s[1] = 'x' : 0;
	return (s);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	int					i;
	unsigned long int	n;
	int					sign;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	str[i] == '+' && str[i + 1] != '-' ? i++ : 0;
	str[i] == '-' ? sign = -1 : 0;
	str[i] == '-' ? i++ : 0;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	if (n > 9223372036854775807)
		return (sign == -1 ? 0 : -1);
	return (sign == -1 ? n = -n : n);
}

char	*ft_charnbr(char *s, int n, int i, int flag)
{
	n == 0 ? *s = '0' : 0;
	if (n == 0)
		return (s);
	while (--i >= 0 && n != 0)
	{
		s[i] = n % 10 + '0';
		n /= 10;
	}
	if (flag)
		s[10] = '8';
	return (s);
}

char	*ft_itoa_pr(long n, int pr)
{
	char	*s;
	int		i;
	long	c;
	int		flag;

	flag = 0;
	i = 1;
	n == -2147483648 ? flag = 1 : 0;
	n == -2147483648 ? n++ : 0;
	c = n;
	while ((c /= 10))
		i++;
	pr = pr > i ? pr - i : 0;
	pr > 0 ? i += pr : 0;
	n < 0 ? i++ : 0;
	if (!(s = (char *)malloc(sizeof(char) * (++i))))
		return (NULL);
	s[--i] = 0;
	n < 0 ? s[0] = '-' : 0;
	c = n < 0 ? 1 : 0;
	n < 0 ? n = -n : 0;
	while (c <= pr)
		s[c++] = '0';
	s = ft_charnbr(s, n, i, flag);
	return (s);
}
