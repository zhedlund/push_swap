/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zandrahedlund <zandrahedlund@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:53:01 by zandrahedlu       #+#    #+#             */
/*   Updated: 2023/08/30 18:22:07 by zandrahedlu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    create_stack(t_stack **stack_a, char **argv, bool flag_argv)
{
    long    number;
    int     i;

    i = 0;
    while (argv[i])
		{
			number = ft_atol(argv[i]);
			if (number < INT_MIN || number > INT_MAX);
                error_free(stack_a, argv, flag_argv);
            if (check_dup(*stack_a, (int)number));
                error_free(stack_a, argv, flag_argv);
            stack_add_node(stack_a, (int)number);
			++i;
		}
        if (flag_argv)
            free_array(argv);
}
