/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:26:37 by palan             #+#    #+#             */
/*   Updated: 2018/11/28 11:39:57 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;
	unsigned char uns_c;

	ptr = (unsigned char *)b;
	uns_c = (unsigned char)c;
	while (len--)
		*ptr++ = uns_c;
	return (b);
}
