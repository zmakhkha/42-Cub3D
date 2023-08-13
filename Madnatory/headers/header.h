/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:33:20 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/13 20:02:12 by edraidry         ###   ########.fr       */
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

// static void	*_malloc(size_t c, char *file, int line)
// {
// 	void	*p;

// 	p = malloc(c);
// 	printf("MALC: %p, LINE = %i, FILE = %s\n", p, line, file);
// 	return (p);
// }

// static void	_free(void *c, char *file, int line)
// {
// 	printf("FREE: %p, LINE = %i, FILE = %s\n", c, line, file);
// 	return (free(c));
// }

// # define malloc(c) _malloc(c, __FILE__, __LINE__)
// # define free(c) _free(c, __FILE__, __LINE__)

// ===================================================================== //
// =======================> The minilibx Stage <======================= //
// =================================================================== //

// Madnatory/src/mlx/ft_hooks.c
int			key_pressed(int keycode, t_vars *vars);
int			key_released(int keycode, t_vars *vars);

// Madnatory/src/mlx/ft_init.c
void		ft_validate(t_vars *data);
int			ft_map_size(char **map, int i);
void		ft_init_shared(t_vars *data);
void		ft_init(t_vars *data);
void		ft_initiate_window(t_vars *data);

// Madnatory/src/mlx/ft_mlx.c
void		my_mlx_clear_window(t_vars *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			key_hook(int keycode, t_vars *data);
int			destroy(t_vars *vars);
void		ft_wait(t_vars *data);

// Madnatory/src/mlx/ft_shapes.c
void		ft_rectangle(t_vars *data, t_rect rec);
void		ft_render_map(t_vars *data);

// ================================================================== //
// =======================> The Utils Stage <======================= //
// ================================================================ //

// Madnatory/src/ft_utils.c
int			ft_render(t_vars *data);
void		ft_line_dda(t_vars *data, t_line l, int color);
int			its_wall(t_vars *data, double x, double y);
void		ft_exit(char *str, int status);

// ================================================================ //
// =======================> The Map Stage <======================= //
// ============================================================== //

// Madnatory/src/ft_map.c
int			ft_strlen2d(char **str);
void		ft_init_map(t_vars *data);

// =================================================================== //
// =======================> The Player Stage <======================= //
// ================================================================= //

// Madnatory/src/ft_player.c
void		ft_player_line(t_vars *data);
void		ft_player_angle(t_vars *data, char c);
void		ft_spawn(t_vars *data);
void		ft_init_player(t_vars *data);
void		ft_render_player(t_vars *data);

// ================================================================== //
// =======================> The rays Stage <======================== //
// ================================================================ //

// Madnatory/src/ft_rays.c
void		ft_hor_loop(t_vars *data, t_cast *r);
void		ft_ver_loop(t_vars *data, t_cast *r);
void		ft_cast_one(t_vars *data, double angle, int id);
void		ft_cast_all_rays(t_vars *data);
void		ft_render_rays(t_vars *data);

// Madnatory/src/ft__rays.c
double		ft_normalize(double ray_ang);
double		ft_distance(double x1, double y1, double x2, double y2);
void		ft_init_ray(t_vars *data, t_cast *r);
void		ft_intersection(t_vars *data, t_cast *r, int type);
void		ft_steps(t_vars *data, t_cast *r, int type);

// Madnatory/src/ft___rays.c
void		ft__store(t_vars *data, t_cast *r, int id);
void		ft_store(t_vars *data, t_cast *r, int id);

// ================================================================== //
// =======================> The walls Stage <======================= //
// ================================================================ //

// Madnatory/src/ft_walls.c
void        ft_empty_wall(t_vars *data);
void	    ft_select_texture(t_vars *data);
void	    ft_draw_wall(t_vars *data);
void		ft_render_walls(t_vars *data);
void		ft_bg(t_vars *data);
// Madnatory/src/ft__walls.c
int         load_images(t_vars *data);
// ================================================================== //
// =======================> The bonus Stage <======================= //
// ================================================================ //

// Bonus/src/ft_utils_bonus.c
int			ft_render_bonus(t_vars *data);

#endif