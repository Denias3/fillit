/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:02:31 by palan             #+#    #+#             */
/*   Updated: 2018/12/20 15:59:23 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# define M_SIZE(x) (int)ft_strlen(x)

typedef	struct	s_tetr
{
	struct s_tetr		*prev;
	int					**data;
	int					x;
	int					y;
	int					g_x;
	int					g_y;
	int					height;
	int					width;
	int					state;
	char				name;
	struct s_tetr		*next;
}				t_tetr;

char			*read_tetr_map(int fd);
int				**convert_tetr_map(char *buf, int pos);
int				basic_valid_check(char *tetr);
void			edge_check(int **tetr, int *num, int row, int col);
int				is_valid_tetr(int **tetr, int num);
t_tetr			*basic_map_check(char *buf, t_tetr **head);
int				full_check(char *map, t_tetr **head);
void			push_back(t_tetr **head, t_tetr *elem);
t_tetr			*tetrnew(int **data);
void			shape_size(t_tetr **head);
char			**create_matrix(int size);
int				calc_map_size(int tetrs);
int				count_elems(t_tetr *head);
int				put_tetr(char **matrix, t_tetr *elem, int i, int j);
int				place_all1(char **matrix, t_tetr *elem);
void			calc_wh(t_tetr *elem);
void			print_matrix(char **matrix);
void			calc_next_tetr_pos(t_tetr *elem, char **matrix);
int				count_status_elems(t_tetr *head);
int				remove_elem_from_matrix(char **matrix, t_tetr *elem);
void			refresh(t_tetr *elem);
int				all_prev_not_placed(char **matrix, t_tetr *elem);
int				is_placed(char **matrix, t_tetr *elem);

#endif
