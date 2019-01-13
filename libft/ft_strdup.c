/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:18:41 by palan             #+#    #+#             */
/*   Updated: 2018/11/27 11:17:27 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dupl;
	char	*tmp;
	int		len;

	len = ft_strlen(s);
	dupl = (char*)malloc(sizeof(char) * (len + 1));
	if (dupl == NULL)
		return (NULL);
	tmp = dupl;
	while (*s)
		*tmp++ = *s++;
	*tmp = '\0';
	return (dupl);
}
