/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/sadiqu-m/delivery/C_prog_elem/CPE_rush4stek_2016/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Sat Jun  3 17:39:13 2017 Sadiqu-m
** Last update Sun Jun  4 13:07:19 2017 Sadiqu-m
*/

#include "my.h"

int	my_nb_word(char *str, int i, char separator)
{
  int	nb;

  nb = 1;
  while (str[i] != '\0')
    {
      if (str[i] == separator && str[i - 1] != separator)
	nb++;
      i++;
    }
  return (nb);
}

int	my_word_len(char *str, char separator, int i)
{
  int	nb;

  nb = 0;
  while (str[i] != '\0' && str[i] != separator)
    {
      nb++;
      i++;
    }
  return (nb);
}

int	check_nb(char separator, char *str, int i)
{
  while (str[i] != '\0' && str[i] != separator)
    i++;
  while (str[i] == separator && str[i] != '\0')
    i++;
  return (i);
}

char	*new_cel(char *str, int i, char separator, char *cel)
{
  int	k;

  k = 0;
  cel = malloc(sizeof(char) * my_word_len(str, separator, i) + 1);
  if (cel == NULL)
    my_error("Malloc Failed\n");
  while (str[i] != '\0' && str[i] != separator)
    {
      cel[k] = str[i];
      k++;
      i++;
    }
  cel[k] = '\0';
  return (cel);
}

char	**my_str_to_wordtab(char *str, char separator)
{
  char	**tab;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] == separator && str[i] != '\0')
    i++;
  tab = malloc(sizeof(char *) * (my_nb_word(str, i, separator) + 1));
  if (tab == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      tab[j] = new_cel(str, i, separator, tab[j]);
      j++;
      i = check_nb(separator, str, i);
    }
  tab[j] = NULL;
  return (tab);
}

