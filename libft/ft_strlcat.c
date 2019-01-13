/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:31:53 by palan             #+#    #+#             */
/*   Updated: 2018/12/02 15:26:28 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_ptr;
	const char	*src_ptr;
	size_t		dst_len;
	size_t		tmp_len;

	dst_ptr = (char*)dst;
	src_ptr = src;
	tmp_len = size;
	while (tmp_len-- && *dst_ptr)
		dst_ptr++;
	dst_len = dst_ptr - dst;
	tmp_len = size - dst_len;
	if (!tmp_len)
		return (dst_len + ft_strlen(src_ptr));
	while (*src_ptr)
	{
		if (tmp_len != 1)
		{
			*dst_ptr++ = *src_ptr;
			tmp_len--;
		}
		src_ptr++;
	}
	*dst_ptr = '\0';
	return (dst_len + (src_ptr - src));
}
