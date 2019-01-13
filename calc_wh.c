/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:18:01 by emeha             #+#    #+#             */
/*   Updated: 2018/12/20 13:18:57 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		calc_wh_alg(t_tetr *elem)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		if (elem->x != -1)
			break ;
		while (j < 4)
		{
			if (elem->data[j][i] == 1)
			{
				elem->x = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void			calc_wh(t_tetr *elem)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		if (elem->y != -1)
			break ;
		while (j < 4)
		{
			if (elem->data[i][j] == 1)
			{
				elem->y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	calc_wh_alg(elem);
}
