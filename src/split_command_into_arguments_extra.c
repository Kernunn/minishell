#include "t_token.h"
#include "libft.h"
#include <stdlib.h>

char	**str_to_argv(t_token *token)
{
	char **argv;

	if (token->type == WORD)
	{
		if (!(argv = ft_split(token->str, ' ')))
			exit(1);
		if (*argv == NULL)
		{
			free(argv);
			return (NULL);
		}
	}
	else
	{
		if (!(argv = malloc(sizeof(char*) * 2)))
			exit(1);
		*argv = token->str;
		*(argv + 1) = NULL;
		token->str = NULL;
	}
	return (argv);
}

char	**merge_array(char **first, char **second)
{
	char	**new_array;
	int		count1;
	int		count2;

	count1 = 0;
	count2 = 0;
	while (first[count1])
		count1++;
	while (second[count2])
		count2++;
	if (!(new_array = malloc(sizeof(char*) * (count1 + count2 + 1))))
		exit(1);
	new_array[count1 + count2] = NULL;
	while (count2--)
		new_array[count1 + count2] = second[count2];
	while (count1--)
		new_array[count1] = first[count1];
	free(first);
	return (new_array);
}

void	add_new_arguments(char ***argv, t_token *token, int *space)
{
	char	**new_arguments;

	if (*argv == NULL)
	{
		if (!(*argv = malloc(sizeof(char*))))
			exit(1);
		**argv = NULL;
	}
	new_arguments = str_to_argv(token);
	if (new_arguments == NULL)
		return ;
	*argv = merge_array(*argv, new_arguments);
	free(new_arguments);
	*space = 0;
}

void	join_to_old_arg(char ***argv, t_token *token, int *space)
{
	char	**new_arguments;
	int		last_element;
	char	*tmp;

	last_element = 0;
	while ((*argv)[last_element + 1])
		last_element++;
	new_arguments = str_to_argv(token);
	if (new_arguments == NULL)
		return ;
	tmp = ft_strjoin((*argv)[last_element], new_arguments[0]);
	free((*argv)[last_element]);
	free(new_arguments[0]);
	(*argv)[last_element] = tmp;
	*argv = merge_array(*argv, new_arguments + 1);
	free(new_arguments);
	*space = 0;
}
