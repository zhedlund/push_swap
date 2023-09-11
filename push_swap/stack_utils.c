/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:55:57 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/11 15:35:02 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_last(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

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

int	stack_size(t_stack *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

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

int	stack_is_sorted(t_stack *stack_a)
{
	int	prev_value;
	
	if (!stack_a)
		return (1);
	prev_value = stack_a->number;
	while (stack_a)
	{
		if (prev_value > stack_a->number)
			return (0);
		prev_value = stack_a->number;
		stack_a = stack_a->next;
	}
	return (1);
}
