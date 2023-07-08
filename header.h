/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 00:01:51 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/09 00:02:33 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// allowed : open, close, read, write, printf,
// allowed : malloc, free, perror, strerror, exit

# define TITLE "Cub3d"
# define WIN_WIDTH 900
# define WIN_HEIGHT 900
# define TILE_SIZE 32
# define ROWS 15
# define COLS 16

# define WIDTH  COLS * TILE_SIZE
# define HEIGHT  ROWS * TILE_SIZE

# define FOV_ANGLE  60 * (Math.PI / 180)
# define WALL_STRIP_WIDTH  50
# define NUM_RAYS  WIDTH / WALL_STRIP_WIDTH

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ON_ESC = 53
};

# define ON_MOUSEUP 5
# define ON_MOUSEDW 4
# define L_MOUSECLK 1
# define K_PRESS 2
# define ON_DESTROY 17
# define BTN_PRESS 4
# define M_NOTIFY 6
# define ON_ESC 53

typedef struct s_player
{
	double	x;
	double	y;
	double	rad;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;
	int		turn_direction;
	int		walk_direction;
}			t_player;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	t_data	img;
	int		**map;
	void	*mlx;
	void	*win;
}			t_vars;

// =======================> The minilibx Stage <======================= //
// =================================================================== //

void		ft_init(t_vars *data);
void		ft_initiate_window(t_vars *data);
void		ft_wait(t_vars *data);
int			destroy(t_vars *vars);

// =================================================================== //

// =======================> The Player Stage <======================= //
// ================================================================= //

// ================================================================= //

// =======================> The Utils Stage <======================= //
// ================================================================ //

void		ft_exit(char *str, int status);

// ================================================================ //

#endif