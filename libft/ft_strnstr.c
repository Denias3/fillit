/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:02:46 by palan             #+#    #+#             */
/*   Updated: 2018/12/02 17:19:53 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hs_pos;
	size_t	nd_pos;
	size_t	find_pos;

	nd_pos = 0;
	hs_pos = 0;
	while (haystack[hs_pos] && hs_pos < len)
	{
		find_pos = hs_pos;
		while (haystack[find_pos] == needle[nd_pos] && find_pos < len)
		{
			nd_pos++;
			find_pos++;
			if (needle[nd_pos] == '\0')
				return ((char*)(haystack + hs_pos));
		}
		find_pos = 0;
		nd_pos = 0;
		hs_pos++;
	}
	if (needle[nd_pos] == '\0')
		return ((char*)haystack);
	return (NULL);
}
