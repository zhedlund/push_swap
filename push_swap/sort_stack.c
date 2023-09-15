/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:37:15 by zandrahedlu       #+#    #+#             */
/*   Updated: 2023/09/14 13:51:25 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
*   checks for highest number in stack and returns pointer to
*   node w highest number. INT_MIN used as placeholder, to make
*   sure no number is smaller than initial value
*/

static t_stack	*find_max_value(t_stack *stack)
{
	int		max_value;
	t_stack	*max_node;

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
*   If top node is biggest: ra (biggest to bottom)
*   else if 2nd node is biggest: rra (brings biggest to bottom)
*   check the top two, if smallest is 2nd: sa (swap top 2)
*/

void	sort_three(t_stack **stack_a)
{
	t_stack	*max_value;

	max_value = find_max_value(*stack_a);
	if (*stack_a == max_value)
		ra(stack_a);
	else if ((*stack_a)->next == max_value)
		rra(stack_a);
	if ((*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
}

void	sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (stack_size(*stack_a) == 2)
		sa(stack_a);
	else if (stack_size(*stack_a) == 3)
		sort_three(stack_a);
	else
		push_swap(stack_a, &stack_b);
}
