/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zandrahedlund <zandrahedlund@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:41:20 by zandrahedlu       #+#    #+#             */
/*   Updated: 2023/08/30 20:47:18 by zandrahedlu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack **head)
{
    t_stack *second_node;
    int size;
    
    size = stack_size(*head);
    if (!head || !*head || size == 1)
        return ;
    second_node = (*head)->next;
    (*head)->next = second_node->next; // Adjust pointers to swap nodes
    if (second_node->next)
        second_node->next->prev = *head;
    second_node->prev = NULL;
    second_node->next = *head;
    (*head)->prev = second_node;
    *head = second_node;
}

void    sa(t_stack **stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}

void    sb(t_stack **stack_b)
{
    swap(stack_b);
    write(1, "sb\n", 3);
}

void    ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "sa\n", 3);
}