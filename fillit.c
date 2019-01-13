/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:17:39 by palan             #+#    #+#             */
/*   Updated: 2018/12/21 19:20:33 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_matrix(char **matrix)
{
	int i;
	int j;

	i = 0;
	while (i < (int)ft_strlen(matrix[0]))
	{
		j = 0;
		while (j < (int)ft_strlen(matrix[0]))
		{
			ft_putchar(matrix[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	fillit(t_tetr *head)
{
	char	**res;
	t_tetr	*tmp;

	shape_size(&head);
	res = create_matrix(calc_map_size(count_elems(head)));
	tmp = head;
	while (place_all1(res, tmp) == 2)
	{
		tmp = head;
		refresh(tmp);
		res = create_matrix(M_SIZE(res[0]) + 1);
	}
	print_matrix(res);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*map;
	t_tetr	*head;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit file\n");
		return (0);
	}
	head = tetrnew(NULL);
	fd = open(av[1], O_RDONLY);
	map = read_tetr_map(fd);
	if (full_check(map, &head) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	fillit(head);
	return (0);
}
