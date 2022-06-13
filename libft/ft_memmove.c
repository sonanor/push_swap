/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:06:50 by adratini          #+#    #+#             */
/*   Updated: 2021/10/10 17:06:51 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	char	*cdest;
	char	*csrc;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	cdest = (char *)dest + num;
	csrc = (char *)src + num;
	if (dest < src)
	{
		ft_memcpy(dest, src, num);
	}
	else
	{
		while (num--)
		{
			*--cdest = *--csrc;
		}
	}
	return (dest);
}
