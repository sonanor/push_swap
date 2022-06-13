/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:55:56 by adratini          #+#    #+#             */
/*   Updated: 2021/10/10 17:55:57 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*ch;
	unsigned char	*found_ch;

	found_ch = NULL;
	ch = (unsigned char *)arr;
	while (n--)
	{
		if (*ch != (unsigned char)c)
		{
			ch++;
		}
		else
		{
			found_ch = ch;
			return (found_ch);
		}
	}
	return (found_ch);
}
