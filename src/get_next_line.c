/*
** get_next_line.c for get_next_line in /home/sadiqu-m/delivery/Systeme_unix/PSU_2016_navy/src
**
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
**
** Started on  Mon Jan 30 16:03:15 2017 Sadiqu-m
** Last update Sun Jun  4 13:07:52 2017 Sadiqu-m
*/

#include "my.h"

char	*my_realloc(char *str)
{
  char	*new_str;
  int	i;

  i = 0;
  if ((new_str = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}

char	get_fd(const int fd)
{
  static char	buffer[READ_SIZE];
  static char	*str = NULL;
  char		word;
  static int	readed = 0;

  if (readed == 0)
    {
      if ((readed = read(fd, buffer, READ_SIZE)) < 0)
	return (84);
      str = buffer;
      if (readed < 1)
	return (0);
    }
  word = *str;
  str++;
  readed--;
  return (word);
}

char	*get_next_line(const int fd)
{
  char	word;
  char	*str;
  int	i;
  static int	option = 0;

  i = 0;
  if ((str = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (NULL);
  if ((word = get_fd(fd)) == 84)
    return (NULL);
  while (word != '\n' && word != '\0')
    {
      option++;
      str[i] = word;
      if ((word = get_fd(fd)) == 84)
	return (NULL);
      i++;
      if (i % (READ_SIZE + 1) == 0)
	if ((str = my_realloc(str)) == NULL)
	  return (NULL);
    }
  str[i] = '\0';
  if (str[0] == 0)
    return (NULL);
  return (str);
}
