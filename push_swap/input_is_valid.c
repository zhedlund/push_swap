/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:55:47 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/08 16:59:49 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

// checks if input between quotation marks are valid

int check_quoted_input(char **argv)
{
    int i;
	
	i = 0;
    while (argv[1][i])
    {
		if (argv[1][i] == '+' || argv[1][i] == '-')
		{
			if (!ft_isdigit(argv[1][i + 1]))
				return (0);
			if (i == 0 && ft_isdigit(argv[1][i + 1]))
				i++;
			if (argv[1][i - 1] == ' ' && ft_isdigit(argv[1][i + 1]))
				i++;
		}
		if (argv[1][i] == ' ' && ft_isdigit(argv[1][i + 1]) && i != 0)
			i++;
		else if (argv[1][i] == ' ' && (argv[1][i + 1] == '+' || argv[1][i + 1] == '-'))
			i++;
   	    else if (!ft_isdigit(argv[1][i]))
       	    return (0);
		else
        	i++;
    }
    return (1);
}

//checks if input are digits, + and - only allowed in beginning of arg

int input_is_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				if (j != 0)
					return (0);
				if (!ft_isdigit(argv[i][j + 1]))
					return (0);
				j++;
			}
			else if (!ft_isdigit(argv[i][j])) 
				return (0);
			j++; 
		}
	i++;
	}
	return (1);
}


/*int main(int argc, char **argv)
{
	if (argc == 2)    
    	printf("%d\n", check_quoted_input(argv));
	else if (argc < 2)
		printf("Too few arguments");
	else
		printf("%d\n", input_is_valid(argc, argv));
    return 0;
}*/
