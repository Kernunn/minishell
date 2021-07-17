#include "libft.h"
#include <stdlib.h>
#include <dirent.h>
#include "ft_getcwd.h"
#include "sort.h"

t_list	*ft_list_last(t_list *begin_list)
{
	if (begin_list)
	{
		while (begin_list->next)
			begin_list = begin_list->next;
	}
	return (begin_list);
}

int		ft_get_all_files(t_list **list, char *pwd, char c)
{
	DIR				*d;
	char			*content;
	struct dirent	*dir;
	char			*temp_pwd;

	temp_pwd = ft_getcwd();
	if (pwd[0] == '\0')
		d = opendir(temp_pwd);
	else
		d = opendir(pwd);
	free(temp_pwd);
	if (d)
	{
		while ((dir = readdir(d)) != NULL && c)
		{
			content = ft_strdup(dir->d_name);
			ft_lstadd_back(list, ft_lstnew(ft_strjoin(pwd, content)));
			free(content);
		}
		closedir(d);
		return (0);
	}
	return (1);
}

char	*ft_list_to_str_with_spaces(t_list **lst)
{
	char	*str;
	char	*prev_str;
	t_list	*list;

	prev_str = ft_strdup("");
	ft_list_sort(lst, ft_alphabet_strcmp);
	list = *lst;
	while (list)
	{
		str = ft_strjoin(prev_str, list->content);
		free(prev_str);
		prev_str = str;
		list = list->next;
		if (list)
		{
			prev_str = ft_strjoin(str, " ");
			free(str);
		}
	}
	ft_lstclear(lst, free);
	return (prev_str);
}

char	*ft_change_pwd_until_star(char *path, char **pwd)
{
	int		i;
	int		k;
	char	*change_path;

	i = 0;
	k = 0;
	while (path[i])
	{
		if (path[i] == '/')
			k = 0;
		else
		{
			if (path[i] == '*')
				break ;
			k++;
		}
		i++;
	}
	k = path[i] == '\0' ? 0 : k;
	if ((*pwd = malloc(i - k + 1)) == NULL)
		exit(1);
	ft_strlcpy(*pwd, path, i - k + 1);
	if ((change_path = ft_strdup(path + i - k)) == NULL)
		exit(1);
	return (change_path);
}

char	*ft_change_str_match(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] && str[i] != '/')
		i++;
	res = malloc(i + 1);
	if (res == NULL)
		exit(1);
	ft_strlcpy(res, str, i + 1);
	return (res);
}
