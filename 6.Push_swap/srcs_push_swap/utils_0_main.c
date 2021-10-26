/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:06:28 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 14:43:11 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *stack)
{
	stack->a = 0;
	stack->b = 0;
	stack->error = 0;
	stack->i = 0;
}

void	parsing_input(char **av, t_stack *stack)
{
	char	**tmp;
	char	**tmp_head;
	int		n;

	while (*(++av))
	{
		tmp = ft_split(*av, ' ');
		tmp_head = tmp;
		while (*tmp)
		{
			n = append_element(&stack->a, my_atoi(*tmp, stack), 0);
			if (n == -1)
				error(ERROR_MALLOC, stack);
			n = append_element(&stack->b, my_atoi(*tmp, stack), 0);
			if (n == -1)
				error(ERROR_MALLOC, stack);
			free(*tmp);
			*tmp = 0;
			tmp++;
		}
		tmp = tmp_head;
		free(tmp);
		tmp = 0;
	}
}

void	set_index_check_duplicates(t_stack *stack)
{
	bubble_sort_stack(&stack->b);
	check_duplicates(stack->b, stack);
	set_index(stack->a, stack->b);
	delete_list(&stack->b);
}

// will handle 2, 3, 4-6, and > 6 differently 
void	run_algorithm(t_stack *stack)
{
	int	size_a;

	if (check_order(stack->a))
	{
		while (size(&stack->a) > 6)
			large_set_algo(stack);
		size_a = size(&stack->a);
		if (size_a == 2)
			sort_two(stack);
		else if (size_a == 3)
			sort_three(stack);
		else if (size_a <= 6 && size_a >= 4)
		{
			while (size_a > 3)
			{
				if (size_a == 5 && (position(ind_min(stack->a), stack->a) == 4))
					reverse_rotate(stack, STACK_A);
				push_subset_to_b(stack, ind_min(stack->a), ind_min(stack->a));
				size_a = size(&stack->a);
			}
			sort_three(stack);
		}
		if (size(&stack->b))
			push_back_to_a(stack);
	}
}
