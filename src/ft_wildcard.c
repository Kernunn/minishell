#include "wildcard_utils.h"
#include "libft.h"
#include <stdlib.h>
#include "ft_match.h"
#include "ft_list_remove_if.h"
#include "remove_hidden.h"

static void	remove_list(t_list **list, t_list **prev, t_list **lst)
{
	t_list	*next;

	next = (*lst)->next;
	if (*prev == NULL)
		*list = next;
	else
		(*prev)->next = next;
	ft_lstdelone(*lst, free);
}

static void	add_list(t_list **list, t_list **prev, t_list **temp, t_list **lst)
{
	t_list	*next;

	next = (*lst)->next;
	if ((*prev) == NULL)
		*list = *temp;
	else
		(*prev)->next = *temp;
	*prev = ft_list_last(*temp);
	(*prev)->next = next;
	*temp = NULL;
	ft_lstdelone(*lst, free);
}

static void	ft_change_list(t_list **list, char c)
{
	t_list	*next;
	t_list	*lst;
	char	*pwd;
	t_list	*prev;
	t_list	**temp;

	temp = malloc(sizeof(t_list*));
	*temp = NULL;
	prev = NULL;
	lst = *list;
	while (lst)
	{
		next = lst->next;
		pwd = ft_strjoin(lst->content, "/");
		if (ft_get_all_files(temp, pwd, c))
			remove_list(list, &prev, &lst);
		else if (c)
			add_list(list, &prev, temp, &lst);
		else
			prev = lst;
		lst = next;
		free(pwd);
	}
	free(temp);
}

static void	ft_strjoin_free(char **pwd, char *add)
{
	char	*temp_pwd;

	temp_pwd = *pwd;
	*pwd = ft_strjoin(temp_pwd, add);
	free(temp_pwd);
}

char		*expantion_stars(char *str_star, t_list **list_files, int i)
{
	char	*pwd;
	char	*temp;
	char	*src;

	src = ft_change_pwd_until_star(str_star, &pwd);
	ft_get_all_files(list_files, pwd, 1);
	while (src[i])
	{
		temp = ft_change_str_match(src + i);
		i = i + ft_strlen(temp);
		ft_strjoin_free(&pwd, temp);
		ft_list_remove_if(list_files, pwd, match);
		ft_list_remove_if(list_files, temp, remove_hidden);
		if (src[i] == '/')
		{
			ft_strjoin_free(&pwd, "/");
			ft_change_list(list_files, src[++i]);
		}
		else if (src[i] != '\0')
			i++;
		free(temp);
	}
	free(pwd);
	free(src);
	return (ft_list_to_str_with_spaces(list_files));
}
