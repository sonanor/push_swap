/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:34:35 by adratini          #+#    #+#             */
/*   Updated: 2022/02/15 15:34:36 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_size(t_struct *list, char stack_char)
{
	if (stack_char == 'a')
		return (list->size_a);
	return (list->size_b);
}

t_node	*identify_stack(t_struct *list, char stack_char)
{
	if (stack_char == 'a')
		return (list->stack_a);
	else
		return (list->stack_b);
}

char	opposite_stack(char stack_char)
{
	if (stack_char == 'a')
		return ('b');
	return ('a');
}

void	free_stack(t_struct *list)
{
	t_node	*tmp;

	while (list->size_a--)
	{
		tmp = list->stack_a->next;
		free(list->stack_a);
		list->stack_a = NULL;
		list->stack_a = tmp;
	}
	while (list->size_b--)
	{
		tmp = list->stack_b->next;
		free(list->stack_b);
		list->stack_b = NULL;
		list->stack_b = tmp;
	}
	free(list);
	exit(0);
}
