/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:07:31 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 14:56:14 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->a->n > stack->a->next->n)
		swap(stack, STACK_A);
}

void	sort_three(t_stack *stack)
{
	int		x;
	int		y;
	char	rank[2];

	rank[0] = 1 + (stack->a->n > stack->a->next->n) + \
			(stack->a->n > stack->a->next->next->n);
	rank[1] = 1 + (stack->a->next->n > stack->a->n) + \
			(stack->a->next->n > stack->a->next->next->n);
	x = 1 - rank[0];
	y = 2 - rank[1];
	if (x || (x + y))
	{
		if (x == -1 && x + y == 0)
			swap(stack, STACK_A);
		else if (x == -2)
			rotate(stack, STACK_A);
		else
			reverse_rotate(stack, STACK_A);
		sort_three(stack);
	}
}

// push items from a to b by subset, items are push in the right order in b, 
//there might be some remains in a at the end of the function, that are dealt
//with in the parent function
void	large_set_algo(t_stack *stack)
{
	int	a_len;
	int	n;
	int	i;

	a_len = size(&stack->a);
	n = subset(a_len);
	i = -1;
	while ((i + 1 + n) <= a_len)
	{
		push_subset_to_b(stack, i + 1, i + n);
		i += n;
	}
}
