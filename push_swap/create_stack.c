/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:53:01 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/11 14:51:50 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	num;
	int	sign;
	int	i;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * sign);
}

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

void    create_stack(t_stack **stack_a, char **argv, bool flag_argv)
{
    long    num;
    int     i;

    i = 0;
    while (argv[i])
		{
			num = ft_atol(argv[i]);
			if (num < INT_MIN || num > INT_MAX)
                error_free(stack_a, argv, flag_argv);
            if (check_dup(*stack_a, (int)num))
                error_free(stack_a, argv, flag_argv);
            stack_add_node(stack_a, (int)num);
			i++;
		}
        if (flag_argv)
            free(argv);
}

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