/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:18:38 by palan             #+#    #+#             */
/*   Updated: 2018/12/12 16:25:00 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	char	*tmp;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	new_str = ft_strnew(len);
	if (new_str == NULL)
		return (NULL);
	while (start--)
		i++;
	if (len > i + ft_strlen(s))
		return (NULL);
	tmp = new_str;
	while (len--)
	{
		*tmp++ = s[i];
		i++;
	}
	return (new_str);
}
