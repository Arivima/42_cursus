/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7_instruction_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:08:52 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 16:40:33 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_list(t_list **a)
{
	t_list	*list;
	int		n;
	int		index;

	list = *a;
	n = list->n;
	index = list->index;
	list->n = list->next->n;
	list->index = list->next->index;
	list->next->n = n;
	list->next->index = index;
}

void	rotate_list(t_list **a)
{
	t_list	*list;
	t_list	*head;

	head = *a;
	list = (*a)->next;
	list->prev = NULL;
	list = go_to_end(list);
	head->prev = list;
	list->next = head;
	head->next = NULL;
	*a = go_to_top(list);
}

void	reverse_rotate_list(t_list **a)
{
	t_list	*end;

	end = go_to_end(*a);
	end->prev->next = NULL;
	end->prev = NULL;
	(*a)->prev = end;
	end->next = (*a);
	(*a) = end;
}
