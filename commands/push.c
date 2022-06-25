/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:33:02 by adratini          #+#    #+#             */
/*   Updated: 2022/02/15 15:33:04 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b(t_struct *list)
{
	t_node	*tmp;

	tmp = list->stack_a;
	list->stack_a = tmp->next;
	list->stack_a->prev = tmp->prev;
	list->stack_a->prev->next = list->stack_a;
	if (list->stack_b)
	{
		list->stack_b->prev->next = tmp;
		tmp->prev = list->stack_b->prev;
		tmp->next = list->stack_b;
		list->stack_b->prev = tmp;
		list->stack_b = tmp;
	}
	else
	{
		list->stack_b = tmp;
		tmp->next = list->stack_b;
		tmp->prev = list->stack_b;
	}
}

void	push_a(t_struct *list)
{
	t_node	*tmp;

	tmp = list->stack_b;
	list->stack_b = tmp->next;
	list->stack_b->prev = tmp->prev;
	list->stack_b->prev->next = list->stack_b;
	if (list->stack_a)
	{
		list->stack_a->prev->next = tmp;
		tmp->prev = list->stack_a->prev;
		tmp->next = list->stack_a;
		list->stack_a->prev = tmp;
		list->stack_a = tmp;
	}
	else
	{
		list->stack_a = tmp;
		tmp->next = list->stack_a;
		tmp->prev = list->stack_a;
	}
}

void push(t_struct *list, char dst_stack, int is_writable)
{
	int		src_size;
	char	src_stack_char;

	src_stack_char = opposite_stack(dst_stack);
	src_size = get_size(list, src_stack_char);
	if (src_size == 0)
		return ;
	if (dst_stack == 'b')
	{
		push_b(list);
		if (list->size_a == 1)
			list->stack_a = NULL;
		list->size_a--;
		list->size_b++;
	}
	if (dst_stack == 'a')
	{
		push_a(list);
		if (list->size_b == 1)
			list->stack_b = NULL;
		list->size_a++;
		list->size_b--;
	}
	if (is_writable)
		write_cmd(dst_stack, 'p');
}
