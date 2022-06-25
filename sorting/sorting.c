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

void	sort_stack(t_struct *list)
{
	if (list->size_a <= 3)
		sort_three_nums(list, 'a');
	else if (list->size_a <= 5)
		sort_five_nums(list);
	else
	{
		do_primary_sorting(list);
		do_secondary_sorting(list);
	}
}

void do_secondary_sorting(t_struct *list)
{
	get_max_value(list);
	while (list->size_b > 0)
	{
		if (list->stack_b->index == list->max)
		{
			push(list, 'a', 1);
			list->max--;
		}
		else if (list->stack_b->prev->index == list->max)
		{
			r_rotate(list, 'b', 1);
			push(list, 'a', 1);
			list->max--;
		}
		else
			scroll_stack(list);
	}
}

void do_primary_sorting(t_struct *list)
{
	int range;

	range = determine_range(list->size_a);
	while (list->size_a != 0)
	{
		if (list->stack_a->index <= list->min_sort)
		{
			push(list, 'b', 1);
			list->min_sort++;
		}
		else if (list->stack_a->index <= list->min_sort + range)
		{
			push(list, 'b', 1);
			rotate(list, 'b', 1);
			list->min_sort++;
		}
		else
			rotate(list, 'a', 1);
	}
}