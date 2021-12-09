/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_9_list_mgt_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:42:40 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 16:43:14 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
