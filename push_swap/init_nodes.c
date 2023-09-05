/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:56:28 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/05 00:55:06 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    set_current_position(t_stack *stack)
{
    int i;
    int middle;

    i = 0;
    if (!stack)
        return ;
    middle = stack_size(stack) / 2;
    while (stack)
    {
        stack->current_position = i;
        if (i <= middle)
            stack->top_half = true;
        else
            stack->top_half = false;
        stack = stack->next;
        i++;
    }
}

/*every node in b gets a target node in a. best match is the next bigger number.
*  if no node is bigger, best match is the smallest.
* LONG_MAX is placeholder, to make sure it's not interfering w numbers
*  in stack from the start
*/

void set_target_node(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *node_a;
    t_stack *target_node;
    long    best_match_index;

    while (stack_b)
    {
        best_match_index = LONG_MAX;
        node_a = stack_a;
        while (node_a)
        {
            if (node_a->number > stack_b->number && node_a->number < best_match_index)
            {
                best_match_index = node_a->number;
                target_node = node_a;
            }
            node_a = node_a->next;
        }
        if (LONG_MAX == best_match_index)
            stack_b->target_node = stack_smallest(stack_a);
        else
            stack_b->target_node = target_node;
        stack_b = stack_b->next;
    }
}

/* sets the cost of pushing the node from b to a, aka how many moves.
* Checks for relative position in stack for every node, calculates
* the cost for each node.
*/

void    set_cost_to_push(t_stack *stack_a, t_stack *stack_b)
{
    int a_size;
    int b_size;

    a_size = stack_size(stack_a);
    b_size = stack_size(stack_b);
    while (stack_b)
    {
        stack_b->cost_to_push = stack_b->current_position;
        if (!(stack_b->top_half))
            stack_b->cost_to_push = b_size - (stack_b->current_position);
        if (stack_b->target_node->top_half)
            stack_b->cost_to_push += stack_b->target_node->current_position;
        else
            stack_b->cost_to_push += a_size - (stack_b->target_node->current_position);
        stack_b = stack_b->next;
    }
}

/* flags the node with the lowest cost */

void    set_lowest_cost(t_stack *stack_b)
{
    long    best_match_number;
    t_stack *best_match_node;

    if (!stack_b)
        return ;
    best_match_number = LONG_MAX;
    while (stack_b)
    {
        if (stack_b->cost_to_push < best_match_number)
        {
            best_match_number = stack_b->cost_to_push;
            best_match_node = stack_b;
        }
        stack_b = stack_b->next;
    }
    best_match_node->lowest_cost = true;
}

void    init_nodes(t_stack *stack_a, t_stack *stack_b)
{
    set_current_position(stack_a);
    set_current_position(stack_b);
    set_target_node(stack_a, stack_b);
    set_cost_to_push(stack_a, stack_b);
    set_lowest_cost(stack_b);
}