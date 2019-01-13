/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:00:35 by palan             #+#    #+#             */
/*   Updated: 2018/12/04 10:48:50 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_str;

	if (size == (size_t)-1)
		return (NULL);
	new_str = (char*)malloc(sizeof(char) * (size + 1));
	if (new_str == NULL)
		return (NULL);
	ft_memset(new_str, 0, size + 1);
	return (new_str);
}
