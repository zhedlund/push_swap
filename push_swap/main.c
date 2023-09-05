/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:44:43 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/05 17:16:46 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void print_stack(t_stack *stack)
{
    t_stack *current = stack;

    while (current != NULL)
    {
        printf("%d ", current->number); // Assuming 'number' is the data you want to print
        current = current->next;
    }

    printf("\n"); // Add a newline for better formatting
}


int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	bool	flag_argv;
	 char **split_result = NULL;

	stack_a = NULL;
	flag_argv = false;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	//else if (!check_quoted_input(argv)) //(!input_is_valid(argc, argv))
		//exit_error();
	printf("argv1: %c\n", *argv[1]);
	if (argc == 2)
	{
		printf("test1\n");
		//argv = ft_split(argv[1], ' '); // creates argv copy in heap - must be freed!
		split_result = ft_split(argv[1], ' '); 
        if (split_result) {
            for (int i = 0; split_result[i]; i++) {
                printf("split_result[%d]: %s\n", i, split_result[i]);
            }
        } else {
            printf("ft_split returned NULL\n");
        }
		printf("test2\n");
		flag_argv = true;
	}
	printf("test3\n");

	if (flag_argv)
    {
        printf("split_result before create_stack:\n");
        for (int i = 0; split_result[i]; i++)
        {
            printf("split_result[%d]: %s\n", i, split_result[i]);
        }
        create_stack(&stack_a, split_result, flag_argv);
		printf("Elements stack a: ");
		print_stack(stack_a);
    }
    else
    {
        create_stack(&stack_a, split_result, flag_argv);
		printf("Stack a: ");
		print_stack(stack_a);
    }
	
	//create_stack(&stack_a, argv + 1, flag_argv); // initialize stack a, argv+1 to exclude program name, flag to free temp argv later
	printf("test4\n");
	if (!stack_is_sorted(stack_a)) // check if stack is sorted
	{
		printf("test5\n");
		sort_stack(&stack_a); // choose sorting operation
	}
	printf("test6\n");
	free_stack(&stack_a);
	return (0);
}
