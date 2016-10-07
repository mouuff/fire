/*
** get_moy.c for get moy in /home/alies/rendu/gfx_incendie/feu
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Dec  5 18:53:18 2015 Arnaud Alies
** Last update Fri Oct  7 12:00:14 2016 alies_a
*/

#include "fire.h"

int     get_ave(t_data *data, int x, int y)
{
  int   res;

  if (x > 1 && x < WIDTH - 2)
    {
      res = (data->grid)[y + 1][x];
      res += (data->grid)[y + 1][x - 1];
      res += (data->grid)[y][x - 1];
      res += (data->grid)[y + 1][x + 1];
      res += (data->grid)[y][x + 1];
      res /= 5;
    }
  else
    res = 0;
  if (res < 2)
    res += 2;
  res +=  - rand() % 2 + ((rand() % 4 == 1) ? data->power : 0);
  return ((res > 125 ? 125 : res));
}
