/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:19:14 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/08 16:31:59 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// prints "Error" on stderr and exit with exit code 1

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

//frees all elements in stack and sets pointer to NULL

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack || (!*stack))
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

//deallocates memory used by individual strings in temp array after ft_split

void	free_array(char **argv)
{
	int	i;
	
	i = -1;
	if ((!argv) || (!*argv))
		return ;
	while (*argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	error_free(t_stack **stack_a, char **argv, bool flag_argv)
{
	free_stack(stack_a);
	if (flag_argv)
		free(argv);
	write(2, "Error\n", 6);
	exit(1);
}