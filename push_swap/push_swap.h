/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zandrahedlund <zandrahedlund@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:44:55 by zhedlund          #+#    #+#             */
/*   Updated: 2023/08/30 20:50:59 by zandrahedlu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stddef.h>
# include <stdbool.h>

typedef struct s_stack
{
    int             number;
    int             current_position;
    int             cost;
    bool            top_half;
    bool            lowest_cost;
    struct	s_stack	*next;
	struct	s_stack	*prev;
}   t_stack;

//input check
int	check_quoted_input(char **argv);
int	input_is_valid(int argc, char **argv);
int	check_dup(t_stack *stack_a, int num);
//t_stack	*process_input(int argc, char **argv);
//t_stack	*process_quoted_input(char **argv);

//utils
int		ft_atol(const char *str);
void	exit_error(void);
void	free_array(char **argv);
void	free_stack(t_stack **stack);
void    error_free(t_stack **stack_a, char **argv, bool flag_argv);
char	**ft_split(const char *s, char c);

//stack utils
void    create_stack(t_stack **stack_a, char **argv, bool flag_argv);
int		stack_size(t_stack *stack);
t_stack	*stack_new_node(int content);
int		stack_is_sorted(t_stack *stack);
t_stack	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *node);

//operations
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);


#endif
