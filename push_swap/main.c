/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:44:43 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/18 20:18:36 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**split_result;

	stack_a = NULL;
	split_result = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	else if ((argc > 2 && !input_is_valid(argc, argv))
		|| (argc == 2 && !check_quoted_input(argv)))
		exit_error();
	if (argc == 2)
	{
		split_result = ft_split(argv[1], ' ');
		create_stack(&stack_a, split_result, argc == 2);
		free(split_result);
	}
	else
		create_stack(&stack_a, argv + 1, argc == 2);
	if (!stack_is_sorted(stack_a))
		sort_stack(&stack_a);
	free_stack(&stack_a);
	return (0);
}
