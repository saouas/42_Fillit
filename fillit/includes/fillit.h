/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:24:22 by saouas            #+#    #+#             */
/*   Updated: 2018/11/28 20:57:39 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"

typedef struct	s_tetri
{
	int			height;
	int			width;
	char		**tetrimino;
}				t_tetri;

int				check_input(char **str);
char			**read_file(char *str);
int				nbr_tetri(char **tab);
t_tetri			*fill_tetrimino(char **tab);
char			**realloc_map(int i, char **old_map);
char			**init_map(int i, char **map);
int				size_map(char **map);
int				width_map(char **map);
char			**check_placement(char **tetrimino, char **map, int height, int width);
char			**place_tetri(char **map, char  **tetriminos);
void			get_height(t_tetri *tetri_tab);
t_tetri			*make_struct(char **str);
int				*give_first_empty_case(char **map);
char			**create_map(t_tetri *tetriminos);
int				gfec_on_one_line(char **map, int j);
int				*get_uper_left(char **tetrimino);
int				r_d_l_u(char **str, int line, int column);
int				*mover(t_tetri tetrimino, int j, int i);
void			set_cordo_to_zero(int tab[2]);
char			**compute_map(char **map, int size);
int				**get_points(char **tetrimino);



void			print_struct_tab(t_tetri *tab);
#endif
