/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:34:26 by adratini          #+#    #+#             */
/*   Updated: 2022/02/15 15:34:27 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted_stack(t_struct *list, char stack_char)
{
	t_node	*tmp;
	int		i;

	tmp = identify_stack(list, stack_char);
	i = 0;
	while (i < get_size(list, stack_char) - 1)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	write_cmd(char stack_char, char cmd)
{
	if (stack_char == 'a' && cmd == 's')
		write(1, "sa\n", 3);
	else if (stack_char == 'b' && cmd == 's')
		write(1, "sb\n", 3);
	else if (stack_char == 's' && cmd == 's')
		write(1, "ss\n", 3);
	else if (stack_char == 'b' && cmd == 'p')
		write(1, "pb\n", 3);
	else if (stack_char == 'a' && cmd == 'p')
		write(1, "pa\n", 3);
	else if (stack_char == 'a' && cmd == 'r')
		write(1, "ra\n", 3);
	else if (stack_char == 'b' && cmd == 'r')
		write(1, "rb\n", 3);
	else if (stack_char == 'r' && cmd == 'r')
		write(1, "rr\n", 3);
	else if (stack_char == 'a' && cmd == 'v')
		write(1, "rra\n", 4);
	else if (stack_char == 'b' && cmd == 'v')
		write(1, "rrb\n", 4);
	else if (stack_char == 'r' && cmd == 'v')
		write(1, "rrr\n", 4);
}

int	*create_index_arr(int *sorted_arr, int *row_arr, int arr_len)
{
	int	i;
	int	j;
	int	*index_array;

	i = 0;
	index_array = (int *) malloc(sizeof (int) * arr_len);
	if (!index_array)
	{
		free(sorted_arr);
		free(row_arr);
		return (NULL);
	}
	while (i < arr_len)
	{
		j = 0;
		while (row_arr[i] != sorted_arr[j])
			j++;
		index_array[i] = j;
		i++;
	}
	free(sorted_arr);
	free(row_arr);
	return (index_array);
}
