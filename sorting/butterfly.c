/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:39:32 by adratini          #+#    #+#             */
/*   Updated: 2022/07/02 16:39:33 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	determine_range(int stack_size)
{
	if (stack_size == 100)
		return (15);
	else
		return (30);
}

void	get_max_value(t_struct *list)
{
	int		max;
	int		size;
	t_node	*tmp;

	max = 0;
	size = list->size_b;
	tmp = list->stack_b;
	while (size-- > 0)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	list->max = max;
}

void	scroll(t_struct *list, int depth, void (*f)(t_struct *, char, int))
{
	while (depth > 0)
	{
		(*f)(list, 'b', 1);
		depth--;
	}
}

void	scroll_stack(t_struct *list)
{
	int		depth;
	t_node	*tmp_top;
	t_node	*tmp_bottom;

	depth = 1;
	tmp_top = list->stack_b->next;
	tmp_bottom = list->stack_b->prev->prev;
	while (tmp_top->index != list->max && tmp_bottom->index != list->max)
	{
		tmp_top = tmp_top->next;
		tmp_bottom = tmp_bottom->prev;
		depth++;
	}
	if (tmp_top->index == list->max)
		scroll(list, depth, rotate);
	else if (tmp_bottom->index == list->max)
		scroll(list, depth, r_rotate);
}
