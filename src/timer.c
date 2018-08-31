/*
** timer.c for timer in /home/sadiqu-m/delivery/C_prog_elem/CPE_rush4stek_2016/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Sun Jun  4 16:46:08 2017 Sadiqu-m
** Last update Sun Jun  4 16:46:32 2017 Sadiqu-m
*/

#include "my.h"

int	timer()
{
  time_t	start;
  time_t	now;

  start = time(NULL);
  initscr();
  keypad(stdscr, TRUE);
  cbreak();
  while (start != 0)
    {
      now = time(NULL) - start;
      mvprintw(15, 18,"%02d:%02d", now / 60 , now % 60);
      refresh();
    }
  endwin();
  return (0);
}
