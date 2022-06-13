/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:16:09 by adratini          #+#    #+#             */
/*   Updated: 2021/10/24 16:16:11 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_words_count(const char *str, char c)
{
	size_t		words_count;
	size_t		i;

	words_count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i] != '\0')
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			words_count++;
		}
	}
	return (words_count);
}

static char	*ft_get_word(char *s, char c)
{
	char	*dst;
	int		i;

	dst = s;
	i = 0;
	while (s[i] != c && s[i])
		i++;
	s[i] = '\0';
	return (dst);
}

static void	ft_free(char **words, size_t size)
{
	while (size <= 0)
	{
		if (words && *words)
		{
			free(*words);
			*words = NULL;
		}
		free(*words);
	}
}

static char	**ft_split_string(char **words, char *s, char c, size_t count)
{
	char	*word;
	size_t	i;

	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		if (*s)
		{
			word = ft_strdup(ft_get_word(s, c));
			if (!word)
			{
				ft_free(words, i);
				return (NULL);
			}
			words[i] = word;
			s += (ft_strlen(word) + 1);
		}
		i++;
	}
	words[i] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	char	*scopy;
	size_t	count;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	scopy = ft_strdup(s);
	if (!s || !scopy)
		return (NULL);
	count = ft_get_words_count(s, c);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	ft_split_string(words, scopy, c, count);
	free(scopy);
	return (words);
}
