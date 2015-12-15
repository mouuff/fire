/*
** rand_start.c for rand start in /home/alies/rendu/gfx_incendie/feu
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Dec  5 18:54:19 2015 Arnaud Alies
** Last update Sat Dec  5 19:32:43 2015 Arnaud Alies
*/

#include "fire.h"

void    rand_start(t_data *data)
{
  int   res;
  int   x;
  int   y;

  x = 0;
  y = HEIGHT - 1;
  while (x < WIDTH - 1)
    {
      if (x > 0 && x < WIDTH - 2)
	{
	  res = ((data->grid)[y][x] +
		 (data->grid)[y][x - 1] +
		 (data->grid)[y][x + 1]) / 3;
	  res += 10 - rand() % 20;
	  if (res > 120)
	    res = 120;
	  if (res < 1)
	    res = 1;
	  (data->grid)[y][x] = res;
	}
      x += 1;
    }
}
