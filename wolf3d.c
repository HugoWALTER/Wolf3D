/*
** wireframe.c for bswireframe in /home/walter_h/wireframe
**
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
**
** Started on  Fri Nov 25 10:52:05 2016 Hugo WALTER
** Last update Mon Jan 23 10:22:06 2017 Hugo WALTER
*/

#include "my.h"

sfColor	setColor(int r, int g, int b, int a)
{
  sfColor	color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  return (color);
}

sfColor	define_colors(t_mapsize *ms)
{
  int	a;

  a = 255;
  ms->Brown = setColor(122, 37, 37, 255);
  ms->Blue = setColor(34, 141, 182, 255);
  if (ms->hit > 2.7)
    ms->Gray = setColor(130, 141, 146, (a - 10));
  else
    if (ms->hit < 2)
      ms->Gray = setColor(130, 141, 146, a);
}

void	destroy(t_mapsize *ms)
{
  sfMusic_destroy(ms->music);
  sfRenderWindow_destroy(ms->window);
}

int     main(int ac, char **av)
{
  t_mapsize		*ms;
  t_my_framebuffer	*fb;
  float			direction;

  if (ac == 1)
    return (84);
  init_struct(&ms);
  open_file(ac, av, ms);
  ms->mapSize.x = ms->nbxmax;
  ms->mapSize.y = ms->nbymax;
  direction = 60;
  initialisation(ms->pos, direction, ms);
  while (sfRenderWindow_isOpen(ms->window))
    {
      while (sfRenderWindow_pollEvent(ms->window, &ms->event))
	{
	  escape(ms->event, ms->window, ms);
	  ms->pos = controls_updown(ms->pos, direction, ms);
	  direction = controls_rightleft(ms->pos, direction, ms);
	  update_texture(ms);
	}
      update_texture(ms);
    }
  destroy(ms);
  return (0);
}
