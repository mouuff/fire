/*
** init.c for grid init in /home/alies/rendu/gfx_incendie/feu/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Dec  5 13:38:29 2015 Arnaud Alies
** Last update Sat Dec  5 15:11:05 2015 Arnaud Alies
*/

#include "fire.h"

void	init_grid(t_data *data)
{
  int   x;
  int   y;

  x = 0;
  y = 0;
  while (y < HEIGHT)
    {
      if (y == HEIGHT - 1)
	(data->grid)[y][x] = 127;
      else
	(data->grid)[y][x] = 1;
      x += 1;
      if (x > WIDTH)
	{
	  x = 0;
	  y += 1;
	}
    }
}
