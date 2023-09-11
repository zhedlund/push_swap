/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:44:55 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/11 16:08:50 by zhedlund         ###   ########.fr       */
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
    int             cost_to_push;
    bool            top_half;
    bool            lowest_cost;
    struct  s_stack *target_node;
    struct	s_stack	*next;
	struct	s_stack	*prev;
}   t_stack;

/* input check */
int     check_dup(t_stack *stack_a, int num);
int     check_quoted_input(char **argv);
int     input_is_valid(int argc, char **argv);

/* algorithm */
void    push_swap(t_stack **stack_a, t_stack **stack_b);
void    sort_stack(t_stack **stack_a);
void    sort_three(t_stack **stack_a);

/* stack initialization */
void    create_stack(t_stack **stack_a, char **argv, bool flag_argv);
void    init_nodes(t_stack *stack_a, t_stack *stack_b);
void    set_cost_to_push(t_stack *stack_a, t_stack *stack_b);
void    set_current_position(t_stack *stack);
void    set_lowest_cost(t_stack *stack_b);
void    set_target_node(t_stack *stack_a, t_stack *stack_b);

/* operations */
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_b, t_stack **stack_a);
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);

/* error handling & free */
void    error_free(t_stack **stack_a, char **argv, bool flag_argv);
void	exit_error(void);
void	free_array(char **argv);
void	free_stack(t_stack **stack);

/* stack utils */
t_stack *return_lowest_cost(t_stack *stack);
void    stack_add_node(t_stack **stack, int num);
int		stack_is_sorted(t_stack *stack_a);
t_stack	*stack_last(t_stack *node);
int     stack_size(t_stack *stack);
t_stack *stack_smallest(t_stack *stack);

/* utils */
long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);
int     ft_isdigit(char c);

#endif
