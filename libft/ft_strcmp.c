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

int	ft_strcmp(const char *str1, const char *str2)
{
	char	*s1;
	char	*s2;
	size_t	j;

	s1 = (char *)str1;
	s2 = (char *)str2;
	j = 0;
	while (s1[j] && s2[j])
	{
		if ((unsigned char)s1[j] != (unsigned char)s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		j++;
	}
	return (0);
}
