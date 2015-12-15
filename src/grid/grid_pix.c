/*
** gridpix.c for grid to pix in /home/alies/rendu/gfx_incendie/feu/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Dec  5 13:39:03 2015 Arnaud Alies
** Last update Sat Dec  5 19:18:26 2015 Arnaud Alies
*/

#include <lapin.h>
#include "fire.h"

void                    grid_to_pix(t_data *data)
{
  t_bunny_position      pos;
  int                   x;
  int                   y;
  int			pal;

  x = 0;
  y = 0;
  while (y < HEIGHT)
    {
      pos.x = x;
      pos.y = y;
      if ((y < HEIGHT && y >= 0) && (x < WIDTH && x >= 0))
	{
	  pal = (data->grid)[y][x];
	  pal = (pal > 127 ? 127 : pal);
	  pal = (pal < 0 ? 0 : pal);
	  tekpixel(data->pix, &pos, &((data->pal)[pal]));
	}
      x += 1;
      if (x > WIDTH)
	{
	  x = 0;
	  y += 1;
	}
    }
}
