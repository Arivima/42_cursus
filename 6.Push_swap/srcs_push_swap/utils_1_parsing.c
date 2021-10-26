/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:06:50 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 14:49:18 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_atoi(const char *str, t_stack *stack)
{
	long int	x;
	int			is_neg;

	while (*str == '\t' || *str == '\n' || *str == '\v' \
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	is_neg = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_neg = -1;
		str++;
	}
	x = 0;
	while (*str >= '0' && *str <= '9' && *str)
	{
		x = (x * 10) + (*str++ - 48);
	}
	if (*str || (is_neg == 1 && x > INT_MX) || (is_neg == -1 && x - 1 > INT_MX))
	{
		error(ERROR_INPUT_FORMAT, stack);
		return (0);
	}
	return (x * is_neg);
}

void	error(int err_msg, t_stack *stack)
{
	if (err_msg == ERROR_DUPLICATES)
		ft_putstr_fd(ERROR_DUPLICATES_MSG, 2);
	if (err_msg == ERROR_INPUT_FORMAT)
		ft_putstr_fd(ERROR_INPUT_FORMAT_MSG, 2);
	if (err_msg == ERROR_MALLOC)
		ft_putstr_fd(ERROR_MALLOC_MSG, 2);
	stack->error = -1;
}
