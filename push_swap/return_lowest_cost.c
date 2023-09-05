/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_lowest_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 00:21:05 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/05 00:25:23 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* returns lowest_cost_node that was flagged in set_lowest_cost */

t_stack *return_lowest_cost(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack)
    {
        if (stack->lowest_cost)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}