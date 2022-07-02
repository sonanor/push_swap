/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:05:23 by adratini          #+#    #+#             */
/*   Updated: 2022/01/30 16:05:25 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_struct
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		max;
	int		min_sort;
	int		size_a;
	int		size_b;
}	t_struct;

int			*parse_args(int argc, char **argv, int *array_length);
int			*sort_argv_array(int *not_sorted_array, int array_length);
void		free_char_array(char **array);
int			duplicates(const int *arr, int arr_len);
void		massage_error(void);
int			count_array_length(char **array);
char		*new_str(void);
int			is_number(const char *num);
int			is_valid(char **argv, int argc);
int			is_sorted(const int *arr, int arr_len);
char		**create_args_arr(int argc, char **argv);
int			*create_integers_array(char **str_num);
t_struct	*initialize_stack(int argc, char **argv);
int			get_size(t_struct *list, char stack_char);
t_node		*identify_stack(t_struct *list, char stack_char);
void		write_cmd(char stack_char, char cmd);
int			*create_index_arr(int *sorted_arr, int *row_arr, int arr_len);
char		opposite_stack(char stack_char);
void		push(t_struct *list, char dst_stack, int is_writable);
void		rotate(t_struct *list, char stack_char, int is_writable);
void		swap(t_struct *list, char stack_char, int is_writable);
void		r_rotate(t_struct *list, char stack_char, int is_writable);
void		sort_stack(t_struct *list);
void		sort_three_nums(t_struct *list, char stack_char);
void		free_stack(t_struct *list);
int			is_sorted_stack(t_struct *list, char stack_char);
int			*sort_arr(int *arr, int arr_len);
int			*copy_arr(int *arr, int arr_len);
void		sort_five_nums(t_struct *list);
void		do_secondary_sorting(t_struct *list);
void		do_primary_sorting(t_struct *list);
int			determine_range(int stack_size);
void		get_max_value(t_struct *list);
void		scroll_stack(t_struct *list);
t_struct	*create_struct(int array_length);
void		create_stack(t_struct *stack, int *index_array, int array_length);

#endif
