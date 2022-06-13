/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:58:05 by adratini          #+#    #+#             */
/*   Updated: 2021/10/10 18:58:07 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*carr1;
	unsigned char	*carr2;

	carr1 = (unsigned char *)arr1;
	carr2 = (unsigned char *)arr2;
	while (n > 0)
	{
		if (*carr1 != *carr2)
		{
			return (*carr1 - *carr2);
		}
		carr1++;
		carr2++;
		n--;
	}
	return (0);
}
