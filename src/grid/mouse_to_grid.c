/*
** mouse_to_grid.c for mouse to grid in /home/alies/rendu/gfx_incendie/feu
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Dec  5 18:51:28 2015 Arnaud Alies
** Last update Sun Dec  6 20:18:48 2015 Arnaud Alies
*/

#include <lapin.h>
#include <math.h>
#include "fire.h"

void			my_circle(t_data *data,
				  t_bunny_position pos,
				  float size)
{
  t_bunny_position	a;
  float			rad;

  rad = 0;
  while (rad < 2 * M_PI)
    {
      a.x = pos.x - cos(rad) * size;
      a.y = pos.y - sin(rad) * size;
      if ((a.y < HEIGHT - 1 && a.y > 0) &&
	  (a.x > 0 && a.x < WIDTH - 1))
	{
	  (data->grid)[a.y][a.x] = (data->draw == 1 ? 130 : 120);
	}
      rad += 0.05;
    }
}

void                            mouse_to_grid(t_data *data)
{
  const t_bunny_position        *pos;
  int                           x;

  x = 1;
  pos = bunny_get_mouse_position();
  if (pos == NULL)
    return ;
  while (x < (data->draw == 2 ? 20 : 10))
    {
      my_circle(data, *pos, x);
      x += 1;
    }
}
