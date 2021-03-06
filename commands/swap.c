/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:33:21 by adratini          #+#    #+#             */
/*   Updated: 2022/02/15 15:33:22 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_struct *list, char stack_char, int is_writable)
{
	int		tmp;
	t_node	*stack;

	stack = identify_stack(list, stack_char);
	if (get_size(list, stack_char) < 2)
		return ;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
	if (is_writable)
		write_cmd(stack_char, 's');
}
