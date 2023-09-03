/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zandrahedlund <zandrahedlund@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:44:43 by zhedlund          #+#    #+#             */
/*   Updated: 2023/08/30 18:35:39 by zandrahedlu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	bool	flag_argv;

	stack_a = NULL;
	flag_argv = false;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	else if ((!input_is_valid(argc, argv)) || !check_quoted_input(argv))
		exit_error();
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' '); // create argv copy in heap - must be freed!
		flag_argv = true;
	}
	create_stack(&stack_a, argv + 1, flag_argv); // initialize stack a, argv+1 to exclude program name, flag to free temp argv later
	if (!stack_is_sorted(stack_a)) // check if stack is sorted
		sort_stack(stack_a); // choose sorting operation
	free_stack(&stack_a);
	return (0);
}
