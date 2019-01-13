/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:39:56 by emeha             #+#    #+#             */
/*   Updated: 2018/12/20 15:59:17 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		remove_elem_from_matrix(char **matrix, t_tetr *elem)
{
	int		i;
	int		j;
	int		ch;

	ch = 0;
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == elem->name)
			{
				if (!ch)
				{
					elem->state = 0;
					ch = 1;
				}
				matrix[i][j] = '.';
			}
			j++;
		}
		i++;
	}
	return (ch);
}

void	calc_next_tetr_pos(t_tetr *elem, char **matrix)
{
	if (elem->g_x + 1 == M_SIZE(matrix[0]) &&
			elem->g_y + 1 == M_SIZE(matrix[0]))
	{
		elem->g_x = 0;
		elem->g_y = 0;
		return ;
	}
	if (elem->g_x + 1 == M_SIZE(matrix[0]))
	{
		elem->g_y++;
		elem->g_x = 0;
		return ;
	}
	elem->g_x++;
}

int		count_dots(char **matrix)
{
	int i;
	int j;
	int	count;

	count = 0;
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '.')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int		is_placed(char **matrix, t_tetr *elem)
{
	int i;
	int j;

	i = 0;
	if (elem == NULL)
		return (0);
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == elem->name)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
