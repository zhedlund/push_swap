/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:53:01 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/05 16:39:58 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    create_stack(t_stack **stack_a, char **argv, bool flag_argv)
{
    long    number;
    int     i;

    i = 0;
    printf("inside create stack\n");
    while (argv[i])
		{
			number = ft_atol(argv[i]);
			if (number < INT_MIN || number > INT_MAX)
                error_free(stack_a, argv, flag_argv);
            if (check_dup(*stack_a, (int)number))
                error_free(stack_a, argv, flag_argv);
            stack_add_node(stack_a, (int)number);
			++i;
		}
     printf("inside create stack 2\n");
        //if (flag_argv)
            //free_array(av);
}
