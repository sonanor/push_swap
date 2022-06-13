#include "../push_swap.h"

//int determine_range(int stack_size)
//{
//
//}
//

void	sort_butterfly(t_struct *list)
{
	while (list->size_b != 0)
	{
		if (list->stack_b->index == list->max)
		{
			push(list, 'a', 1);
			list->max--;
		}
		else if (list->stack_b->prev->index == list->max)
		{
			r_rotate(list, 'b',1);
			push(list, 'a', 1);
			list->max--;
		}
	}
}

void get_min_max(t_struct *list)
{
	int	min;
	int max;
	int size;

	size = get_size(list, 'a');
	while (size-- > 0)
	{
		if (list->stack_a->index < min)
			min = list->stack_a->index;
		if (list->stack_a->index > max)
			max = list->stack_a->index;
		list->stack_a = list->stack_a->next;
	}
	list->min = min;
	list->max = max;
}

void create_butterfly(t_struct *list)
{
//	int	n;
//
//	n = determine_range
//	int	i;
//
//	i = 0;
	get_min_max(list);
	while (list->size_a != 0)
	{
		if (list->stack_a->index <= list->min_sort)
		{
			push(list, 'b', 1);
			list->min_sort++;
		}
		else if (list->stack_a->index <= list->min_sort + 1)
		{
			push(list, 'b', 1);
			rotate(list, 'b', 1);
			list->min_sort++;
		}
		else
			rotate(list, 'a', 1);
//		i++;
	}
}

