/*
** draw.c for draw in /home/walter_h/wolf3d
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Sun Jan 15 18:44:53 2017 Hugo WALTER
** Last update Sun Jan 15 18:49:47 2017 Hugo WALTER
*/

#include "my.h"

void	draw_sky(t_mapsize *ms, float uppixel, int x)
{
  ms->frompixel.x = (int)x;
  ms->frompixel.y = (int)uppixel;
  ms->tosky.x = (int)x;
  ms->tosky.y = 0;
  my_draw_line(ms->structure, ms->frompixel, ms->tosky, ms->Blue);
}

void	draw_floor(t_mapsize *ms, float downpixel, int x)
{
  ms->fromp.x = (int)x;
  ms->fromp.y = (int)downpixel;
  ms->tofloor.x = (int)x;
  ms->tofloor.y = SCREEN_HEIGHT;
  my_draw_line(ms->structure, ms->fromp, ms->tofloor, ms->Brown);
}

void	draw_wall(t_mapsize *ms, float downpixel, float uppixel, int x)
{
  ms->fromdw.x = (int)x;
  ms->fromdw.y = (int)uppixel;
  ms->todw.x = (int)x;
  ms->todw.y = (int)downpixel;
  my_draw_line(ms->structure, ms->fromdw, ms->todw, ms->Gray);
}

void	disp_wall(sfVector2f pos, float direction, int **map, t_mapsize *ms)
{
  float         hit;
  int           x;
  float         downpixel;
  float         uppixel;
  float         distancewall;

  x = 0;
  define_colors(ms);
  ms->anglesave = direction + 30;
  while (x != SCREEN_WIDTH)
    {
      hit = raycast(pos, direction, ms->map, ms->mapSize)
	* cos((ms->anglesave - direction) * M_PI / 180);
      ms->hit = hit;
      distancewall = (SCREEN_HEIGHT / hit);
      uppixel = -(distancewall) + (SCREEN_HEIGHT / 2);
      draw_sky(ms, uppixel, x);
      downpixel = (distancewall / 2) + (SCREEN_HEIGHT / 2);
      draw_floor(ms, downpixel, x);
      draw_wall(ms, uppixel, downpixel, x);
      draw_crosshair(ms);
      x++;
      direction+= 0.09375;
    }
}

void	update_texture(t_mapsize *ms)
{
  sfRenderWindow_clear(ms->window, sfBlack);
  sfTexture_updateFromPixels(ms->texture, ms->structure->pixels,
			     ms->structure->width,
			     ms->structure->height, 0, 0);
  sfRenderWindow_drawSprite(ms->window, ms->sprite, NULL);
  sfRenderWindow_display(ms->window);
}
