/*
** my.h for my.h in /home/walter_h/wireframe/include
**
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
**
** Started on  Wed Dec  7 17:35:58 2016 Hugo WALTER
** Last update Fri Mar 31 18:50:45 2017 Hugo WALTER
*/

#ifndef MY_H
# define MY_H
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

typedef struct  s_my_drawl
{
  int i;
  int x;
  int y;
  int j;
  int dx;
  int dy;
  int lx;
  int ly;
}               t_my_drawl;

typedef struct  s_my_framebuffer
{
  sfUint8*      pixels;
  int           width;
  int           height;
}               t_my_framebuffer;

typedef struct  s_mapsize
{
  sfRenderWindow        *window;
  sfEvent               event;
  sfTexture             *texture;
  sfSprite              *sprite;
  t_my_framebuffer      *structure;
  sfVector2i            from;
  sfVector2i            to;
  int			nbxmax;
  int			nbymax;
  int			k;
  int			**map;
  float			hit;
  sfVector2f		savepos;
  sfVector2i		mapSize;
  sfVector2f		pos;
  sfColor		Brown;
  sfColor		Blue;
  sfColor		Gray;
  sfVector2i		frompixel;
  sfVector2i		tosky;
  sfVector2i		fromp;
  sfVector2i		tofloor;
  sfVector2i		fromdw;
  sfVector2i		todw;
  float			anglesave;
  sfMusic		*music;
}               t_mapsize;

t_my_framebuffer*	my_framebuffer(int width, int height);
int			verif(sfRenderWindow *window);
sfRenderWindow		*create_window(char *name, int width, int height);
int			initialisation(sfVector2f pos, float direction,
				       t_mapsize *ms);
int			escape(sfEvent event, sfRenderWindow *window,
			       t_mapsize *ms);
sfVector2f		move_up(sfVector2f pos, float direction,
				t_mapsize *ms);
sfVector2f		move_down(sfVector2f pos, float direction,
				  t_mapsize *ms);
float			move_right(sfVector2f pos, float direction,
				   t_mapsize *ms);
float			move_left(sfVector2f pos, float direction,
				  t_mapsize *ms);
void			draw_sky(t_mapsize *ms, float uppixel, int x);
void			draw_floor(t_mapsize *ms, float downpixel, int x);
void			draw_wall(t_mapsize *ms, float downpixel,
				  float uppixel, int x);
void			disp_wall(sfVector2f pos, float direction, int **map,
				  t_mapsize *ms);
void			update_texture(t_mapsize *ms);
sfVector2f		controls_updown(sfVector2f pos, float direction,
					t_mapsize *ms);
float			controls_rightleft(sfVector2f pos, float direction,
					   t_mapsize *ms);
sfVector2i		take2D(int a, int b);
void			draw_crosshair(t_mapsize *ms);
sfColor			setColor(int r, int g, int b, int a);
sfColor			define_colors(t_mapsize *ms);
int			main(int ac, char **av);
int			error();
int			init_struct(t_mapsize **mapsize);
int			**map_to_inttab(char *buffer, t_mapsize *ms);
int			open_file(int ac, char **av, t_mapsize *ms);
sfVector2f		move_coll(sfVector2f pos, float direction,
				  float distance, t_mapsize *ms);
int			my_abs(int x);
int			my_strlen(char *str);
void			my_put_pixel(t_my_framebuffer* framebuffer, int x,
				     int y, sfColor color);
void			my_draw_line(t_my_framebuffer* framebuffer,
				     sfVector2i from, sfVector2i to,
				     sfColor color);
void			my_draw_lineonx(t_my_framebuffer* framebuffer,
					sfVector2i from, sfVector2i to,
					sfColor color);
void			my_draw_lineony(t_my_framebuffer* framebuffer,
					sfVector2i from, sfVector2i to,
					sfColor color);
sfVector2f		my_move(sfVector2f pos, float direction,
				float distance);
float			raycast(sfVector2f pos, float direction, int **map,
				sfVector2i mapSize);
void			destroy(t_mapsize *ms);

#endif
