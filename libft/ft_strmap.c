/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:49:18 by palan             #+#    #+#             */
/*   Updated: 2018/11/29 20:06:39 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	new_str = (char*)malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	while (*s && (i < len))
	{
		new_str[i] = f(*s);
		s++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
