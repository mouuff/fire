/*
** main.c for fire in /home/alies/rendu/gfx_incendie
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec  4 21:54:40 2015 Arnaud Alies
** Last update Fri Oct  7 13:47:20 2016 alies_a
*/

#include <math.h>
#include <stdlib.h>
#include <lapin.h>
#include "fire.h"

static t_bunny_response	loop(void *data_pt)
{
  t_data		*data;
  t_bunny_position	zero;

  zero.x = 0;
  zero.y = 1;
  data = (t_data*)data_pt;
  rand_start(data);
  live(data);
  mouse_to_grid(data);
  grid_to_pix(data);
  bunny_blit(&((data->win)->buffer), &((data->pix)->clipable), &zero);
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response	key_listenner(t_bunny_event_state state,
				      t_bunny_keysym keysym,
				      void *data_pt)
{
  t_data		*data;

  data = (t_data*)data_pt;
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (state == GO_DOWN && keysym == BKS_UP)
    data->power += (data->power < 3 ? 1 : 0);
  if (state == GO_DOWN && keysym == BKS_DOWN)
    data->power -= (data->power > 0 ? 1 : 0);
  return (GO_ON);
}

t_bunny_response	mouse_listenner(t_bunny_event_state state,
					t_bunny_mousebutton button,
					void *data_pt)
{
  t_data		*data;

  data = (t_data*)data_pt;
  if (state == GO_DOWN && button == 0)
    data->draw = 1;
  else if (state == GO_DOWN && button == 1)
    data->draw = 2;
  else
    data->draw = 0;
  return (GO_ON);
}

int			main()
{
  t_data		data;

  if ((data.win = bunny_start(WIDTH, HEIGHT, false, "Feu")) == NULL)
    return (1);
  if ((data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  set_pal(data.pal);
  init_grid(&data);
  bunny_set_loop_main_function(loop);
  bunny_set_key_response(&key_listenner);
  bunny_set_click_response(&mouse_listenner);
  data.draw = 0;
  data.power = 0;
  bunny_loop(data.win, FPS, (void*)(&data));
  bunny_stop(data.win);
  bunny_delete_clipable(&((data.pix)->clipable));
  return (0);
}
