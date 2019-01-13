/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:17:25 by palan             #+#    #+#             */
/*   Updated: 2018/12/02 16:51:52 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

static int	count_words1(const char *s, char c)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (flag == 1 && *s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			count++;
			flag = 1;
		}
		s++;
	}
	return (count);
}

static int	get_word_len1(const char *s, char c)
{
	int	len;

	len = 0;
	while ((*s != c) && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		words_counter;

	i = 0;
	if (!s)
		return (NULL);
	words_counter = count_words1((const char*)s, c);
	if ((arr = (char**)malloc(sizeof(char*) * (words_counter + 1))) == NULL)
		return (NULL);
	while (words_counter--)
	{
		while (*s == c && *s)
			s++;
		arr[i] = ft_strsub((const char*)s, 0, get_word_len1((const char*)s, c));
		if (arr[i] == NULL)
		{
			ft_free2darr(arr, i);
			return (NULL);
		}
		s += get_word_len1(s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
