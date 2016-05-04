/*
** final.c for get_next_line in /home/gassem_a/CPE_2015_getnextline
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Sat Jan 16 18:12:27 2016 aurelien gassemann
** Last update Sun Jan 17 18:37:15 2016 aurelien gassemann
*/

#include <stdlib.h>
#include "get_next_line.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i = i + 1;
  return (i);
}

int	fill_buff_with_lines(char *string, char *buff)
{
  t_var	var;

  var.i = my_strlen(string);
  var.j = 0;
  while (buff[var.j] != '\0')
    {
      string[var.i] = 0;
      if (buff[var.j] == '\n')
	{
	  var.j = var.j + 1;
	  return (1);
	}
      string[var.i] = buff[var.j];
      var.i = var.i + 1;
      var.j = var.j + 1;
    }
  string[var.i] = 0;
  return (0);
}

char		*get_next_line(const int fd)
{
  t_var		var;
  char		*buff;
  char		*string;

  if ((string = malloc(sizeof(char) * SIZE_OF_LINE)) == NULL)
    return (NULL);
  if ((buff = malloc(sizeof(char *) * SIZE_OF_LINE)) == NULL)
    return (NULL);
  string[0] = 0;
  while ((var.length = read(fd, buff, READ_SIZE)) && var.length > 0)
    {
      if (fill_buff_with_lines(string, buff) == 1)
	return (string);
    }
  if (read(fd, buff, READ_SIZE) == -1)
    return (NULL);
  free (string);
  free (buff);
  return (0);
}
