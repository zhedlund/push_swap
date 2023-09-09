/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:53:01 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/07 15:32:54 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
