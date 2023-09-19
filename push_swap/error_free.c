/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:19:14 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/19 13:54:52 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	free_array(char **str)
{
	char	*s;

	if (!str || (!*str))
		return ;
	while (*str)
	{
		s = *str;
		str++;
		free(s);
	}
	*str = NULL;
}

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

void	error_free(t_stack **stack_a, char **argv, bool flag_split)
{
	free_stack(stack_a);
	if (flag_split)
		free_array(argv);
	write(2, "Error\n", 6);
	exit(1);
}
