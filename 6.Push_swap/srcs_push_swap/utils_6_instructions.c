/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:08:28 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 16:39:28 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, int option)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	a = (stack->a && stack->a->next);
	b = (stack->b && stack->b->next);
	if (option == STACK_A && a)
	{
		swap_list(&stack->a);
		ft_putstr_fd(MSG_SA, 1);
	}
	else if (option == STACK_B && b)
	{
		swap_list(&stack->b);
		ft_putstr_fd(MSG_SB, 1);
	}
	else if (option == BOTH_STACKS && a && b)
	{
		swap_list(&stack->a);
		swap_list(&stack->b);
		ft_putstr_fd(MSG_SS, 1);
	}
}

void	rotate(t_stack *stack, int option)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	a = (stack->a && stack->a->next);
	b = (stack->b && stack->b->next);
	if (option == STACK_A && a)
	{
		rotate_list(&stack->a);
		ft_putstr_fd(MSG_RA, 1);
	}
	else if (option == STACK_B && b)
	{
		rotate_list(&stack->b);
		ft_putstr_fd(MSG_RB, 1);
	}
	else if (option == BOTH_STACKS && a && b)
	{
		rotate_list(&stack->a);
		rotate_list(&stack->b);
		ft_putstr_fd(MSG_RR, 1);
	}
}

void	reverse_rotate(t_stack *stack, int option)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	a = (stack->a && stack->a->next);
	b = (stack->b && stack->b->next);
	if (option == STACK_A && a)
	{
		reverse_rotate_list(&stack->a);
		ft_putstr_fd(MSG_RRA, 1);
	}
	else if (option == STACK_B && b)
	{
		reverse_rotate_list(&stack->b);
		ft_putstr_fd(MSG_RRB, 1);
	}
	else if (option == BOTH_STACKS && a && b)
	{
		reverse_rotate_list(&stack->a);
		reverse_rotate_list(&stack->b);
		ft_putstr_fd(MSG_RRR, 1);
	}
}

void	push(t_list **src, t_list **dst, int option)
{
	t_list	*tmp;

	if (*src)
	{
		append_element(dst, (*src)->n, (*src)->index);
		if ((*dst)->next)
			reverse_rotate_list(dst);
		tmp = (*src)->next;
		remove_element(*src);
		*src = tmp;
		if (option == STACK_A)
			ft_putstr_fd(MSG_PA, 1);
		else if (option == STACK_B)
			ft_putstr_fd(MSG_PB, 1);
	}
}
