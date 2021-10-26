/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4_large_set_algo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:56:23 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 15:03:11 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//return the index of what should be the position of the first item of a in b
//= distance to head so that a can be pushed in the right spot
int	position_goal(t_stack *stack)
{
	t_list	tmp_b;
	t_list	*ptr_b;
	int		i;

	tmp_b = *(stack->b);
	ptr_b = &tmp_b;
	i = 0;
	if (!ptr_b)
		return (-1);
	while (ptr_b->next)
	{
		if (ptr_b->index > ptr_b->next->index)
		{
			if (stack->a->index < ptr_b->index \
					&& stack->a->index > ptr_b->next->index)
				return (i + 1);
		}
		else
			if ((stack->a->index < ptr_b->index) \
					|| (stack->a->index > ptr_b->next->index))
				return (i + 1);
		ptr_b = ptr_b->next;
		i++;
	}
	return (0);
}

// prepare stack b so first item in a is ready to be pushed
// not used in insertion sort because seg fault, why ? 
// Used in push_subset_to_b()
void	set_to_position(int path_to_top, t_stack *stack)
{
	int	path_to_bottom;
	int	direction;

	if (stack->b && stack->b->next)
	{
		path_to_bottom = size(&stack->b) - path_to_top;
		direction = path_to_top - path_to_bottom;
		if (size(&stack->b) >= 2 && path_to_top != -1)
		{
			while (direction <= 0 && path_to_top--)
				rotate(stack, STACK_B);
			while (direction > 0 && path_to_bottom--)
				reverse_rotate(stack, STACK_B);
		}
	}
}

// insert first item in a in the right position within items of stack b
void	insertion_sort(t_stack *stack)
{
	if (stack->b && stack->b->next)
		set_to_position(position_goal(stack), stack);
	push(&stack->a, &stack->b, STACK_B);
	if (size(&stack->b) == 2 && stack->b->index < stack->b->next->index)
		swap(stack, STACK_B);
}

// insert into b every item which index is within a specified range, 
// each item is inserted at its right order in b
void	push_subset_to_b(t_stack *stack, int start_set, int end_set)
{
	int	i;

	i = end_set - start_set + 1;
	start_set = ind_min(stack->a);
	end_set = start_set + i - 1;
	while (stack->a && i)
	{
		if (stack->a->index >= start_set && stack->a->index <= end_set)
		{
			insertion_sort(stack);
			i--;
		}
		else
			rotate(stack, STACK_A);
	}
	set_to_position(position(index_max(stack->b), stack->b), stack);
}

// push all existing items in b into stack a
void	push_back_to_a(t_stack *stack)
{
	int	i;

	i = size(&stack->b);
	while (i--)
		push(&stack->b, &stack->a, STACK_A);
}

// int     position_goal(t_stack *stack) 
// {
//     t_list  tmp_b;
//     t_list  *ptr_b;
//     int     i;

//     tmp_b = *(stack->b);
//     ptr_b = &tmp_b;
//     i = 0;
//     if (!ptr_b)
//         return (-1);
//     while (ptr_b->next)
//     {
//         /*normal*/
//         if (ptr_b->index > ptr_b->next->index)
//         {
//             // if within b and b->next
//             if (stack->a->index < ptr_b->index  && 
//             stack->a->index > ptr_b->next->index)
//                 return (i + 1);
//         }
//         /*roll-over*/
//         else
//             // if > max or < min
//             if ((stack->a->index < ptr_b->index) 
//             || (stack->a->index > ptr_b->next->index))
//                 return (i + 1);
//         ptr_b = ptr_b->next;
//         i++;
//     }
//     // if value > head and < tail
//     return (0);
// }
