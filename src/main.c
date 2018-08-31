/*
** main.c for Rush in /home/elayou_y/Rush/CPE_rush4stek_2016/src
** 
** Made by Youness El Ayouch
** Login   <elayou_y@epitech.net>
** 
** Started on  Sat Jun  3 16:55:55 2017 Youness El Ayouch
** Last update Sun Jun  4 18:35:03 2017 Sadiqu-m
*/

#include "my.h"

static int	check_lap(char *str)
{
  char	**tmp;
  int	i;
  static int	nb = 0;

  if ((tmp = my_str_to_wordtab(str, ':')) == NULL)
    return (0);
  i = -1;
  dprintf(2, "[Info] Current lap : ");
  while (tmp[++i] != NULL)
    {
      if (strcmp(tmp[i], "Lap Cleared") == 0)
	{
	  nb = nb + 1;
	}
    }
  dprintf(2, "(%d)\n", nb);
  free(str);
  free(tmp);
  return (0);
}

sfRenderWindow	*create_window(char *name)
{
  sfRenderWindow	*window;
  sfVideoMode	mode;

  mode.width = 1280;
  mode.height = 720;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}

int	main(void)
{
  char	*str;
  clock_t debut;

  if ((get_cmd("start_simulation\n")) == 84)
    {
      my_error("[Error] Can't start !\n");
      return (84);
    }
  while (42)
    {
      dprintf(2, "\n\n**** [Info] **** \n");
      my_putstr("get_info_lidar\n");
      if ((str = get_next_line(0)) == NULL)
	break;
      if ((check_lap(str)) == 84)
	return (84);
      if ((get_speed()) == 84)
	return (84);
      if ((get_wheels()) == 84)
	return (84);
      debut = clock();
      dprintf(2, "-Time : %.2f-\n", (double) debut/CLOCKS_PER_SEC);
      ai_car();
    }
  get_cmd("stop_simulation\n");
  return (0);
}
