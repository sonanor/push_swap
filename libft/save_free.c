#include "libft.h"

void	save_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}