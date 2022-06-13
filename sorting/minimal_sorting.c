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
		rotate(list, stack_char, 1);
	else if (second > top && second > last)
		r_rotate(list, stack_char, 1);
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
		swap(list, stack_char, 1);
}

void	treat_three(t_struct *list, char stack_char, int flag)
{
	t_node	*stack;

	stack = identify_stack(list, 'b');
	if (stack)
		sort_three_nums(list, 'b');
	while (list->size_b > 0)
	{
		if (list->stack_a->index > list->stack_a->next->index \
		&& list->stack_a->flag == list->stack_a->next->flag)
			swap(list, 'a', 1);
		sort_last_tree(list, stack_char, flag);
		if (list->size_b == 1)
			break ;
	}
	if (stack_char == 'b')
		while (list->stack_a->index == list->min_sort)
			push_down(list);
}

void	sort_five_b(t_struct *list)
{
	int	flag;
	int	size;

	flag = list->stack_a->flag;
	size = list->size_b;
	while (size > 3)
	{
		if (list->stack_b->index == list->min_sort)
		{
			push(list, 'a', 1);
			push_down(list);
		}
		else if (list->stack_a->index == list->min_sort)
			push_down(list);
		else
			push(list, 'a', 1);
		size--;
	}
	if (list->size_b <= 3)
		treat_three(list, 'b', flag);
}

void	sort_five_a(t_struct *list)
{
	t_node	*tmp;
	int		flag;
	int		size;

	flag = list->stack_a->flag;
	tmp = list->stack_a;
	size = 0;
	while (tmp->flag == flag && flag != -1)
	{
		tmp = tmp->next;
		size++;
	}
	if (size <= 5 && size != 0)
	{
		while (size > 2)
		{
			if (list->stack_a->index == list->min_sort)
				push_down(list);
			else
				push(list, 'b', 1);
			size--;
		}
		treat_three(list, 'a', flag);
	}
}
