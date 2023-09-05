/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:02:54 by zhedlund          #+#    #+#             */
/*   Updated: 2023/09/05 14:26:47 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// counts how many words in string

static int	wordcount(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

// creates substring with the words

static char	*substring(const char *s, size_t len)
{
	char 	*substr;
	size_t	i;
	
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

//splits string into separate arrays

char	**ft_split(const char *s, char c)
{
	char	**words;
	int		index;
	int		len;

	index = 0;
	words = malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!words)
		return (NULL);	
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			words[index++] = substring(s, len);
			s += len;
		}
	}
	words[index] = NULL;
	return (words);
}

/*#include <stdio.h>
int	main(void)

{
	char	*str1 = "2 6 4 7";
	char	**res = ft_split(str1, ' ');	
	int i = 0;

	while (res[i] != NULL)
	{
		printf("%s\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}
*/