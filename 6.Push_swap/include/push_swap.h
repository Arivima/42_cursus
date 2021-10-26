/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:09:52 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 16:50:14 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//INCLUDES
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

//DEFINES
# define ERROR_MALLOC 1
# define ERROR_INPUT_FORMAT 2
# define ERROR_DUPLICATES 3
# define ERROR_MALLOC_MSG "\n\nError\nAllocation failed\n\n"
# define ERROR_INPUT_FORMAT_MSG "\n\nError\nInvalid input format\n\n"
# define ERROR_DUPLICATES_MSG "\n\nError\nThere are duplicates\n\n"

# define INT_MX 2147483647

# define STACK_A 1
# define STACK_B 2
# define BOTH_STACKS 3
# define MSG_SA "sa\n"
# define MSG_SB "sb\n"
# define MSG_SS "ss\n"
# define MSG_RA "ra\n"
# define MSG_RB "rb\n"
# define MSG_RR "rr\n"
# define MSG_RRA "rra\n"
# define MSG_RRB "rrb\n"
# define MSG_RRR "rrr\n"
# define MSG_PA "pa\n"
# define MSG_PB "pb\n"

//STRUCTURES
typedef struct s_list
{
	int				n;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	int		error;
	int		i;
}				t_stack;

//MAIN
void	init_stacks(t_stack *stack);
void	parsing_input(char **av, t_stack *stack);
void	set_index_check_duplicates(t_stack *stack);
void	run_algorithm(t_stack *stack);

//PARSING (& ERROR MANAGEMENT)
int		my_atoi(const char *str, t_stack *stack);
void	error(int err_msg, t_stack *stack);

//INIT, SET, CHECK INPUT
void	bubble_sort_stack(t_list **b);
void	check_duplicates(t_list *b, t_stack *stack);
void	set_index(t_list *a, t_list *b);
int		check_order(t_list *list);

//ALGO
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	large_set_algo(t_stack *stack);

//LARGE SET ALGO - UTILS
int		position_goal(t_stack *stack);
void	set_to_position(int path_to_top, t_stack *stack);
void	insertion_sort(t_stack *stack);
void	push_subset_to_b(t_stack *stack, int start, int end);
void	push_back_to_a(t_stack *stack);

//LIST - UTILS
int		size(t_list **a);
int		subset(float size);
int		ind_min(t_list *list);
int		index_max(t_list *list);
int		position(int ind, t_list *list);

//INSTRUCTIONS
void	swap(t_stack *stack, int option);
void	rotate(t_stack *stack, int option);
void	reverse_rotate(t_stack *stack, int option);
void	push(t_list **a, t_list **b, int option);

//INSTRUCTIONS LIST
void	swap_list(t_list **a);
void	rotate_list(t_list **a);
void	reverse_rotate_list(t_list **a);

//LIST MANAGEMENT_1
t_list	*create_element(int n, int index);
t_list	*go_to_end(t_list *list);
t_list	*go_to_top(t_list *list);
int		append_element(t_list **head, int n, int index);
void	remove_element(t_list *elem);
//LIST MANAGEMENT_2
void	delete_list(t_list **list);

#endif
