/*
** my.h for my.h in /home/sadiqu-m/delivery/C_prog_elem/CPE_rush4stek_2016/include
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Sat Jun  3 15:47:50 2017 Sadiqu-m
** Last update Mon Jun  5 14:29:17 2017 Sadiqu-m
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <string.h>
#include <time.h>

char    *my_realloc(char *str);
char    get_fd(const int fd);
char    *get_next_line(const int fd);

int     get_cmd(char *str);
void    my_putstr(char *str);
int	my_strlen(char *str);
void	my_putchar(char c);
int     my_nb_word(char *str, int i, char separator);
int     my_error(char *str);
int	ai_car();
int     get_wheels();
int     get_speed();

int     my_word_len(char *str, char separator, int i);
int     check_nb(char separator, char *str, int i);
char    *new_cel(char *str, int i, char separator, char *cel);
char    **my_str_to_wordtab(char *str, char separator);

#ifndef READ_SIZE
# define READ_SIZE 1024

#endif /* !READ_SIZE */
#endif /* MY_H_ */
