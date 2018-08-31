/*
** get_cmd.c for get_cmd in /home/sadiqu-m/delivery/C_prog_elem/N4S/src
**
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
**
** Started on  Mon May 22 15:53:40 2017 Sadiqu-m
** Last update Fri Jun  2 23:55:24 2017 Sadiqu-m
*/

#include "my.h"

int	get_cmd(char *str)
{
  my_putstr(str);
  if ((str = get_next_line(0)) == NULL)
    return (84);
  return (0);
}
