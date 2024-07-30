/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:59:24 by ptheo             #+#    #+#             */
/*   Updated: 2024/07/30 15:13:42 by ptheo            ###   ########.fr       */
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

#ifndef M_PI
# define M_PI 3.14
#endif

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define WHITE 0xFFFFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

# define WHITE_SPACE " \f\n\r\t\v"

/* STRUCT */
typedef struct s_color
{
	int	start;
	int	end;
}				t_color;

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

typedef struct s_mouse
{
	int	right;
	int	left;
	int	vector_x;
	int	vector_y;
	int	rota_x;
	int	rota_y;
}				t_mouse;

typedef struct s_line
{
	char	**line;
	struct s_line	*next;
}				t_line;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_pos	pos;
	t_pixel	*pixel;
	t_mouse	mouse;
	t_axe	axis;
    t_pos   **matrix;
	double	middle_x;
	double	middle_y;
    int     width;
	int		height;
	int		prof;
	int		**screen;
    int		zoom;
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

/* CREATE FIGURE */
void	create_line(t_data *data, t_pos pos0, t_pos pos1, t_color color);
void	create_field(t_data *data);

/* MATRIX MAP */
t_pos	**create_matrix(t_line *map, t_data *data);
t_line	*create_map(int fd, t_data *data);
void	maplen(t_line *list, t_data *data);
void	print_map(t_line *map);

/* SPLIT */
int	check_char(char s, char *c);
char	**better_split(char const *s, char *c);

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
int		close_window(t_data *data);
void	freeall(t_data *data);
void	clear_tab(void **tab, int size);

/* RENDER */
int	render_next_frame(t_data *data);

/* CHAIN LIST LINE */
t_line	*new_line(char **content);
void	line_add(t_line **lst, t_line *new);
void	line_clear(t_line **lst, void (*del)(char **));
void	free_line(char **line);

/* TEXT */
void	affiche_text(t_data *data);

/* COLOR */
t_color	new_color(int color1, int color2);
t_color	full_color(t_pos pos1, t_pos pos2);
int		pick_color(t_pos pos);

#endif