/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:25:31 by adratini          #+#    #+#             */
/*   Updated: 2021/10/10 20:25:32 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*c;

	i = dstsize;
	c = (char *)src;
	if (dstsize != 0)
	{
		while (--i != 0 && *c != '\0')
		{
			*dst++ = *c++;
		}
		*dst = '\0';
	}
	return (ft_strlen(src));
}
