/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:15:14 by palan             #+#    #+#             */
/*   Updated: 2018/11/26 14:40:31 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *tmp;

	tmp = dest;
	while (*src && n)
	{
		*tmp++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*tmp++ = '\0';
		n--;
	}
	return (dest);
}
