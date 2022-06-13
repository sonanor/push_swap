/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:38:13 by adratini          #+#    #+#             */
/*   Updated: 2022/02/15 15:38:14 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	treat_min_values(t_struct *list, int *size)
{
	if (list->stack_a->index == list->min_sort)
		push_down(list);
	else if (list->stack_b->index == list->min_sort)
	{
		push(list, 'a', 1);
		push_down(list);
		(*size)--;
	}
	else if (list->stack_a->next->index == list->min_sort)
	{
		swap(list, 'a', 1);
		push_down(list);
	}
}

void	secondary_sorting(t_struct *list)
{
	int	stack_size;

	stack_size = list->size_b;
	get_median(list, 'b');
	while (stack_size-- > 0)
	{
		treat_min_values(list, &stack_size);
		if (!list->stack_b)
			break ;
		if (list->stack_b && list->stack_b->index > list->med)
		{
			list->stack_b->flag++;
			push(list, 'a', 1);
		}
		else
		{
			if (list->stack_b)
			{
				list->stack_b->flag++;
				rotate(list, 'b', 1);
			}
		}
	}
}
