/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:53:50 by adratini          #+#    #+#             */
/*   Updated: 2021/10/26 22:53:51 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_len(long int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		len = 1;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			num_len;
	long int	num;

	num = (long)n;
	num_len = digit_len(num);
	str = (char *)malloc(sizeof(char) * (num_len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	str[num_len] = '\0';
	num_len--;
	while (num_len >= 0 && num != 0)
	{
		str[num_len] = num % 10 + '0';
		num = num / 10;
		num_len--;
	}
	return (str);
}
