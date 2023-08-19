/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:32:41 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/15 17:37:41 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Madnatory/headers/header.h"

int	ft_render_bonus(t_vars *data)
{
	my_mlx_clear_window(data);
	ft_render_player(data);
	ft_render_rays(data);
	ft_bg(data);
	ft_render_walls(data);
	mlx_put_image_to_window(&(data->img), data->win, data->img.img, 0, 0);
	return (0);
}
