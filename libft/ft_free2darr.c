/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2darr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:52:07 by palan             #+#    #+#             */
/*   Updated: 2018/12/02 16:53:59 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free2darr(char **ar, int len)
{
	int i;

	i = -1;
	while (++i < len)
		ft_strdel(&ar[i]);
	free(ar);
	ar = NULL;
}
