/*
** window.c for window in /home/walter_h/wolf3d
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Sun Jan 15 18:31:20 2017 Hugo WALTER
** Last update Sun Jan 15 20:08:19 2017 Hugo WALTER
*/

#include "my.h"

t_my_framebuffer*	my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	*buffer;
  int	i;

  buffer = malloc(sizeof(*buffer));
  buffer->pixels = malloc(width * height * 4 * sizeof(buffer->pixels));
  buffer->width = width;
  buffer->height = height;
  if (buffer->pixels == NULL)
    return (0);
  i = 0;
  while (i < width * height * 4)
    {
      buffer->pixels[i] = 0;
      i++;
    }
  return (buffer);
}

int	verif(sfRenderWindow *window)
{
  if (window == NULL)
    return (1);
}

sfRenderWindow	*create_window(char* name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  verif(window);
  return (window);
}

int	initialisation(sfVector2f pos, float direction, t_mapsize *ms)
{
  ms->music = sfMusic_createFromFile("addon/xx_intro.ogg");
  if (!ms->music)
    return (84);
  sfMusic_play(ms->music);
  sfMusic_setLoop(ms->music, sfTrue);
  if (pos.x > ms->mapSize.x || pos.y > ms->mapSize.y)
    return (84);
  ms->window = create_window("WOLF3D", SCREEN_WIDTH, SCREEN_HEIGHT);
  ms->texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  ms->sprite = sfSprite_create();
  sfSprite_setTexture(ms->sprite, ms->texture, sfTrue);
  ms->structure = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  disp_wall(pos, direction, ms->map, ms);
  draw_crosshair(ms);
  return (0);
}

int	escape(sfEvent event, sfRenderWindow *window, t_mapsize *ms)
{
  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    sfRenderWindow_close(ms->window);
  if (ms->event.type == sfEvtClosed)
    sfRenderWindow_close(ms->window);
  return (0);
}
