/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:09:32 by adratini          #+#    #+#             */
/*   Updated: 2021/10/17 20:09:34 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_is_maxlong(char *c, int sign)
{
	size_t	len;
	int		result;
	int		i;

	result = 0;
	i = 0;
	len = ft_strlen(c);
	while (c[i] && ft_isdigit((int)c[i]))
		i++;
	if (len < 19)
		return (0);
	else if (sign > 0 && i >= 19)
		result = ft_strncmp(c, "9223372036854775807", len);
	else if (sign < 0 && i >= 19)
		result = ft_strncmp(c, "9223372036854775808", len);
	if (result <= 0)
		return (0);
	return (1);
}

static int	ft_long_result(int sign)
{
	if (sign > 0)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		num;
	int		sign;
	char	*s;

	sign = 1;
	num = 0;
	s = (char *)str;
	if (*s == '\0')
		return (0);
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	if (ft_is_maxlong(s, sign))
		return (ft_long_result(sign));
	while (*s && *s >= '0' && *s <= '9')
		num = num * 10 + (*s++ - '0');
	return (num * sign);
}
