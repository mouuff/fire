/*
** pal.c for pal in /home/alies/rendu/gfx_incendie/feu/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Dec  5 09:22:17 2015 Arnaud Alies
** Last update Sat Dec  5 15:06:13 2015 Arnaud Alies
*/

#include <lapin.h>
#include "fire.h"

void		pal_deg(t_color *pal,
			int beg,
			unsigned int start_color,
			unsigned int end_color)
{
  t_color	s_c;
  t_color	e_c;
  int		x;

  s_c.full = start_color;
  e_c.full = end_color;
  x = beg;
  while (x < beg + OFF)
    {
      x += 1;
      pal[x].argb[0] = MAP((float)x, beg, beg + OFF, s_c.argb[0], e_c.argb[0]);
      pal[x].argb[1] = MAP((float)x, beg, beg + OFF, s_c.argb[1], e_c.argb[1]);
      pal[x].argb[2] = MAP((float)x, beg, beg + OFF, s_c.argb[2], e_c.argb[2]);
      pal[x].argb[3] = 255;
    }
}

void	set_pal(t_color *pal)
{
  pal_deg(pal, 0, RED, BLACK);
  pal_deg(pal, 32, YELLOW, RED);
  pal_deg(pal, 64, WHITE, YELLOW);
  pal_deg(pal, 96, WHITE, WHITE);
}
