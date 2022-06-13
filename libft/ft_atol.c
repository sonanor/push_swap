/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:27:50 by adratini          #+#    #+#             */
/*   Updated: 2022/02/15 17:27:51 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *num)
{
	long	return_value;
	short	negative;
	int		i;

	return_value = 0;
	negative = 1;
	i = 0;
	while (ft_isspace(num[i]))
		i++;
	if (num[i] == '-' || num[i] == '+')
	{
		if (num[i++] == '-')
			negative = -1;
	}
	while ('0' <= num[i] && num[i] <= '9')
	{
		return_value *= 10;
		return_value += num[i] - 48;
		i++;
	}
	return (return_value * negative);
}
