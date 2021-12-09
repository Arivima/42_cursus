/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:04:49 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 14:39:09 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac > 1)
	{
		init_stacks(&stack);
		parsing_input(av, &stack);
		if (stack.error != -1)
			set_index_check_duplicates(&stack);
		if (stack.error != -1)
			run_algorithm(&stack);
		delete_list(&stack.a);
		delete_list(&stack.b);
	}
	return (0);
}
