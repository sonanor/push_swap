/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:38:07 by adratini          #+#    #+#             */
/*   Updated: 2022/02/15 15:38:08 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	treat_lower_values(t_struct *list)
{
	if (list->stack_b->index == list->min_sort)
	{
		list->stack_b->flag = -1;
		if (list->size_b > 1)
			rotate(list, 'b', 1);
	}
}

void	move_sorted(t_struct *list)
{
	while (list->stack_b && list->stack_b->prev->flag == -1 && list->size_b > 1)
		r_rotate(list, 'b', 1);
	while (list->stack_b && list->stack_b->flag == -1)
	{
		push(list, 'a', 1);
		push_down(list);
	}
	if (list->stack_b && list->stack_b->index == list->min_sort)
	{
		list->stack_b->flag = -1;
		move_sorted(list);
	}
}

void	primary_sorting(t_struct *list)
{
	int	i;

	i = list->size_a;
	while (i-- > 0 && list->stack_a->flag != -1)
	{
		if (list->stack_a->index <= list->med)
		{
			push(list, 'b', 1);
			treat_lower_values(list);
		}
		else
			rotate(list, 'a', 1);
	}
	move_sorted(list);
}
