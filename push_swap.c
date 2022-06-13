/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:02:02 by adratini          #+#    #+#             */
/*   Updated: 2022/01/30 16:02:04 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_struct	*stack;

	if (argc == 1)
		return (0);
	if (!is_valid(argv, argc))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack = initialize_stack(argc, argv);
//	sort_stack(stack);
	create_butterfly(stack);
	sort_butterfly(stack);
//	int i = 0;
//	while (i < stack->size_a)
//	{
//		printf("%d", stack->stack_a->index);
//		stack->stack_a = stack->stack_a->next;
//		i++;
//	}
	free_stack(stack);
}
