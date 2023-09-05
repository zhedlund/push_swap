/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:23:13 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/04 20:57:22 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
*   checks for highest number in stack and returns pointer to
*   node w highest number. INT_MAX used as placeholder, to make
*   sure no number is smaller than init value
*/

static t_stack  *find_max_value(t_stack *stack)
{
    int max_value;
    t_stack *max_node;

    max_value = INT_MIN; 
    while (stack)
    {
        if (stack->number > max_value)
        {
            max_value = stack->number;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}

/* 
*   If first node is biggest: ra (biggest to bottom)
*   else if 2nd node is biggest: rra (biggest to bottom)
*   check the top two, if smallest is 2nd: sa (swap top 2)
*/

void    sort_three(t_stack **stack_a)
{
    t_stack *max_value;
    
    max_value = find_max_value(*stack_a);
    if (*stack_a == max_value)
        ra(stack_a);
    else if ((*stack_a)->next == max_value)
        rra(stack_a);
    if ((*stack_a)->number > (*stack_a)->next->number)
        sa(stack_a);
}