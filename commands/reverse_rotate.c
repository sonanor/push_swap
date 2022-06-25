/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:33:13 by adratini          #+#    #+#             */
/*   Updated: 2022/02/15 15:33:15 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void r_rotate(t_struct *list, char stack_char, int is_writable)
{
	if (get_size(list, stack_char) > 1)
	{
		if (stack_char == 'a')
			list->stack_a = list->stack_a->prev;
		else
			list->stack_b = list->stack_b->prev;
	}
	if (is_writable)
		write_cmd(stack_char, 'v');
}
