/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:59:19 by emfourni          #+#    #+#             */
/*   Updated: 2025/01/29 19:03:39 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void    *load_image(t_data *data, char *path)
{
    void *img_ptr;

    img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->img_width, &data->img_height);
    if (!img_ptr)
    {
        ft_printf("Error:\nFailed to load image %s\n", path);
        exit(EXIT_FAILURE);
    }
    return img_ptr;
}

void	load_assets(t_data *data)
{
    data->assets.north_wall_texture = load_image(data, data->map->north_texture_path);
    data->assets.south_wall_texture = load_image(data, data->map->south_texture_path);
    data->assets.west_wall_texture = load_image(data, data->map->west_texture_path);
    data->assets.east_wall_texture = load_image(data, data->map->east_texture_path);
    data->assets.floor = mlx_new_image(data->mlx_ptr, 64, 64);
    data->assets.ceiling = mlx_new_image(data->mlx_ptr, 64, 64);
}