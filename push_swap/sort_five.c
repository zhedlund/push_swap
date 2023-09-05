/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:08:40 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/05 01:36:43 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_five(t_stack **stack_a, t_stack **stack_b)
{
    while (stack_size(*stack_a) > 3)
    {
        init_nodes(*stack_a, *stack_b);
        rotate_to_target(stack_a, stack_smallest(*stack_a), 'a');
        pb(stack_b, stack_a);
    }
}