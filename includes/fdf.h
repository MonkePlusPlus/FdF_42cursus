/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:59:24 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/03 19:52:00 by ptheo            ###   ########.fr       */
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
typedef struct s_pixel
{
	void	*pixel;
	char	*addr;
	int		bits;
	int		length;
	int		endian;
}				t_pixel;

typedef struct s_pos
{
	int	x;
	int	y;
	int	z;
	int angle;
}				t_pos;

typedef struct s_var
{
	void	*mlx;
	void	*win;
}				t_var;

typedef struct s_data
{
	t_var	var;
	t_pos	pos;
	t_pixel	*pixel;
}				t_data;

/* PIXEL MANAGEMENT */
t_pixel	*create_pixel(void *mlx);
void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color);
void	put_pixel(t_var var, t_pixel *pixel, t_pos pos);

/* CREATE FIGURE */
void	create_line(t_var var, t_pixel *pixel, t_pos *pos);
void	create_square(t_var var, t_pixel *pixel, t_pos *pos);

/* POSITION POINT */
t_pos	*double_pos(t_pos pos1, t_pos pos2);
t_pos	make_pos(int x, int y);

/* KEY MANAGEMENT */
int key_touch(int keycode, t_data *data);
int left_mouse_movement(int x, int y, t_data *data);
int right_mouse_movement(int x, int y, t_data *data);
int key_mouse(int mousecode, int x, int y, t_data *data);


/* CLOSE WINDOW */
int	close_window(int keycode, t_data *data);

#endif