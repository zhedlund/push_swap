/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zandrahedlund <zandrahedlund@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:49:00 by zhedlund          #+#    #+#             */
/*   Updated: 2023/08/21 16:25:03 by zandrahedlu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//creates new stack node for the number

t_stack	*stack_new_node(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit_error();
	new_node->number = content;
	new_node->next = NULL;
	return (new_node);
}
