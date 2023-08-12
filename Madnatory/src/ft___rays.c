/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft___rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:51:04 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/12 15:53:00 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft__store(t_vars *data, t_cast *r, int id)
{
	if ((r->ver_dist < r->hor_dist))
		data->rays[id].is_ver = 1;
	else
		data->rays[id].is_ver = 0;
	data->rays[id].is_up = r->is_up;
	data->rays[id].is_down = r->is_down;
	data->rays[id].is_left = r->is_left;
	data->rays[id].is_right = r->is_right;
}

void	ft_store(t_vars *data, t_cast *r, int id)
{
	if (r->found_hor_wall_hit)
		r->hor_dist = ft_distance(data->player.x, data->player.y, \
			r->hor_wall_hit_x, r->hor_wall_hit_y);
	else
		r->hor_dist = 100000000;
	if (r->found_ver_wall_hit)
		r->ver_dist = ft_distance(data->player.x, data->player.y, \
			r->ver_wall_hit_x, r->ver_wall_hit_y);
	else
		r->ver_dist = 100000000;
	data->rays[id].angle = r->angle;
	if (r->hor_dist < r->ver_dist)
	{
		data->rays[id].distance = r->hor_dist;
		data->rays[id].wall_hit_y = r->hor_wall_hit_y;
		data->rays[id].wall_hit_x = r->hor_wall_hit_x;
	}
	else
	{
		data->rays[id].distance = r->ver_dist;
		data->rays[id].wall_hit_x = r->ver_wall_hit_x;
		data->rays[id].wall_hit_y = r->ver_wall_hit_y;
	}
	ft__store(data, r, id);
}
