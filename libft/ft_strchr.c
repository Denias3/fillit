/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:58:21 by palan             #+#    #+#             */
/*   Updated: 2018/11/28 11:40:35 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char *ret;

	ret = (char *)s;
	while (*ret != c)
	{
		if (*ret == '\0')
			return (NULL);
		ret++;
	}
	if (*ret == c)
		return (ret);
	return (ret);
}
