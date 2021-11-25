#include "libft.h"

t_list	*create_element(int n, int index)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->prev = NULL;
	elem->next = NULL;
	elem->n = n;
	elem->index = index;
	return (elem);
}

t_list	*go_to_end(t_list *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

t_list	*go_to_top(t_list *list)
{
	while (list->prev)
		list = list->prev;
	return (list);
}

int	append_element(t_list **head, int n, int index)
{
	t_list	*list_tmp;

	list_tmp = *head;
	if (!*head)
	{
		*head = create_element(n, index);
		if (!(*head))
			return (-1);
		else
			return (0);
	}
	list_tmp = go_to_end(list_tmp);
	list_tmp->next = create_element(n, index);
	list_tmp->next->prev = list_tmp;
	if (!list_tmp->next)
		return (-1);
	else
		return (0);
}

void	remove_element(t_list *elem)
{
	if (elem->prev)
		elem->prev->next = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	free(elem);
}

void	delete_list(t_list **list)
{
	t_list	*list_tmp;

	while (*list)
	{
		list_tmp = *list;
		*list = (*list)->next;
		list_tmp->prev = 0;
		list_tmp->next = 0;
		list_tmp->index = 0;
		list_tmp->n = 0;
		free(list_tmp);
	}
}

int	size(t_list **a)
{
	int		i;
	t_list	*tmp;

	tmp = *a;
	if (!tmp)
		return (0);
	else
	{
		i = 1;
		while (tmp->next)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

int	ind_min(t_list *list)
{
	t_list	tmp;
	t_list	*ptr;
	int		min;

	tmp = *list;
	ptr = &tmp;
	min = ptr->index;
	while (ptr)
	{
		if (min > ptr->index)
			min = ptr->index;
		ptr = ptr->next;
	}
	return (min);
}

//return the current position of a the highest number in a specified stack
int	index_max(t_list *list)
{
	t_list	tmp;
	t_list	*ptr;
	int		max;

	tmp = *list;
	ptr = &tmp;
	max = ptr->index;
	while (ptr)
	{
		if (max < ptr->index)
			max = ptr->index;
		ptr = ptr->next;
	}
	return (max);
}

void	bubble_sort_stack(t_list **b)
{
	int		tmp;
	t_list	*head;
	int		flag;

	head = *b;
	flag = 1;
	while (flag)
	{
		flag = 0;
		while ((*b)->next)
		{
			if ((*b)->n > (*b)->next->n)
			{
				tmp = (*b)->n;
				(*b)->n = (*b)->next->n;
				(*b)->next->n = tmp;
				flag = 1;
			}
			(*b) = (*b)->next;
		}
		*b = head;
	}
}