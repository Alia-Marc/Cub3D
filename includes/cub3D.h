/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:59:29 by marc              #+#    #+#             */
/*   Updated: 2025/04/09 19:22:00 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
//# include "../mlx_linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>

typedef struct s_map
{
	char		**map;
	char		*north_texture_path;
	char		*south_texture_path;
	char		*west_texture_path;
	char		*east_texture_path;
	int			floor_red;
	int			floor_green;
	int			floor_blue;
	int			ceiling_red;
	int			ceiling_green;
	int			ceiling_blue;
	double		start_y;
	double		start_x;
	char		player_orientation;
	int			nb_rows;

}	t_map;

typedef	struct s_assets
{
	void	*north_wall_texture;
	void	*south_wall_texture;
	void	*west_wall_texture;
	void	*east_wall_texture;
	void	*floor;
	void	*ceiling;

}	t_assets;

typedef union u_color	t_color;

union					u_color
{
	__uint32_t			integer;
	struct
	{
		__uint8_t		r;
		__uint8_t		g;
		__uint8_t		b;
		__uint8_t		a;
	};
};

typedef struct s_img
{
	void	*img;
	void	*address;
	int		height;
	int		width;
	t_color	*pixels;

}	t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

}	t_player;

typedef struct s_rendering
{
	// double	time;
	// double	old_time;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_x;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	
}	t_rendering;

typedef struct s_data
{
	t_assets	assets;
	t_img		window;
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_height;
	int			win_width;
	t_map		*map;
	t_player	player;
	t_rendering	dda;
	t_img		textures[4];
	t_color		floor;
	t_color		ceiling;

}	t_data;

///////////////////////////////////////MAP_PARSING//////////////////////////////

//map_creation.c

#define BAD_FILE_NAME "tia du caca dans le nom de la map, ca foit finir par .cub\n"
#define BAD_OPENING "ca a chie dans la colle a l'ouverture du fichier le S\n"
#define ERROR_WALL_TEXTURE_PATH "tia une couille dans le texture path des wall zebi\n"
#define ERROR_VALUE_RGB "valeurs RGB OUT_OF_RANGE ou tia pas bien rempli les valeurs le S\n"
#define OUT_OF_RANGE(x) ((x) < 0 || (x) > 255)
#define IS_NUM_OR_SPACE(c) (((c) >= '0' && c <= '9') || (c) == ' ')

int check_and_open_map(char *file_name, t_map *map);

//map_creation_utils.c

char	*path_texture_cpy(char *s, int i);
char	**free_line_map(char **map);
int 	check_rgb(char **rgb_values);
int		check_struct_fill(t_map *map);

//map_creation_utils2.c

void	init_map(t_map *map);
void	free_map(t_map *map);
void	print_map(char **map);

//parse_map.cs

#define BAD_CHAR_MAP "tia un char qu'a rien a foutre dans la map zebi\n"
#define IS_INVALID_CHAR(c) ((c) != '1' && (c) != '0' && (c) != 'N' && (c) != 'E' && (c) != 'S' && (c) != 'W' && (c) != ' ')
#define IS_POSITION_PLAYER(c) ((c) == 'N' || (c) == 'S' || (c) == 'E' || (c) == 'W')
#define IS_CELL_SUURROUNDED(c) ((c) == 'N' || (c) == 'S' || (c) == 'E' || (c) == 'W' || (c) == '0')
#define WRONG_PLAYER_POS "tia un truc nique avec ta position du player zebi\n"
#define MAP_IS_INVALID "elle est naze ta carte on dirait du gruyere zebi\n"

int		parse_map(t_map *map);

///////////////////////////////////////RENDERING////////////////////////////////

//manage_window.c

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define MLX_POINTER_FAIL "le pointeur mlx a chie zebi\n"

void	manage_window(t_data *data);

//load_assets.c

void	load_assets(t_data *data);
void    *load_image(t_data *data, char *path);

//init.c
void	init_and_launch(t_map *map);
t_img	init_img_to_square(t_data *g, char *path);
t_img	init_screen(t_data *g);
t_color	init_color(int red, int green, int blue);

//dda.c

void	calculate_ray_dir(t_data *g, int x);
void	init_dda(t_data *g);
void	perform_dda(t_data *g);
void	calculate_draw_limits(t_data *g);

//draw_dda.c

void	dda(t_data *g);
void	draw_vertical_line(t_data *g, t_img texture, int x);
t_img	choose_wall_texture(t_data *g);
void	draw_floor_and_ceiling(t_data *g);

//exit.c
void	exit_free_all(t_data *g, char *message, int exit_code);
void	free_img(t_data *g, t_img *img);
void	free_all(t_data *g);


///////////////////////////////////////EVENTS////////////////////////////////

void	hooks(t_data *g);
int		update(t_data *g);
int		handle_keypress(int keycode, t_data *g);
int		handle_keyrelease(int keycode, void *g);
int		exit_game(t_data *g);



#endif
