/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:37:15 by zandrahedlu       #+#    #+#             */
/*   Updated: 2023/09/07 15:26:08 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_stack(t_stack **stack_a)
{
    t_stack *stack_b;

    stack_b = NULL;
    if (stack_size(*stack_a) == 2)
        sa(stack_a);
    else if (stack_size(*stack_a) == 3)
        sort_three(stack_a);
    else
        push_swap(stack_a, &stack_b);
}