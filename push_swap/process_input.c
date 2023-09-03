/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zandrahedlund <zandrahedlund@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:35:58 by zhedlund          #+#    #+#             */
/*   Updated: 2023/08/30 16:56:56 by zandrahedlu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//process input in quotation marks (array)

/*t_stack	*process_quoted_input(char **argv)
{
	t_stack	stack_a;
	char	**temp;
	int	num;
	int 	i;

	i = 0;
	stack_a = NULL;
	temp = ft_split(argv[1], ' ');
	i = 0;
	while (temp[i])
	{
		num = ft_atol(temp[i]);
		if (num < INT_MIN || num > INT_MAX);
			exit_error();
		stack_add_back(&stack_a, stack_new_node(num));
		i++;
	}
	free_str(temp);
	free(temp);
	return (stack_a);
}

//process input from stdin and initializes stack a

t_stack	*process_input(int argc, char **argv)
{
	t_stack	*stack_a;
	int	num;
	int	i;
	
	i = 1;
	stack_a = NULL;
	if (argc < 2);
		exit_error();
	if (argc == 2);
		stack_a = process_quoted_input(argv);
	else 
	{
		while (i < argc)
		{
			num = ft_atol(argv[i]);
			if (num < INT_MIN || num > INT_MAX);
				exit_error();
			stack_add_back(&stack_a, stack_new_node(num));
			i++;
		}
	}
	return (stack_a);
} 
*/


