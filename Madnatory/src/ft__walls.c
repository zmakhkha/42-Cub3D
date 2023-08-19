/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:54:43 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/15 19:19:51 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	load_images(t_vars *data)
{
	int		w;
	int		h;
	void	*xpm;

	xpm = mlx_xpm_file_to_image(data->mlx, data->parse->we, \
		&data->wall.width_we, &data->wall.hight_we);
	if (!xpm)
		ft_exit("Error : Counld not load west texture file", 1);
	data->wall.texture_we = (int *)mlx_get_data_addr(xpm, &w, &w, &h);
	xpm = mlx_xpm_file_to_image(data->mlx, data->parse->no, \
		&data->wall.width_no, &data->wall.hight_no);
	if (!xpm)
		ft_exit("Error : Counld not load east texture file", 1);
	data->wall.texture_no = (int *)mlx_get_data_addr(xpm, &w, &w, &h);
	xpm = mlx_xpm_file_to_image(data->mlx, data->parse->so, \
		&data->wall.width_so, &data->wall.hight_so);
	if (!xpm)
		ft_exit("Error : Counld not load south texture file", 1);
	data->wall.texture_so = (int *)mlx_get_data_addr(xpm, &w, &w, &h);
	xpm = mlx_xpm_file_to_image(data->mlx, data->parse->ea, \
		&data->wall.width_ea, &data->wall.hight_ea);
	if (!xpm)
		ft_exit("Error : Counld not load north texture file", 1);
	data->wall.texture_ea = (int *)mlx_get_data_addr(xpm, &w, &w, &h);
	return (0);
}

void	ft_empty_wall(t_vars *data)
{
	data->wall.cr_dist = data->rays[data->wall.i].distance
		* cos(data->rays[data->wall.i].angle - data->player.rotation_angle);
	data->wall.dst_proj_plan = (data->data.win_width / 2)
		/ tan(data->data.fov_angle / 2.0);
	data->wall.project_wall_height = (data->data.cub_size / data->wall.cr_dist)
		* data->wall.dst_proj_plan;
	data->wall.wall_height = (int)data->wall.project_wall_height;
	data->wall.top_pixel = (data->data.win_height / 2)
		- (data->wall.project_wall_height / 2);
	data->wall.bottom_pixel = (data->data.win_height / 2)
		+ (data->wall.project_wall_height / 2);
	if (data->wall.top_pixel < 0)
		data->wall.top_pixel = 0;
	if (data->wall.bottom_pixel > data->data.win_height)
		data->wall.bottom_pixel = data->data.win_height;
	data->wall.line.ox = data->wall.i;
	data->wall.line.oy = data->wall.top_pixel;
	data->wall.line.dx = data->wall.i;
	data->wall.line.dy = data->wall.bottom_pixel;
}
