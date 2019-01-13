/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:46:55 by palan             #+#    #+#             */
/*   Updated: 2018/11/28 11:39:15 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	calc_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		count;
	char	*number;

	count = calc_len(n);
	if (n == 2147483647 || n == 0)
		return (n == 0 ? ft_strdup("0") : ft_strdup("2147483647"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(number = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	number[count] = '\0';
	if (n < 0)
	{
		n *= -1;
		number[0] = '-';
	}
	while (n > 0 && (count-- > -1))
	{
		number[count] = n % 10 + '0';
		n /= 10;
	}
	return (number);
}
