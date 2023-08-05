/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:33:20 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/05 08:05:41 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../../libft/libft.h"
# include "cub3d.h"
# include "structs.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// allowed : open, close, read, write, printf,
// allowed : malloc, free, perror, strerror, exit

// =======================> The minilibx Stage <======================= //
// =================================================================== //

void	ft_init(t_vars *data);
void	ft_initiate_window(t_vars *data);
void	ft_wait(t_vars *data);
int		destroy(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_mlx_clear_window(t_vars *data);


// src/mlx/ft_shapes.c
void	ft_rectangle(t_vars *data, t_rect rect);
void	ft_render_map(t_vars *data);

// src/mlx/ft_hooks.c
int		key_pressed(int keycode, t_vars *vars);
int		key_released(int keycode, t_vars *vars);

// =======================> The shared stuff Stage <======================= //
// ======================================================================= //
void	ft_update(t_vars *data);
void	ft_line_dda(t_vars *data, t_line l, int color);
int		ft_render(t_vars *data);

// ===================================================================== //

// =======================> The Player Stage <======================= //
// ================================================================= //
void	ft_main_player(t_vars *data);
void	ft_draw_player(t_vars *data);
void	ft_init_player(t_vars *data);
void	ft_update_player(t_vars *data);
void	ft_render_player(t_vars *data);
void	ft_main_player(t_vars *data);

// ================================================================= //

// =======================> The Utils Stage <======================= //
// ================================================================ //

void	ft_exit(char *str, int status);

// ================================================================ //

// =======================> The Map Stage <======================= //
// ============================================================== //

void	ft_main_map(t_vars *data);
void	ft_init_map(t_vars *data);
int		its_wall(t_vars *data, double x, double y);
void	ft_print_map(t_vars *data);
int		ft_strlen2d(char **str);

// ============================================================== //

// =======================> The rays Stage <======================== //
// ================================================================ //

void	ft_cast_all_rays(t_vars *data);
void	ft_cast_one(t_vars *data, double angle, int id);
double	ft_distance(double x1, double x2, double y1, double y2);
double	ft_normalize(double ray_ang);
void	ft_render_rays(t_vars *data);

// ================================================================ //

#endif