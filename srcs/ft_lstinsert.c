/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstinsert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:52:41 by gduval            #+#    #+#             */
/*   Updated: 2016/11/30 12:52:43 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h> //daw

int       browsecase(char *buf, t_list *tetriminos)
{
  size_t  height;
  size_t  tmp_height;
  size_t  width;

  ft_putstr("browsecase() opened\n");
  if (!tetriminos || !buf)
    return (-1);
  height = 0;
  width = 0;
  tmp_height = 0;
  while (width != 4)
  {
    while (height < 12)
    {
      height = (tmp_height * 4) + width;
      tmp_height++;
    }
    height = 0;
    tmp_height = 0;
    width++;
  }
  return (0);
}

size_t     browsebuf(char *buf, t_list *tetriminos, size_t len)
{
  size_t  i;

  ft_putstr("browsebuf() opened\n");
  i = 0;
  while (i < len)
  {
    browsecase(buf, tetriminos);
    i++;
  }
  return (0);
}

size_t     lstinsert(char *buf, t_list *tetriminos, size_t len)
{
  ft_putstr("lstinsert() opened\n"); //dwa
  browsebuf(buf, tetriminos, len);
  return (0);
}
