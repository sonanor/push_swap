/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:37:53 by adratini          #+#    #+#             */
/*   Updated: 2021/10/09 17:37:55 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char	*new_dest;

	new_dest = (unsigned char *)destination;
	while (n != 0)
	{
		*new_dest++ = (unsigned char)c;
		n--;
	}
	return (destination);
}
