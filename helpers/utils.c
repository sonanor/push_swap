/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:39:01 by adratini          #+#    #+#             */
/*   Updated: 2022/01/30 21:39:02 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	massage_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	count_array_length(char **array)
{
	int	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

char	*new_str(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(char));
	str[0] = '\0';
	return (str);
}

int	*copy_arr(int *arr, int arr_len)
{
	int	i;
	int	*sorted_arr;

	i = 0;
	sorted_arr = (int *)malloc(sizeof(int) * arr_len);
	if (!sorted_arr)
	{
		free(arr);
		return (NULL);
	}
	while (i < arr_len)
	{
		sorted_arr[i] = arr[i];
		i++;
	}
	return (sorted_arr);
}
