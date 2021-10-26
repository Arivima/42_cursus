/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:03:35 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 16:30:09 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// return a calculated subset depending on a specified size
// square rrot from ourcodeworld.com
int	subset(float size)
{
	int		subset;
	float	temp;
	float	sqrt;

	subset = 0;
	sqrt = size / 2;
	temp = 0;
	if (size >= 7)
	{
		while (sqrt != temp)
		{
			temp = sqrt;
			sqrt = (size / temp + temp) / 2;
		}
		subset = sqrt * 2;
	}
	return (subset);
}

//return the current position of a the lowest number in a specified stack
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

//return the current position of a specified number in a specified stack
int	position(int ind, t_list *list)
{
	t_list	tmp;
	t_list	*ptr;
	int		i;

	tmp = *list;
	ptr = &tmp;
	i = 0;
	while (ptr)
	{
		if (ind == ptr->index)
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (-1);
}
