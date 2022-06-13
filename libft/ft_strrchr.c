/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:08:05 by adratini          #+#    #+#             */
/*   Updated: 2021/10/17 17:08:06 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*c;
	char	*last_elem;

	c = (char *)str;
	last_elem = 0;
	while (*c != '\0')
	{
		if (*c == (char)ch)
			last_elem = c;
		c++;
	}
	if (ch == '\0')
		return (c);
	return (last_elem);
}
