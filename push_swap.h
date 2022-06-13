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
	int				flag;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_struct
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		min;
	int 	max;
	int		med;
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
char		opposite_stack(char stack_char);
void		push(t_struct *list, char dst_stack, int writable);
void		rotate(t_struct *list, char stack_char, int writable);
void		rr(t_struct *list, int writable);
void		swap(t_struct *list, char stack_char, int writable);
void		ss(t_struct *list, int writable);
void		r_rotate(t_struct *list, char stack_char, int writable);
void		rrr(t_struct *list, int writable);
void		get_median(t_struct *list, char stack_char);
void		push_down(t_struct *list);
void		sort_stack(t_struct *list);
void		sort_three_nums(t_struct *list, char stack_char);
void		free_stack(t_struct *list);
void		primary_sorting(t_struct *list);
void		sort_five_b(t_struct *list);
void		secondary_sorting(t_struct *list);
void		sort_five_a(t_struct *list);
void		sort_last_tree(t_struct *list, char stack_char, int flag);
int			is_sorted_stack(t_struct *list, char stack_char);
void		sort_next_chunk(t_struct *list);
int			*sort_arr(int *arr, int arr_len);
int			*copy_arr(int *arr, int arr_len);
int			*create_index_arr(int *sorted_arr, int *row_arr, int arr_len);
void	sort_five(t_struct *list);
void create_butterfly(t_struct *list);
void	sort_butterfly(t_struct *list);

#endif
