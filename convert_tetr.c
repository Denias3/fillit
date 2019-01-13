/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tetr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:08:58 by palan             #+#    #+#             */
/*   Updated: 2018/12/20 19:29:41 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**convert_tetr_map(char *buf, int pos)
{
	int		i;
	int		j;
	int		**arr;

	arr = (int**)malloc(sizeof(int*) * 4);
	if (arr == NULL)
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		arr[i] = (int*)malloc(sizeof(int) * 4);
		j = -1;
		while (++j < 4)
		{
			if (buf[pos] == '.')
				arr[i][j] = 0;
			else if (buf[pos] == '#')
				arr[i][j] = 1;
			pos++;
			if (buf[pos] == '\n')
				pos++;
		}
	}
	return (arr);
}

char	*read_tetr_map(int fd)
{
	char	*map;
	char	*line;
	char	*temp;

	map = ft_strnew(0);
	while (get_next_line(fd, &line) == 1)
	{
		temp = ft_strjoin(line, "\n");
		map = ft_strjoin(map, temp);
		free(temp);
	}
	return (map);
}
