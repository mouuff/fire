/*
** do_stuff.c for do stuff in /home/alies/rendu/gfx_incendie/feu
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Dec  5 18:52:12 2015 Arnaud Alies
** Last update Fri Oct  7 12:01:05 2016 alies_a
*/

#include "fire.h"

void    live(t_data *data)
{
  int   x;
  int   y;

  x = 0;
  y = HEIGHT - 2;
  while (y >= 0)
    {
      if ((data->grid)[y][x] < 127)
	(data->grid)[y][x] = get_ave(data, x, y);
      x += 1;
      if (x > WIDTH)
	{
	  x = 0;
	  y -= 1;
	}
    }
}
