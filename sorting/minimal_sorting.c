/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimal_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:38:00 by adratini          #+#    #+#             */
/*   Updated: 2022/02/15 15:38:01 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three_nums(t_struct *list, char stack_char)
{
	int		top;
	int		second;
	int		last;
	t_node	*stack;

	stack = identify_stack(list, stack_char);
	top = stack->index;
	second = stack->next->index;
	last = stack->prev->index;
	if (top > second && top > last)
		rotate(list, stack_char);
	else if (second > top && second > last)
		r_rotate(list, stack_char);
	if (stack_char == 'a')
	{
		top = list->stack_a->index;
		second = list->stack_a->next->index;
	}
	else
	{
		top = list->stack_b->index;
		second = list->stack_b->next->index;
	}
	if (top > second)
		swap(list, stack_char);
}

void	sort_five_nums(t_struct *list)
{
	while (list->size_a > 3)
	{
		if (list->stack_a->index == 1 || list->stack_a->index == 2)
			push(list, 'b');
		else
			rotate(list, 'a');
	}
	sort_three_nums(list, 'a');
	if (is_sorted_stack(list, 'b'))
		swap(list, 'b');
	push(list, 'a');
	push(list, 'a');
}
