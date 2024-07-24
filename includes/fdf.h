/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:59:24 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/24 02:11:45 by ptheo            ###   ########.fr       */
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

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 800

# define WHITE 0xFFFFFFFF
# define BLACK 0x00000000

/* STRUCT */
typedef struct s_pixel
{
	void	*pixel;
	char	*addr;
	int		bits;
	int		length;
	int		endian;
}				t_pixel;

typedef struct s_axe
{
    double  alpha;
    double  beta;
    double  delta;
}               t_axe;

typedef struct s_pos
{
	double	a;
	double	b;
	double	c;
	double	i;
	double	j;
	double	z;
	double	x;
	double	y;
}				t_pos;

typedef struct s_var
{
	void	*mlx;
	void	*win;
}				t_var;

typedef struct s_mouse
{
	int	right;
	int	left;
	int	vector_x;
	int	vector_y;
	int	rota_x;
	int	rota_y;
}				t_mouse;

typedef struct s_data
{
	t_var	var;
	t_pos	pos;
	t_pixel	*pixel;
	t_mouse	mouse;
	t_axe	axis;
    t_pos   **matrix;
    int     length;
	int		**screen;
    int     zoom;
	int		rendering;
	int		inrendering;
}				t_data;

/* PIXEL MANAGEMENT */
t_pixel	*create_pixel(void *mlx);
void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color);
void	put_pixel(t_data *data, int x, int y, int color);
void	clear_pixel(t_pixel *pixel);

/* BACKGROUND */
void create_backgound(t_data *data);
int **create_screen();
void    free_tab(int **tab, int size);

/* CREATE FIGURE */
void	create_line(t_data *data, t_pos pos0, t_pos pos1);
void	create_field(t_data *data);
t_pos	**create_matrix();

/* POSITION POINT & ROTATION */
t_pos	new_pos(int x, int y, int z);
void	roll(t_axe axis, t_pos *pos);
void	pitch(t_axe axis, t_pos *pos);
void	yaw(t_axe axis, t_pos *pos);

/* KEY MANAGEMENT */
int key_touch(int keycode, t_data *data);

/* MOUSE MANAGEMENT*/
int mouse_movement(int x, int y, t_data *data);
int mouse_click(int mousecode, int x, int y, t_data *data);
int mouse_release(int mousecode, int x, int y, t_data *data);

/* CLOSE WINDOW */
int	close_window(int keycode, t_data *data);

/* RENDER */
int	render_next_frame(t_data *data);

#endif