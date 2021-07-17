#include "../includes/scene.h"

t_objects_lst	*ft_lstnew2(void *content)
{
	t_objects_lst *new;

	new = (t_objects_lst *)malloc(sizeof(t_objects_lst));
	if (new)
	{
		new->object = content;
		new->next = NULL;
	}
	return (new);
}
