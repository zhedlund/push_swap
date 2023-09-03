/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zandrahedlund <zandrahedlund@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:23:14 by zhedlund          #+#    #+#             */
/*   Updated: 2023/08/30 16:45:07 by zandrahedlu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks for duplicate number input

int	check_dup(t_stack *stack_a, int num)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->number == num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
