/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:38:17 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/11 16:14:40 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* moves bottom node to top of stack */

static void reverse_rotate(t_stack **stack)
{
    t_stack *last_node;
    int size;
    
    size = stack_size(*stack);
    if (!stack || (!*stack) || size <= 1)
        return ;
    last_node = stack_last(*stack);
    last_node->prev->next = NULL;
    last_node->next = *stack;
    last_node->prev = NULL;
    *stack = last_node;
    last_node->next->prev = last_node;
}

void    rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    write (1, "rra\n", 4);
}

void    rrb(t_stack **stack_b)
{
    reverse_rotate(stack_b);
    write (1, "rrb\n", 4);
}

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    write (1, "rrr\n", 4);
}