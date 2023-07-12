/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:57:05 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/12 15:22:32 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define TITLE "cub3D"
# define WIDTH 1000
# define HEIGHT 1000

enum
{
	NORTH = 0,
	SOUTH = 1,
	EST = 3,
	WEST = 4
} enum
{
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	ARROW_DOWN = 125,
	ARROW_UP = 126
};

enum
{
	RED = 0x990033,
	GREEN = 0x009900,
	BLUE = 0x3399ff,
	BLACK = 0x00000000,
	WHITE = 0xffffff
};

enum
{
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ON_ESC = 53
};

typedef struct s_shared
{
	int			cub_size;
	int			grid_rows;
	int			grid_cols;
	int			grid_width;
	int			grid_height;
	int			fov_angle;
	int			wall_stripe_width;
	int			num_rays;
}				t_shared;

typedef struct s_player
{
	int			spawn;
	double		x;
	double		y;
	double		rotation_angle;
	double		move_speed;
	double		rotation_speed;
	int			turn_direction;
	int			walk_direction;
}				t_player;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			notify;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_vars
{
	t_data		img;
	int			**map;
	void		*mlx;
	void		*win;
	t_shared	data;
	t_player	player;
}				t_vars;

typedef struct s_rect
{
	int			x;
	int			y;
	int			len;
	int			fill;
}				t_rect;
typedef struct s_line
{
	double		ox;
	double		oy;
	double		dx;
	double		dy;
}				t_line;
typedef struct s_dda
{
	double		dx;
	double		dy;
	double		step;
	double		x_inc;
	double		y_inc;
}				t_dda;

#endif