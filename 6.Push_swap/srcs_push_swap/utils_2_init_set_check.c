/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_init_set_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:07:15 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 14:53:13 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// algorithm to sort a stack, used to check 
// for duplicate and assign an index value
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

// return error if there is any duplicate in the input
void	check_duplicates(t_list *b, t_stack *stack)
{
	t_list	*tmp;

	tmp = b;
	while ((*tmp).next)
	{
		if ((*tmp).n == (*tmp).next->n)
			error(ERROR_DUPLICATES, stack);
		tmp = tmp->next;
	}
}

// assigne to each item in a an index based on
// what will be its final position when sorted
void	set_index(t_list *a, t_list *b)
{
	int		i;
	t_list	*tmp;

	while (a)
	{
		tmp = b;
		i = 0;
		while (a->n != tmp->n)
		{
			tmp = tmp->next;
			i++;
		}
		a->index = i;
		a = a->next;
	}
}

int	check_order(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while ((*tmp).next)
	{
		if ((*tmp).n > (*tmp).next->n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
