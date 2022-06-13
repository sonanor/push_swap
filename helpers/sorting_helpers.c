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

void	get_median(t_struct *list, char stack_char)
{
	int		min;
	int		max;
	int		med;
	int		i;
	t_node	*stack;

	stack = identify_stack(list, stack_char);
	i = get_size(list, stack_char);
	min = stack->index;
	max = stack->index;
	while (i-- > 0)
	{
		if (stack->index < min)
			min = stack->index;
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	med = (min + max) / 2;
	list->min = min;
	list->med = med;
}

void	push_down(t_struct *list)
{
	list->stack_a->flag = -1;
	rotate(list, 'a', 1);
	list->min_sort++;
}

void	sort_last_tree(t_struct *list, char stack_char, int flag)
{
	if (list->stack_b->index == list->min_sort)
	{
		push(list, 'a', 1);
		push_down(list);
	}
	else if (list->stack_a->index == list->min_sort)
		push_down(list);
}

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
