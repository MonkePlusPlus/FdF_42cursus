/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:59:24 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/02 17:34:26 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <math.h>

/* STRUCT */
typedef struct s_data
{
	void	*pixel;
	char	*addr;
	int		bits;
	int		length;
	int		endian;
}				t_data;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_var
{
	void	*mlx;
	void	*win;
}				t_var;

typedef struct s_all
{
	t_var	var;
	t_pos	pos;
	t_data	*pixel;
}				t_all;

/* PIXEL MANAGEMENT */
t_data	*create_pixel(void *mlx);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	put_pixel(t_var var, t_data *pixel, t_pos pos);

/* CREATE FIGURE */
void	create_line(t_var var, t_data *pixel, t_pos *pos);
void	create_square(t_var var, t_data *pixel, t_pos *pos);

/* POSITION POINT */
t_pos	*double_pos(t_pos pos1, t_pos pos2);
t_pos	make_pos(int x, int y);

/* KEY MANAGEMENT */
int click_mouse(int keycode, t_var *var);
int mouse_movement(int x, int y, t_var *var);

#endif