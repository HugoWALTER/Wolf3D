/*
** fctrayscast.c for fctraycast in /home/walter_h/bswolf3d/src
**
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
**
** Started on  Mon Jan  2 16:33:00 2017 Hugo WALTER
** Last update Tue Jul  4 10:39:43 2017 Hugo WALTER
*/

#include "my.h"

int	error()
{
  write(2, "You must use 2 arguments to load the map !\n",
	my_strlen("You must use 2 arguments to load the map !\n"));
  return (84);
}

int	init_struct(t_mapsize **mapsize)
{
  t_mapsize	*ms;

  ms = malloc(sizeof(*ms));
  if (malloc(sizeof(*ms)) == NULL)
    return (84);
  ms->nbxmax = 0;
  ms->nbymax = 0;
  ms->k = 0;
  ms->hit = 0;
  ms->savepos.x = 0;
  ms->savepos.y = 0;
  ms->pos.x = 7.3;//7.3 / 6.8
  ms->pos.y = 1.3;//1.3 / 2.2
  *mapsize = ms;
  return (0);
}

int	**map_to_inttab(char *buffer, t_mapsize *ms)
{
  int	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  tab = malloc(sizeof(int **) * strlen(buffer));
  while (buffer[k])
    {
      j = 0;
      tab[i] = malloc(sizeof(int *) * strlen(buffer));
      while (buffer[k] != '\n')
	{
	  tab[i][j] = buffer[k] - 48;
	  j++;
	  k++;
	}
      tab[i][j] = buffer[k];
      i++;
      k++;
    }
  return (tab);
}

int	open_file(int ac, char **av, t_mapsize *ms)
{
  char	fd;
  char	*buffer;
  int	i;

  buffer = malloc(sizeof(char) * 1024);
  if (buffer == NULL)
    return (84);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (84);
  i = read(fd, buffer, 1024);
  buffer[i] = '\0';
  i = 0;
  while (buffer[i])
    {
      if (buffer[i] == '\n')
	ms->nbymax++;
      while (buffer[ms->k] != '\n')
	ms->k++;
      i++;
    }
  ms->nbxmax = ms->k;
  close(fd);
  ms->map = map_to_inttab(buffer, ms);
  return (0);
}
