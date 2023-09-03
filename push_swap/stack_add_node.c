/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zandrahedlund <zandrahedlund@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:13:56 by zandrahedlu       #+#    #+#             */
/*   Updated: 2023/08/30 18:20:10 by zandrahedlu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stack_add_node(t_stack **stack, int num)
{
    t_stack *node;
    t_stack *last_node;

    if (!stack)
        return ;
    node = malloc(sizeof(t_stack));
    if (!node)
        return ;
    node->next = NULL;
    node->number = num;
    if (!*stack)
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = stack_last(*stack);
        last_node -> next = node;
        node->prev = last_node;
    }
}