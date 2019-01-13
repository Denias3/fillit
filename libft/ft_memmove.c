/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:04:52 by palan             #+#    #+#             */
/*   Updated: 2018/11/29 18:06:38 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned const char	*src_tmp;
	unsigned char		*dst_tmp;

	dst_tmp = dst;
	src_tmp = src;
	if (dst > src)
	{
		while (len--)
		{
			dst_tmp[len] = src_tmp[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
