/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:35:32 by adratini          #+#    #+#             */
/*   Updated: 2022/02/15 15:35:34 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*create_new_list(int index)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if (!list)
		return (NULL);
	list->index = index;
	list->flag = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_struct	*create_struct(int array_length)
{
	t_struct	*stack;

	stack = malloc(sizeof(t_struct));
	if (!stack)
		return (NULL);
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->size_a = array_length;
	stack->size_b = 0;
	stack->min = 0;
	stack->med = 0;
	stack->max = 0;
	stack->min_sort = 0;
	return (stack);
}

void	list_add_back(t_node **stack_a, t_node *new)
{
	t_node	*head;

	head = *stack_a;
	if (head)
	{
		if (head->prev)
		{
			head->prev->next = new;
			new->prev = head->prev;
			new->next = head;
			head->prev = new;
		}
		else
		{
			head->prev = new;
			head->next = new;
			new->prev = head;
			new->next = head;
		}
	}
	else
		*stack_a = new;
}

void	create_stack(t_struct *stack, int *index_array, int array_length)
{
	int	i;

	i = 0;
	while (i < array_length)
	{
		list_add_back(&stack->stack_a, create_new_list(index_array[i]));
		i++;
	}
	free(index_array);
}

t_struct	*initialize_stack(int argc, char **argv)
{
	int			*raw_argv_array;
	int			*sorted_argv_array;
	int			*index_arr;
	int			array_length;
	t_struct	*stack;

	array_length = 0;
	raw_argv_array = parse_args(argc, argv, &array_length);
	sorted_argv_array = sort_argv_array(raw_argv_array, array_length);
	index_arr = create_index_arr(sorted_argv_array, raw_argv_array, \
	array_length);
	stack = create_struct(array_length);
	if (!stack)
	{
		free(index_arr);
		return (NULL);
	}
	create_stack(stack, index_arr, array_length);
	return (stack);
}
