/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:35:05 by adratini          #+#    #+#             */
/*   Updated: 2022/02/15 15:35:06 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	duplicates(const int *arr, int arr_len)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (j < arr_len)
	{
		if (arr[i] == arr[j])
		{
			return (1);
		}
		i++;
		j++;
	}
	return (0);
}

int	is_number(const char *num)
{
	int	i;
	int	correct;

	i = 0;
	correct = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!((num[i] >= '0' && num[i] <= '9') || num[i] == ' '))
			return (0);
		i++;
		correct = 1;
	}
	return (correct);
}

int	is_int(long int arg)
{
	if (arg > 2147483647 || arg < -2147483648)
		return (0);
	return (1);
}

int	is_valid(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!(is_number(argv[i]) && is_int(ft_atol(argv[i]))))
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(const int *arr, int arr_len)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (j < arr_len)
	{
		if (arr[i] >= arr[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}
