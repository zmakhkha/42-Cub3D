/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:33:20 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/09 17:45:55 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
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

// src/mlx/ft_shapes.c
void	ft_rectangle(t_vars *data, t_rect rect);
void	ft_render(t_vars *data);

// src/mlx/ft_hooks.c
int		key_pressed(int keycode, t_vars *vars);
int		key_released(int keycode, t_vars *vars);

// =================================================================== //

// =======================> The Player Stage <======================= //
// ================================================================= //

// ================================================================= //

// =======================> The Utils Stage <======================= //
// ================================================================ //

void	ft_exit(char *str, int status);

// ================================================================ //

// =======================> The Map Stage <======================= //
// ============================================================== //

void	ft_main_map(t_vars *data);
void	ft_init_map(t_vars *data);

// ============================================================== //

#endif