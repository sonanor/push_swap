/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:53:09 by adratini          #+#    #+#             */
/*   Updated: 2021/10/17 17:53:11 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	j;

	s1 = (char *)str1;
	s2 = (char *)str2;
	j = 0;
	while (s1[j] && s2[j] && j < n)
	{
		if ((unsigned char)s1[j] != (unsigned char)s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		j++;
	}
	if (j < n)
		return ((unsigned char)s1[j] - (unsigned char)s2[j]);
	return (0);
}
