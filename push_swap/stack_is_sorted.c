/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:57:35 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/07 15:26:48 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if stack is sorted

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
