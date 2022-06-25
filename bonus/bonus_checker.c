
#include "bonus_checker.h"



int validate(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (!is_valid(argv, argc))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

char	**get_commands(char **commands)
{
	char *line;
	char *result;

	result = new_str();

	while (get_next_line(0, &line))
	{
		result = ft_strjoin(ft_strjoin(result, line), " ");
		free(line);
	}

	commands = ft_split(result, ' ');
	return commands;
}

void execute_commands(char **commands, t_struct *checker_struct)
{
	int i;
//	int j;

	i = 0;
//	j = 0;
	while(commands[i])
	{
		if (!ft_strcmp(commands[i], "sa"))
			swap(checker_struct, 'a', 0);
		else if (!ft_strcmp(commands[i], "sb"))
			swap(checker_struct, 'b', 0);
		else if (!ft_strcmp(commands[i], "pa"))
			push(checker_struct, 'a', 0);
		else if (!ft_strcmp(commands[i], "pb"))
			push(checker_struct, 'b', 0);
		else if (!ft_strcmp(commands[i], "ra"))
			rotate(checker_struct, 'a', 0);
		else if (!ft_strcmp(commands[i], "rb"))
			rotate(checker_struct, 'b', 0);
		else if (!ft_strcmp(commands[i], "rra"))
			r_rotate(checker_struct, 'a', 0);
		else if (!ft_strcmp(commands[i], "rrb"))
			r_rotate(checker_struct, 'b', 0);
		else
			return ;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_struct	*checker_struct;
	int			*argv_array;
	int			array_length;
	char 		**commands;

	array_length = 0;
	commands = NULL;
	if (validate(argc, argv))
	{
		argv_array = parse_args(argc, argv, &array_length);
		if (is_sorted(argv_array, array_length))
		{
			free(argv_array);
			return (0);
		}
		checker_struct = create_struct(array_length);
		if (!checker_struct)
		{
			free(argv_array);
			return (0);
		}
		create_stack(checker_struct, argv_array, array_length);
		commands = get_commands(commands);
		if (*commands != NULL)
			execute_commands(commands, checker_struct);
		if (is_sorted_stack(checker_struct, 'a') && checker_struct->size_b == 0)
			write(1, "OK", 2);
		else
			write(1, "KO", 2);
	}
	return (0);
}