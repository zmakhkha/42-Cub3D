/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:57:05 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/13 18:36:44 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define TITLE "cub3D"
# define WIDTH 1000
# define HEIGHT 1000
# define FOV (60 * M_PI / 180)

# define MAP_NUM_ROWS 10
# define MAP_NUM_COLS 10
# define TILE_SIZE 30

enum
{
	NORTH = 0,
	SOUTH = 1,
	EST = 3,
	WEST = 4
};
enum
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
	WHITE = 0xffffff,
	YELLOW = 0xccff00
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
typedef struct s_player
{
	int			spawn;
	float		x;
	float		y;
	float		rotation_angle;
	float		move_speed;
	float		rotation_speed;
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

typedef struct s_ray
{
	float		angle;
	int			is_ver;
	float		distance;
	float		wall_hit_x;
	float		wall_hit_y;
	int			wall_content;
	int			is_up;
	int			is_down;
	int			is_left;
	int			is_right;
}				t_ray;

typedef struct s_rect
{
	int			x;
	int			y;
	int			len;
	int			fill;
}				t_rect;
typedef struct s_line
{
	float		ox;
	float		oy;
	float		dx;
	float		dy;
}				t_line;
typedef struct s_dda
{
	float		dx;
	float		dy;
	float		step;
	float		x_inc;
	float		y_inc;
}				t_dda;

typedef struct s_cast
{
	float		angle;
	float		hor_dist;
	float		ver_dist;

	int			is_up;
	int			is_down;
	int			is_left;
	int			is_right;

	float		x_inters;
	float		y_inters;

	float		x_step;
	float		y_step;

	float		next_touch_hor_x;
	float		next_touch_hor_y;
	float		hor_wall_hit_x;
	float		hor_wall_hit_y;

	float		x_check;
	float		y_check;
	int			hor_wall_cont;

	int			found_hor_wall_hit;

	float		next_touch_ver_x;
	float		next_touch_ver_y;
	float		ver_wall_hit_x;
	float		ver_wall_hit_y;

	int			ver_wall_cont;

	int			found_ver_wall_hit;
}				t_cast;

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
	t_ray		*ray;
}				t_shared;

typedef struct s_vars
{
	t_data		img;
	int			**map;
	void		*mlx;
	void		*win;
	t_shared	data;
	t_ray		*rays;
	t_player	player;
}				t_vars;

#endif