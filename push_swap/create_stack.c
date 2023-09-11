/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:53:01 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/11 15:24:36 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if input between quotation marks are valid

int check_quoted_input(char **argv)
{
    int i;
	
	i = 0;
    while (argv[1][i])
    {
		if (argv[1][i] == '+' || argv[1][i] == '-')
		{
			if (!ft_isdigit(argv[1][i + 1]))
				return (0);
			if (i == 0 && ft_isdigit(argv[1][i + 1]))
				i++;
			if (argv[1][i - 1] == ' ' && ft_isdigit(argv[1][i + 1]))
				i++;
		}
		if (argv[1][i] == ' ' && ft_isdigit(argv[1][i + 1]) && i != 0)
			i++;
		else if (argv[1][i] == ' ' && (argv[1][i + 1] == '+' || argv[1][i + 1] == '-'))
			i++;
   	    else if (!ft_isdigit(argv[1][i]))
       	    return (0);
		else
        	i++;
    }
    return (1);
}

//checks if input are digits, + and - only allowed in beginning of arg

int input_is_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				if (j != 0)
					return (0);
				if (!ft_isdigit(argv[i][j + 1]))
					return (0);
				j++;
			}
			else if (!ft_isdigit(argv[i][j])) 
				return (0);
			j++; 
		}
	i++;
	}
	return (1);
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