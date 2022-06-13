/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:38:20 by adratini          #+#    #+#             */
/*   Updated: 2022/02/15 15:38:22 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_next_chunk(t_struct *list)
{
	int	flag;

	flag = list->stack_a->flag;
	if (!is_sorted_stack(list, 'a'))
	{
		while (list->stack_a->flag != -1 && list->stack_a->flag == flag)
		{
			if (list->stack_a->index == list->min_sort)
				push_down(list);
			else
				push(list, 'b', 1);
		}
	}
}

void	sort_stack(t_struct *list)
{
	get_median(list, 'a');
	if (list->size_a < 6)
	{
		sort_five(list);
		free_stack(list);
		exit(0);
	}
	primary_sorting(list);
	while (!(is_sorted_stack(list, 'a')) || list->size_b > 0)
	{
		if (list->stack_b && list->size_b < 6)
		{
			sort_five_b(list);
			sort_next_chunk(list);
		}
		else if (list->size_b >= 6)
			secondary_sorting(list);
		if (list->size_b == 0)
		{
			sort_five_a(list);
			sort_next_chunk(list);
		}
	}
}

void	sort_five(t_struct *list)
{
	while (list->size_a > 3)
	{
		if (list->stack_a->index == 1 || list->stack_a->index == 2)
			push(list, 'b', 1);
		else
			rotate(list, 'a', 1);
	}
	sort_three_nums(list, 'a');
	if (is_sorted_stack(list, 'b'))
		swap(list, 'b', 1);
	push(list, 'a', 1);
	push(list, 'a', 1);
}
