/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:37:13 by adratini          #+#    #+#             */
/*   Updated: 2022/02/15 15:37:15 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**create_args_arr(int argc, char **argv)
{
	int		i;
	char	**list;
	char	*str;

	i = 1;
	str = new_str();
	if (!str)
		return (NULL);
	if (argc == 2)
		list = ft_split(argv[1], ' ');
	else
	{
		while (i < argc)
		{
			str = ft_strjoin(ft_strjoin(str, argv[i]), " ");
			i++;
		}
		list = ft_split(str, ' ');
	}
	free(str);
	return (list);
}

int	*create_integers_array(char **str_num)
{
	int		*arr;
	size_t	len;
	int		i;

	i = 0;
	len = count_array_length(str_num);
	arr = (int *) malloc(sizeof(int) * (len));
	if (!arr)
	{
		free_char_array(str_num);
		return (NULL);
	}
	while (str_num[i])
	{
		arr[i] = ft_atoi(str_num[i]);
		i++;
	}
	return (arr);
}

int	*sort_arr(int *arr, int arr_len)
{
	int	i;
	int	j;
	int	tmp;
	int	*sorted_arr;

	i = 0;
	sorted_arr = copy_arr(arr, arr_len);
	while (i < arr_len)
	{
		j = 0;
		while (j < arr_len - 1)
		{
			if (sorted_arr[j] > sorted_arr[j + 1])
			{
				tmp = sorted_arr[j];
				sorted_arr[j] = sorted_arr[j + 1];
				sorted_arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sorted_arr);
}

int	*sort_argv_array(int *not_sorted_array, int array_length)
{
	int	*sorted_array;

	sorted_array = NULL;
	if (!is_sorted(not_sorted_array, array_length))
	{
		sorted_array = sort_arr(not_sorted_array, array_length);
		if (duplicates(sorted_array, array_length))
		{
			free(not_sorted_array);
			free(sorted_array);
			massage_error();
		}
	}
	else
	{
		free(not_sorted_array);
		exit(1);
	}
	return (sorted_array);
}

int	*parse_args(int argc, char **argv, int *array_length)
{
	char	**argv_char_array;
	int		*not_sorted_array;

	argv_char_array = create_args_arr(argc, argv);
	not_sorted_array = create_integers_array(argv_char_array);
	(*array_length) = count_array_length(argv_char_array);
	free_char_array(argv_char_array);
	return (not_sorted_array);
}
