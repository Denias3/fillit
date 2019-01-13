/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:22:24 by emeha             #+#    #+#             */
/*   Updated: 2018/12/26 17:12:44 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		basic_valid_check(char *tetr)
{
	int size;
	int dot;
	int hash;
	int newl;

	hash = 0;
	dot = 0;
	newl = 0;
	size = 20;
	while (size != -1)
	{
		if (tetr[size] == '.')
			dot++;
		if (tetr[size] == '#')
			hash++;
		if (tetr[size] == '\n')
			newl++;
		size--;
	}
	if (dot == 12 && hash == 4 && newl == 4)
		return (1);
	return (0);
}

t_tetr		*basic_map_check(char *buf, t_tetr **head)
{
	char	*sub;
	int		new_start;
	t_tetr	*tmp;
	char	letter;

	letter = 'A' - 1;
	if (!buf || ft_strlen(buf) < 20 || (ft_strlen(buf) > (26 * 20 + 25)))
		return (NULL);
	if ((ft_strlen(buf) - 20) % 21 != 0)
		return (NULL);
	tmp = *head;
	while (ft_strlen(buf) >= 20 && letter++)
	{
		new_start = 21;
		sub = ft_strsub(buf, 0, 20);
		if (basic_valid_check(sub) == 0)
			return (NULL);
		if (tmp == NULL)
			tmp = tetrnew(NULL);
		tmp->data = convert_tetr_map(sub, 0);
		tmp->name = letter;
		if (is_valid_tetr(tmp->data, 0) == 0)
			return (NULL);
		calc_wh(tmp);
		free(sub);
		if (ft_strlen(buf) == 20)
			new_start = 20;
		while (new_start && ft_strlen(buf) >= (size_t)new_start)
		{
			buf++;
			new_start--;
		}
		if (new_start)
			return (NULL);
		if (*head != tmp)
			push_back(head, tmp);
		tmp = tmp->next;
	}
	return (*head);
}

void	edge_check(int **tetr, int *num, int row, int col)
{
	if (((row >= 0 && row <= 3) && (col == 0 || col == 3)) ||
		((row == 0 || row == 3) && (col >= 0 && col <= 3)))
	{
		if (col == 0 || col == 1 || col == 2)
			if (tetr[row][col + 1] == 1)
				(*num)++;
		if (row == 0 || row == 1 || row == 2)
			if (tetr[row + 1][col] == 1)
				(*num)++;
		if (row == 3 || row == 2 || row == 1)
			if (tetr[row - 1][col] == 1)
				(*num)++;
		if (col == 3 || col == 2 || col == 1)
			if (tetr[row][col - 1] == 1)
				(*num)++;
	}
}

int		is_valid_tetr(int **tetr, int num)
{
	int	col;
	int row;

	row = -1;
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
			if (tetr[row][col] == 1)
			{
				edge_check(tetr, &num, row, col);
				if ((row == 1 || row == 2) && (col == 1 || col == 2))
				{
					if (tetr[row][col + 1] == 1)
						num++;
					if (tetr[row + 1][col] == 1)
						num++;
					if (tetr[row - 1][col] == 1)
						num++;
					if (tetr[row][col - 1] == 1)
						num++;
				}
			}
	}
	return ((num == 6 || num == 8) ? 1 : 0);
}

int		full_check(char *map, t_tetr **head)
{
	t_tetr	*tmp;

	tmp = basic_map_check(map, head);
	if (!tmp)
		return (0);
	return (1);
}
