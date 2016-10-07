/*
** fire.h for fire in /home/alies/rendu/gfx_incendie
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec  4 21:55:38 2015 Arnaud Alies
** Last update Fri Oct  7 12:01:57 2016 alies_a
*/

#ifndef FIRE_H_
#define FIRE_H_

#define WIDTH (500)
#define HEIGHT (500)
#define FPS (50)

#define OFF (32)

#define MAP(x, sA, eA, sB, eB) ((((sA - x) / (sA - eA)) * (eB - sB)) + sB)

#include <lapin.h>

typedef struct s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  int			grid[HEIGHT][WIDTH];
  t_color		pal[128];
  int			draw;
  int			power;
} t_data;

void	init_grid(t_data *data);
void	grid_to_pix(t_data *data);

void    set_pal(t_color *pal);
void    pixfill(t_bunny_pixelarray *pix,
		unsigned int color);
void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

void	mouse_to_grid(t_data *data);
void    live(t_data *data);
int     get_ave(t_data *data, int x, int y);
void    rand_start(t_data *data);

#endif
