/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:58:44 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/11 15:21:24 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *lowest_cost_node)
{
    while (*stack_a != lowest_cost_node->target_node && *stack_b != lowest_cost_node)
        rr(stack_a, stack_b);
    set_current_position(*stack_a);
    set_current_position(*stack_b);
}

static void reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *lowest_cost_node)
{
    while (*stack_a != lowest_cost_node->target_node && *stack_b != lowest_cost_node)
        rrr(stack_a, stack_b);
    set_current_position(*stack_a);
    set_current_position(*stack_b);
}

/* rotate until node with lowest cost to push is on top*/

static void    rotate_to_target(t_stack **stack, t_stack *lowest_cost_node, char stack_name)
{
    while (*stack != lowest_cost_node)
    {
        if (stack_name == 'a')
        {
            if (lowest_cost_node->top_half)
                ra(stack);
            else
                rra(stack);
        }
        else if (stack_name == 'b')
        {
            if (lowest_cost_node->top_half)
                rb(stack);
            else
                rrb(stack);
        }
    }
}

/*
* push all nodes into b, one at a time, choosing the node with lowest_cost
* then push everything back to a in order. if smallest number is in top_half
* of stack: rotate, else: reverse rotate.
* Step 1: make target node come to top of stack B
* step 2: push to A
*/

static void rotate_and_push(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *lowest_cost_node;
    
    lowest_cost_node = return_lowest_cost(*stack_b);
    if (lowest_cost_node->top_half && lowest_cost_node->target_node->top_half)
        rotate_both(stack_a, stack_b, lowest_cost_node);
    else if (!(lowest_cost_node->top_half) && !(lowest_cost_node->target_node->top_half))
        reverse_rotate_both(stack_a, stack_b, lowest_cost_node);
    rotate_to_target(stack_b, lowest_cost_node, 'b');
    rotate_to_target(stack_a, lowest_cost_node->target_node, 'a');
    pa(stack_a, stack_b);
}

void    push_swap(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *smallest;
    int a_size;

    a_size = stack_size(*stack_a);
    while (a_size-- > 3)
        pb(stack_b, stack_a);
    sort_three(stack_a);
    while (*stack_b)
    {
        init_nodes(*stack_a, *stack_b);
        rotate_and_push(stack_a, stack_b);
    }
    set_current_position(*stack_a);
    smallest = stack_smallest(*stack_a);
    if (smallest->top_half)
        while (*stack_a != smallest)
            ra(stack_a);
    else
        while (*stack_a != smallest)
            rra(stack_a);
}