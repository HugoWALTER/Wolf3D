/*
** move_forward.c for move_forward in /home/walter_h/bswolf3d/src
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Tue Dec 20 19:14:04 2016 Hugo WALTER
** Last update Mon Jan  2 16:45:17 2017 Hugo WALTER
*/

#include "../include/my.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  pos.x = pos.x + (distance * cos(direction * (M_PI/180)));
  pos.y = pos.y + (distance * sin(direction * (M_PI/180)));
  return (pos);
}
