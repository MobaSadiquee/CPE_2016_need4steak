/*
** ai.c for ai in /home/sadiqu-m/delivery/C_prog_elem/CPE_rush4stek_2016/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Sun Jun  4 16:44:45 2017 Sadiqu-m
** Last update Sun Jun  4 23:02:24 2017 Sadiqu-m
*/

#include "my.h"

int	ai_car()
{
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    get_cmd("car_forward:0.5\n");
  else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    get_cmd("car_forward:0.0\n");
  else if (sfKeyboard_isKeyPressed(sfKeyR) == sfTrue)
    get_cmd("car_backwards:0.5\n");
  else if (sfKeyboard_isKeyPressed(sfKeyT) == sfTrue)
    get_cmd("car_forward:1.0\n");
  else if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    {
      get_cmd("wheels_dir:0.4\n");
      get_cmd("Cycle_wait:1\n");
      get_cmd("wheels_dir:0.0\n");
    }
  else if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    {
      get_cmd("wheels_dir:-0.4\n");
      get_cmd("Cycle_wait:1\n");
      get_cmd("wheels_dir:0.0\n");
    }
  else if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    get_cmd("stop_simulation\n");
  return (0);
}

int	get_speed()
{
  char	*str;
  float	nb;
  char	**tab;

  write(1, "GET_CURRENT_SPEED\n", 18);
  if ((str = get_next_line(0)) == NULL)
    {
      my_error("[Error] Can't get info\n");
      return (84);
    }
  tab = my_str_to_wordtab(str, ':');
  nb = atoi(tab[3]) * 2;
  dprintf(2, "[Info] Current Speed : ");
  dprintf(2, "(0.%.0f)\n", nb);
  free(tab);
  free(str);
  return (0);
}

int	get_wheels()
{
  char	*str;
  float	nb;
  char	**tab;

  write(1, "GET_CURRENT_WHEELS\n", 19);
  if ((str = get_next_line(0)) == NULL)
    {
      my_error("[Error] Can't get info\n");
      return (84);
    }
  tab = my_str_to_wordtab(str, ':');
  nb = atoi(tab[3]) * 2;
  dprintf(2, "[Info] Current Wheels : ");
  dprintf(2, "(%.1f)\n", nb);
  free(tab);
  free(str);
  return (0);
}

