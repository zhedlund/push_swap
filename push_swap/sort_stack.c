/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zandrahedlund <zandrahedlund@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:37:15 by zandrahedlu       #+#    #+#             */
/*   Updated: 2023/08/30 18:33:50 by zandrahedlu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_stack(t_stack **stack_a)
{
    t_stack *stack_b;
    int i;

    stack_b = NULL; 
    if (stack_size(stack_a) == 2)
        sa(&stack_a); // swap a
    else if (stack_size == 3)
        sort_three(&stack_a);
    else
        push_swap(&stack_a, &stack_b);
}