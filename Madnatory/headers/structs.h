/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:57:05 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/12 19:47:14 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

# define TITLE "cub3D"
# define WIDTH 800
# define HEIGHT 800
# define FOV_DEG 60

# define TILE_SIZE 32

# define HOR -1
# define VER -2

# define MINI_CUB 10

# define M_NOTIFY 6

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
	YELLOW = 0xccff00,
	BROWN = 0xd4ccb5,
	PURPLE = 0x9519b2
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
enum
{
	ROWS = -10,
	COLS = -20
};

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

typedef struct s_ray
{
	double		angle;
	int			is_ver;
	double		distance;
	double		wall_hit_x;
	double		wall_hit_y;
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

typedef struct s_cast
{
	double		angle;
	double		hor_dist;
	double		ver_dist;

	int			is_up;
	int			is_down;
	int			is_left;
	int			is_right;

	double		x_inters;
	double		y_inters;

	double		x_step;
	double		y_step;

	double		next_touch_hor_x;
	double		next_touch_hor_y;
	double		hor_wall_hit_x;
	double		hor_wall_hit_y;

	double		x_check;
	double		y_check;
	int			hor_wall_cont;

	int			found_hor_wall_hit;

	double		next_touch_ver_x;
	double		next_touch_ver_y;
	double		ver_wall_hit_x;
	double		ver_wall_hit_y;

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
	double		fov_angle;
	double		half_fov;
	int			wall_stripe_width;
	int			num_rays;
	int			win_width;
	int			win_height;
	t_ray		*ray;
}				t_shared;

typedef struct s_wall
{
	t_line		line;
	int			i;
	int			j;
	double		dst_proj_plan;
	double		project_wall_height;
	int			wall_height;
	int			top_pixel;
	int			bottom_pixel;
	double		cr_dist;
	int		*texture_so;
	int		*texture_ea;
	int		*texture_we;
	int		*texture_no;
	int 	hight_we;
	int 	width_we;
	int 	hight_no;
	int 	width_no;
	int 	hight_so;
	int 	width_so;
	int 	hight_ea;
	int 	width_ea;

	int 	*buffer;
	int 	hight;
	int 	width;
}				t_wall;

typedef struct s_vars
{
	t_data		img;
	char		**map;
	void		*mlx;
	void		*win;
	t_shared	data;
	t_ray		*rays;
	t_player	player;
	t_parse		*parse;
	t_wall		wall;
}				t_vars;

typedef struct s_mini
{
	int			x_player;
	int			y_player;
	int			x_start;
	int			y_start;
	int			x_end;
	int			y_end;
	t_line		l;

	int			i;
	int			j;
	int			rows;
	int			cols;
	int			curr_cols;
}				t_mini;

#endif