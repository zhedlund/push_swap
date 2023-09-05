/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_smallest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 00:10:12 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/05 01:39:57 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stack_smallest(t_stack *stack)
{
    long    smallest;
    t_stack *smallest_node;

    if (!stack)
        return (NULL);
    smallest = LONG_MAX;
    while (stack)
    {
        if (stack->number < smallest)
        {
            smallest = stack->number;
            smallest_node = stack;
        }
        stack = stack->next;
    }
    return (smallest_node);
}