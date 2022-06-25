/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:33:39 by adratini          #+#    #+#             */
/*   Updated: 2022/02/15 15:33:40 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate(t_struct *list, char stack_char, int is_writable)
{
	if (get_size(list, stack_char) > 1)
	{
		if (stack_char == 'a')
			list->stack_a = list->stack_a->next;
		else
			list->stack_b = list->stack_b->next;
	}
	if (is_writable)
		write_cmd(stack_char, 'r');
}