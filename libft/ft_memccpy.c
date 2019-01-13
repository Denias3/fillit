/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:16:09 by palan             #+#    #+#             */
/*   Updated: 2018/11/26 14:00:31 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *dst_ptr;
	unsigned char *src_ptr;
	unsigned char uns_c;

	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	uns_c = (unsigned char)c;
	while (n--)
	{
		if (*src_ptr == uns_c)
		{
			*dst_ptr++ = *src_ptr++;
			return (dst_ptr);
		}
		*dst_ptr++ = *src_ptr++;
	}
	return (NULL);
}
