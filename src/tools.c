/*
** tools.c for rush in /home/elayou_y/Rush/CPE_rush4stek_2016/src
** 
** Made by Youness El Ayouch
** Login   <elayou_y@epitech.net>
** 
** Started on  Sat Jun  3 17:07:10 2017 Youness El Ayouch
** Last update Sun Jun  4 19:10:06 2017 Sadiqu-m
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
      ++i;
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      ++i;
    }
}

int	my_error(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((write(2, &str[i], 1)) < 0)
	return (84);
      i++;
    }
  return (84);
}
